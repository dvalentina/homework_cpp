#pragma once

#include "world.h"

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

class MessageBox
{
public:
    MessageBox(
        const sf::Vector2i& position, const sf::Vector2i& sizes,
        const int char_size
    );
    virtual ~MessageBox() = default;

    void Create(
        const sf::Vector2i& position, const sf::Vector2i& sizes,
        const int char_size
    );
    void Add(const std::string& message);
    //void Clear();

    void Update(const float dt);
    void Render(sf::RenderWindow& window);


private:
    // сообщения, которые видны пользователю в данный момент
    std::vector<std::string> messages_;

    sf::RectangleShape background_;
    sf::Font font_;
    sf::Text all_messages_;
};
