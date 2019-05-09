#include "world.h"

extern const float BLOCK_SIZE;
extern const sf::Vector2i WORLD_SIZES;

void World::Update(const float dt)
{
    snake_.Update(dt);
    apple_.Update(dt);
    for (Wall& wall : walls_)
    {
        wall.Update(dt);
    }
    HandleCollisions();
}

void World::Create()
{
    Wall right_wall;
    right_wall.Create({ WORLD_SIZES.x - 1, 0 }, { WORLD_SIZES.x, WORLD_SIZES.y });
    walls_.push_back(std::move(right_wall));

    Wall left_wall;
    left_wall.Create({ 0, 0 }, { 1, WORLD_SIZES.y });
    walls_.push_back(std::move(left_wall));

    // инициализаци€ ещЄ 3х стен

    

    Wall upper_wall;
    upper_wall.Create({ 0, 0 }, { WORLD_SIZES.x, 1 }); 
    walls_.push_back(std::move(upper_wall));

    Wall bottom_wall;
    bottom_wall.Create({ 0, WORLD_SIZES.y - 1 }, { WORLD_SIZES.x, WORLD_SIZES.y });
    walls_.push_back(std::move(bottom_wall));

    // конец

    apple_.Create(FindRandomFreeCell());
    snake_.Create(FindRandomFreeCell());
}

void World::Render(sf::RenderWindow& window)
{
    //шаматна€ доска

    for (int i = 0; i < WORLD_SIZES.y; ++i)
    {

    }

    snake_.Render(window);
    apple_.Render(window);
    for (Wall& wall : walls_)
    {
        wall.Render(window);
    }
}

void World::HandleCollisions()
{
    // проверить, совпадают ли позиции головы  змеи и €блока
    // если совпадают, то вызвать snake_.Grow() и сместить €блоко на 1 клетку вправо и 1 клеточку вниз (дл€ теста)
    // вызвать apple_.Create(new_position)
    // shape_.ssetPosition(1*BLOCK_SIZE,5*BLOCK_SIZE) в острисовке

    if (snake_.CheckSelfCollision())
    {
        // уменьшить жизни на 1
        // вызвать snake.create
        snake_.DecreaseLives();
        snake_.Create(FindRandomFreeCell());
    }

    for (const Wall& wall : walls_)
    {
        // уменьшить жизни на 1
        // вызвать snake.create
        if (wall.CheckCellInWall(snake_.GetHeadPosition()))
        {
            snake_.DecreaseLives();
            snake_.Create(FindRandomFreeCell());
            break;
        }
        
    }

    if (snake_.GetHeadPosition() == apple_.GetPosition())
    {
        snake_.Grow();
        snake_.IncreaseScore();
        apple_.Create(FindRandomFreeCell());
    }

    if (snake_.GetLives() == 0)
    {
        //
    }
}

sf::Vector2i World::FindRandomFreeCell() const
{
    while (true)
    {
        bool is_random_cell_collided = false;
        const sf::Vector2i random_cell_position(
            std::rand() % WORLD_SIZES.x,
            std::rand() % WORLD_SIZES.y
        );

        // Check possible collisions with walls
        for (const Wall& wall : walls_)
        {
            if (wall.CheckCellInWall(random_cell_position))
            {
                is_random_cell_collided = true;
                break;
            }
        }

        // Check possible collisions with snake
        if (!is_random_cell_collided)
        {
            const auto& snake_body = snake_.GetBody();
            for (const auto& snake_segment : snake_body)
            {
                if (snake_segment.position == random_cell_position)
                {
                    is_random_cell_collided = true;
                    break;
                }
            }
        }

        // Check possible collision with apple
        if (!is_random_cell_collided)
        {
            if (apple_.GetPosition() == random_cell_position)
            {
                is_random_cell_collided = true;
            }
        }

        if (!is_random_cell_collided)
        {
            return random_cell_position;
        }
    }
}

