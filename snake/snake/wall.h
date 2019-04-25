#pragma once

#include <SFML/Graphics.hpp>

class Wall
{
public:
    Wall() = default;
    virtual ~Wall() = default;

    void Update(const float dt);
    void Render(sf::RenderWindow& window);

};