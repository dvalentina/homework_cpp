#include "game.h"

extern const sf::Vector2u WINDOW_SIZES(800, 600);
extern const sf::Vector2i WORLD_SIZES(40, 25);
extern const float BLOCK_SIZE = 18.0f; // только для отрисовки

Game::Game()
    : main_window_("Snake", WINDOW_SIZES)
{
    sf::Vector2i apple_position(3, 4);
    sf::Vector2i snake_position(4, 4);
    world_.Create(apple_position, snake_position);
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && 
        world_.snake_.GetDirection() != Snake::Direction::Down)
    {
        world_.snake_.SetDirection(Snake::Direction::Up);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
        world_.snake_.GetDirection() != Snake::Direction::Up)
    {
        world_.snake_.SetDirection(Snake::Direction::Down);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
        world_.snake_.GetDirection() != Snake::Direction::Right)
    {
        world_.snake_.SetDirection(Snake::Direction::Left);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
        world_.snake_.GetDirection() != Snake::Direction::Left)
    {
        world_.snake_.SetDirection(Snake::Direction::Right);
    }    
}

void Game::Update(const float dt)
{
    main_window_.Update(dt);

    world_.Update(dt);
}



void Game::Render()
{
    main_window_.BeginDraw();

    // draw other objects here
    main_window_.Draw(world_);

    main_window_.EndDraw();
}