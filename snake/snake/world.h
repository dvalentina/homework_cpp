#pragma once

#include <vector>

#include "window.h"
#include "apple.h"
#include "wall.h"
#include "snake.h"

class World
{
    friend class Game;

public:
    World() = default;
    virtual ~World() = default;

    void Create(sf::Vector2i apple_position, sf::Vector2i snake_position);
    void Update(const float dt);
    void Render(sf::RenderWindow& window);
private:
    void HandleCollisions();
    //sf::Vector2i FindRandowFreeCell() const;

    Snake snake_;
    Apple apple_;
    std::vector<Wall> walls_;
};