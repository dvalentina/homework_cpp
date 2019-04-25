#pragma once
#include <SFML/Graphics.hpp>

class Apple
{
public:
    Apple() = default;
    virtual ~Apple() = default;
    
    void Create(const sf::Vector2i& new_position);

    sf::Vector2i GetPosition() const;

    void Update(const float dt); // у него пустое тело
    void Render(sf::RenderWindow& window); // отрисовать shape_
private:
    sf::Vector2i position_;
    sf::CircleShape shape_;
};