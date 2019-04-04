#include "Game.h"

Game::Game()
    : main_window_("Forest", sf::Vector2u(600, 600)),
      forest_(5, 5)
{
    const float tree_height = main_window_.GetWindowSize().y / forest_.GetForest().GetHeight();
    const float tree_width = main_window_.GetWindowSize().x / forest_.GetForest().GetWidth();
    tree_.setSize(sf::Vector2f(tree_height, tree_width));


    normal_tree_texture_.loadFromFile("../data/normal_tree_texture.jpg");

    tree_in_fire_texture_.loadFromFile("../data/tree_in_fire_texture.jpg");

    burnt_tree_texture_.loadFromFile("../data/burnt_tree_texture.jpg");

    tree_.setTexture(&normal_tree_texture_);
}

void Game::Run()
{
    while (!main_window_.CheckIsDone())
    {
        Update();
        Render();
    }
}

void Game::Update()
{
    main_window_.Update();

    forest_.Update();

    sf::sleep(sf::seconds(1.0f));
}

void Game::Render()
{
    main_window_.BeginDraw();
    float tree_height = tree_.getSize().y;
    float tree_width = tree_.getSize().x;
    for (size_t i = 0; i < forest_.GetForest().GetHeight(); ++i)
    {
        for (size_t j = 0; j < forest_.GetForest().GetWidth(); ++j)
        {
            tree_.setPosition(sf::Vector2f(j * tree_width, i * tree_height));
            if (forest_.GetForest().GetState(i, j) == NORMAL_TREE)
            {
                tree_.setTexture(&normal_tree_texture_);
            }
            else if (forest_.GetForest().GetState(i, j) == TREE_IN_FIRE)
            {
                tree_.setTexture(&tree_in_fire_texture_);
            }
            else if (forest_.GetForest().GetState(i, j) == BURNT_TREE)
            {
                tree_.setTexture(&burnt_tree_texture_);
            }
            main_window_.Draw(tree_);

        }
    }
    main_window_.EndDraw();
}
