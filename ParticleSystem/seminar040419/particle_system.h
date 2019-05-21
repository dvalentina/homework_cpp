// теперь с кодировкой всё хорошо

#include <SFML/Graphics.hpp>
#include <vector>

#pragma once

class Particle
{
    friend class ParticleSystem;

public:
    Particle(const sf::Vector2f position, const sf::Vector2f velocity, const sf::Vector2f acceleration, const float radius, const float mass);
    virtual ~Particle() = default;

    void Push(const sf::Vector2f force, const float dt);

    sf::Vector2f GetPosition() const;
    void Particle::SetPosition(sf::Vector2f& position);
    float GetRadius() const;
    void Particle::SetVelocity(const sf::Vector2f& velocity);
    sf::Vector2f GetVelocity() const;
    sf::Vector2f Particle::GetAcceleration() const;

    void Update(const float dt);
    void Render(sf::RenderWindow& window);

private:
    //physics
    sf::Vector2f position_;
    sf::Vector2f velocity_;
    sf::Vector2f acceleration_;
    float radius_;
    float mass_;

    //graphics
    sf::CircleShape shape_;
};

class ParticleSystem
{
public:
    ParticleSystem() = default;
    virtual ~ParticleSystem() = default;

    using ParticleID = size_t;

    ParticleID AddParticle(
        const sf::Vector2f position, const sf::Vector2f velocity, const sf::Vector2f acceleration, 
        const float radius, const float mass
    );
    //void RemoveParticle(ParticleID particle_id);

    void Push(const sf::Vector2f force, const float dt);
    void AddLink(
        const ParticleID particle1_id, const ParticleID particle2_id, 
        const float stiffness
    );

    float ComputeDistanceBetween(const ParticleID particle1_id, const ParticleID particle2_id) const;

    const Particle& GetParticleByID(const ParticleID particle_id) const;

    //void HandleCollisions(const float dt);

    void Update(const float dt);
    void Render(sf::RenderWindow& window);

private:
    void ApplyGravity();
    void HandleCollisions();
    void SolveLinks();

    struct Link
    {
        ParticleID particle1_id;
        ParticleID particle2_id;
        float initial_length;
        float stiffness;
    };

    std::vector<Particle> particles_;
    std::vector<Link> links_;
};