#pragma once

#include "window.h"
#include "world.h"

class Game
{
public:
    Game();
    virtual ~Game() = default;

    void Run();
    void HandleInput(const float dt);
    void Update(const float dt);
    void Render();


private:
    Window main_window_;

    //sf::Vector2f increment_;

    World world_;
};

