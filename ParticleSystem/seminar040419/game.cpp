#include "game.h"

extern const sf::Vector2u WINDOW_SIZES(800, 600);


Game::Game()
    : main_window_("Particle", WINDOW_SIZES)
{
    /*const ParticleSystem::ParticleID particle1_id = particles_.AddParticle(sf::Vector2f(3 * WINDOW_SIZES.x / 4, WINDOW_SIZES.y / 4), 
                                                      sf::Vector2f(10.0f, 10.0f), sf::Vector2f(0.0f, 0.0f), 15.0f, 10.0f);
    const auto particle2_id = particles_.AddParticle(sf::Vector2f(3 * WINDOW_SIZES.x / 4, 3 * WINDOW_SIZES.y / 4), 
                                                       sf::Vector2f(-10.0f, -10.0f), sf::Vector2f(0.0f, 0.0f), 23.0f, 30.0f);
    particles_.AddLink(
        particle1_id, particle2_id,
        100.0f //stiffness
    );*/

    ParticleSystem::ParticleID particle1_id = particles_.AddParticle(
        sf::Vector2f(100.0f, 100.0f), // position 
        sf::Vector2f(0, 0), // velocity 
        sf::Vector2f(0, 0), // acceleration 
        25.0f, // radius 
        15000.0f // mass 
    );

    ParticleSystem::ParticleID particle2_id = particles_.AddParticle(
        sf::Vector2f(100.0f, 400.0f), // position 
        sf::Vector2f(0, 0), // velocity 
        sf::Vector2f(0, 0), // acceleration 
        25.0f, // radius 
        15000.0f // mass 
    );

    ParticleSystem::ParticleID particle3_id = particles_.AddParticle(
        sf::Vector2f(400.0f, 100.0f), // position 
        sf::Vector2f(0, 0), // velocity 
        sf::Vector2f(0, 0), // acceleration 
        25.0f, // radius 
        15000.0f // mass 
    );

    ParticleSystem::ParticleID particle4_id = particles_.AddParticle(
        sf::Vector2f(400.0f, 400.0f), // position 
        sf::Vector2f(0, 0), // velocity 
        sf::Vector2f(0, 0), // acceleration 
        25.0f, // radius 
        15000.0f // mass 
    );

    particles_.AddLink(
        particle1_id, particle2_id,
        1e5 // stiffness 
    );

    particles_.AddLink(
        particle2_id, particle3_id,
        1e5 // stiffness 
    );

    particles_.AddLink(
        particle3_id, particle4_id,
        1e5 // stiffness 
    );

    particles_.AddLink(
        particle4_id, particle1_id,
        1e5 // stiffness 
    );

    particles_.AddLink(
        particle1_id, particle3_id,
        1e5 // stiffness 
    );

    particles_.AddLink(
        particle4_id, particle2_id,
        1e5 // stiffness 
    );
}



void Game::Run()
{
    const float updates_per_seconds = 60.0f;
    const sf::Time time_per_update = sf::seconds(1.0f / updates_per_seconds);

    sf::Clock clock;
    sf::Time time_sinse_last_update = sf::Time::Zero;
    while (!main_window_.CheckIsDone())
    {
        time_sinse_last_update += clock.restart();        
        while (time_sinse_last_update >= time_per_update)
        {
            //чтобы приложение было более отзывчивым, ставим handleinput именно сюда
            HandleInput(time_per_update.asSeconds());
            Update(time_per_update.asSeconds());
            
            time_sinse_last_update -= time_per_update;
        }

        Render();
    }
}

void Game::HandleInput(const float dt)
{
    sf::Vector2f force(0.0f, 0.0f);
    const float force_modulus = 500000.0f;

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up))&&(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
    {
        force.y -= force_modulus / 1.4;
        force.x -= force_modulus / 1.4;
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up))&&(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
    {
        force.y -= force_modulus / 1.4;
        force.x += force_modulus / 1.4;
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down))&&(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
    {
        force.y += force_modulus / 1.4;
        force.x -= force_modulus / 1.4;
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
    {
        force.y += force_modulus / 1.4;
        force.x += force_modulus / 1.4;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        force.y -= force_modulus;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        force.y += force_modulus;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        force.x -= force_modulus;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        force.x += force_modulus;
    }

    particles_.Push(force, dt);
    
}

void Game::Update(const float dt)
{
    main_window_.Update(dt);

    particles_.Update(dt);
}



void Game::Render()
{
    main_window_.BeginDraw();

    // draw other objects here
    main_window_.Draw(particles_);

    main_window_.EndDraw();
}