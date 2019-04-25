#pragma once

#include <SFML/Graphics.hpp>


class Snake
{
public:
    struct Segment
    {
        sf::Vector2i position;
        sf::RectangleShape shape;
        sf::Color color;
    };

    enum Direction
    {
        Up,
        Right,
        Down,
        Left,
        None
    };

public:
    Snake() = default;
    virtual ~Snake() = default;

    void Create(const sf::Vector2i& head_position);
    
    //bool CheckSelfCollision() const;
    void Grow();
    
    // реализовать эти шесть методов
    Direction GetDirection() const;
    void SetDirection(const Direction new_direction);
    int GetScore() const;
    void IncreaseScore();
    int GetLives() const;
    void DecreaseLives();

    sf::Vector2i GetHeadPosition() const;
    const std::vector<Segment>& GetBody() const;

    void Update(const float dt);
    void Render(sf::RenderWindow& window) const;

private:
    void MoveByOneCell();
    

    std::vector<Segment> body_;
    Direction direction_;

    int lives_;
    int score_;
};