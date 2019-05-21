#include "particle_system.h"
#include "utils.h"

extern const sf::Vector2u WINDOW_SIZES;

Particle::Particle(const sf::Vector2f position, const sf::Vector2f velocity, const sf::Vector2f acceleration, const float radius, const float mass)
    : position_(position)
    , velocity_(velocity)
    , acceleration_(acceleration)
    , radius_(radius)
    , mass_(mass)
{
    shape_.setRadius(radius);
    shape_.setFillColor(sf::Color::Yellow);
    shape_.setPosition(position);
    shape_.setOrigin(sf::Vector2f(radius, radius));
}

void Particle::Update(const float dt)
{
    velocity_ += acceleration_ * dt;
    position_ += velocity_ * dt;
}

sf::Vector2f Particle::GetPosition() const
{
    return position_;
}

void Particle::SetPosition(sf::Vector2f& position)
{
    position_ = position;
}

float Particle::GetRadius() const
{
    return radius_;
}

void Particle::SetVelocity(const sf::Vector2f& velocity)
{
    velocity_ = velocity;
}

sf::Vector2f Particle::GetVelocity() const
{
    return velocity_;
}

sf::Vector2f Particle::GetAcceleration() const
{
    return acceleration_;
}

void Particle::Render(sf::RenderWindow& window)
{
    shape_.setPosition(position_);
    shape_.setRadius(radius_);

    window.draw(shape_);
}

void Particle::Push(const sf::Vector2f force, const float dt)
{
    velocity_ = (force * dt) / mass_ + velocity_;
}

//particle system

ParticleSystem::ParticleID ParticleSystem::AddParticle(
    const sf::Vector2f position, const sf::Vector2f velocity, const sf::Vector2f acceleration, 
    const float radius, const float mass)
{
    Particle new_particle(position, velocity, acceleration, radius, mass);
    particles_.push_back(new_particle);
    return particles_.size() - 1;
}

void ParticleSystem::Push(const sf::Vector2f force, const float dt)
{
    for (Particle& particle : particles_)
    {
        particle.Push(force, dt);
    }
}

void ParticleSystem::AddLink(
    const ParticleID particle1_id, const ParticleID particle2_id, 
    const float stiffness)
{
    links_.push_back(Link{
        particle1_id, particle2_id,
        ComputeDistanceBetween(particle1_id, particle2_id),
        stiffness 
    });
}

float ParticleSystem::ComputeDistanceBetween(const ParticleID particle1_id, const ParticleID particle2_id) const
{
    const Particle& particle1 = GetParticleByID(particle1_id);
    const Particle& particle2 = GetParticleByID(particle2_id);

    const sf::Vector2f distanse_vector12 = (
        particle2.position_ - particle1.position_
        );

    return utils::ComputeLength(distanse_vector12);
}

const Particle& ParticleSystem::GetParticleByID(const ParticleID particle_id) const
{
    return particles_[particle_id];
}

void ParticleSystem::Update(const float dt)
{
    for (Particle& particle : particles_)
    {
        particle.acceleration_ = sf::Vector2f(0.0f, 0.0f);
    }

    SolveLinks();
    ApplyGravity();

    for (Particle& particle : particles_)
    {
        particle.Update(dt);
    }
    
    HandleCollisions();
}

void ParticleSystem::Render(sf::RenderWindow& window)
{
    for (Link& link : links_)
    {
        const Particle& particle1 = GetParticleByID(link.particle1_id);
        const Particle& particle2 = GetParticleByID(link.particle2_id);

        const float length = utils::ComputeLength(particle1.GetPosition() - particle2.GetPosition());
        const float width = sqrt(pow(WINDOW_SIZES.x, 2) + pow(WINDOW_SIZES.y, 2)) / length;

        sf::RectangleShape line(sf::Vector2f(length, width));
        line.setPosition(particle1.GetPosition());
        line.setOrigin(0, width / 2);

        const float y = particle2.GetPosition().y - particle1.GetPosition().y;
        const float x = particle2.GetPosition().x - particle1.GetPosition().x;
        line.rotate(180 * atan2(y, x) / 3.14);
        
        const float delta = fabs(length - link.initial_length);
        const float allowed_delta = 100.0f;
        int red = 0;
        if (delta >= allowed_delta)
        {
            red = 255;
        }
        else
        {
            red = (255 / allowed_delta) * delta;
        }
        line.setFillColor(sf::Color(red, 50, 50));
        window.draw(line);

    }

    for (Particle& particle : particles_)
    {
        particle.Render(window);
    }
}

void ParticleSystem::ApplyGravity()
{
    const sf::Vector2f acceleration_g(0.0f, 500.0f);
    for (Particle& particle : particles_)
    {
        particle.acceleration_ += acceleration_g;
    }
}

void ParticleSystem::HandleCollisions()
{
    for (Particle& particle : particles_)
    {
        if (particle.position_.x < particle.radius_)
        {
            particle.position_.x = particle.radius_;
            particle.velocity_.x = -particle.velocity_.x / 2.0f;
        }
        if (particle.position_.x > WINDOW_SIZES.x - particle.radius_)
        {
            particle.position_.x = WINDOW_SIZES.x - particle.radius_;
            particle.velocity_.x = -particle.velocity_.x / 2.0f;
        }

        if (particle.position_.y < particle.radius_)
        {
            particle.position_.y = particle.radius_;
            particle.velocity_.y = -particle.velocity_.y / 2.0f;
        }
        const float bottom_gap = 50.0f;
        if (particle.position_.y > WINDOW_SIZES.y - particle.radius_ - bottom_gap)
        {
            particle.position_.y = WINDOW_SIZES.y - particle.radius_ - bottom_gap;
            particle.velocity_.y = -particle.velocity_.y / 2.0f;
        }
    }
}

void ParticleSystem::SolveLinks()
{
    for (Link& link : links_)
    {
        Particle& particle1 = particles_[link.particle1_id];
        Particle& particle2 = particles_[link.particle2_id];

        const sf::Vector2f distance_vector12 = (
            particle2.position_ - particle1.position_
            );
        const float distance = utils::ComputeLength(distance_vector12);
       
        const float delta = distance - link.initial_length;
        const float force = link.stiffness * delta;
        const sf::Vector2f unit_vector12 = distance_vector12 / distance;
        particle1.acceleration_ += (force * unit_vector12) / particle1.mass_;
        particle2.acceleration_ -= (force * unit_vector12) / particle2.mass_;
    }
}