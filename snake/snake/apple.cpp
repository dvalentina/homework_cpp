#include "apple.h"

extern const float BLOCK_SIZE;
extern const sf::Vector2i WORLD_SIZES;

void Apple::Create(const sf::Vector2i& new_position)
{
    position_ = new_position;
    // ����� ������������������� shape_
    shape_.setRadius(BLOCK_SIZE / 2);
}

sf::Vector2i Apple::GetPosition() const
{
    return position_;
}

void Apple::Update(const float dt) // � ���� ������ ����
{
}

void Apple::Render(sf::RenderWindow& window) // ���������� shape_
{
    // ������������ shape_ � ����������� �� position_
    // ����������� ������� ������
    sf::CircleShape apple = shape_;
    apple.setPosition(sf::Vector2f(position_.x * WORLD_SIZES.x, position_.y * WORLD_SIZES.y));
    apple.setFillColor(sf::Color::Red);
    window.draw(apple);
}
