#pragma once
#include "window.h"
#include "forest.h"

class Game
{
public:
    Game();
    virtual ~Game() = default;

    void Run();
    void Update();
    void Render();

private:
    Window main_window_;

    sf::RectangleShape tree_;
    sf::Texture normal_tree_texture_;
    sf::Texture tree_in_fire_texture_;
    sf::Texture burnt_tree_texture_;

    Forest forest_;
};