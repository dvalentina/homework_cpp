#include "world.h"


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

void World::Create(sf::Vector2i apple_position, sf::Vector2i snake_position)
{
    apple_.Create(sf::Vector2i(3, 4));
    snake_.Create(sf::Vector2i(4, 4));
}

void World::Render(sf::RenderWindow& window)
{
    snake_.Render(window);
    apple_.Render(window);
    for (Wall& wall : walls_)
    {
        wall.Render(window);
    }
}

void World::HandleCollisions()
{
    // проверить, совпадают ли позиции головы  змеи и яблока
    // если совпадают, то вызвать snake_.Grow() и сместить яблоко на 1 клетку вправо и 1 клеточку вниз (для теста)
    // вызвать apple_.Create(new_position)
    // shape_.ssetPosition(1*BLOCK_SIZE,5*BLOCK_SIZE) в острисовке

    if (snake_.GetHeadPosition() == apple_.GetPosition())
    {
        snake_.Grow();
        sf::Vector2f apple_position_delta(1, 1);
        apple_.Create(sf::Vector2i(apple_.GetPosition().x + apple_position_delta.x, apple_.GetPosition().y + apple_position_delta.y));
    }
}

/*sf::Vector2i World::FindRandowFreeCell() const
{
    // пока оставить пустым
    // вызывает apple_.GetPosition(), snake_.GetBody()
    // формирует рандомную клетку, которая не лежит в теле змеи и не лежит в яблоке

    // проверяем, что полученная клетка не принадлежит ни одной из стен
    // если принадлежит, то перегенерируем клетку, пока не найдём подходящую
}*/