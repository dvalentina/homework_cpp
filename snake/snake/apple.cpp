#include "apple.h"

extern const float BLOCK_SIZE;
extern const sf::Vector2i WORLD_SIZES;

void Apple::Create(const sf::Vector2i& new_position)
{
    position_ = new_position;
    // можно проинициализировать shape_
    shape_.setRadius(BLOCK_SIZE / 2);
}

sf::Vector2i Apple::GetPosition() const
{
    return position_;
}

void Apple::Update(const float dt) // у него пустое тело
{
}

void Apple::Render(sf::RenderWindow& window) // отрисовать shape_
{
    // отрисовываем shape_ в зависимости от position_
    // отрисвываем красным цветом
    sf::CircleShape apple = shape_;
    apple.setPosition(sf::Vector2f(position_.x * BLOCK_SIZE, position_.y * BLOCK_SIZE));
    apple.setFillColor(sf::Color::Red);
    window.draw(apple);
}
