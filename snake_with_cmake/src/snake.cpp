#include "snake.h"
#include <cassert>
#include <iterator>

extern const float BLOCK_SIZE;
extern const sf::Vector2i WORLD_SIZES;

void Snake::Create(const sf::Vector2i& head_position)
{
    direction_ = None;
    body_.clear();
    Segment head = {
        head_position,
        sf::RectangleShape(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE)),
        sf::Color::Yellow
    };

    body_.push_back(std::move(head));
}

// реализовать следующие шесть методов

Snake::Direction Snake::GetDirection() const
{
    return direction_;
}

void Snake::SetDirection(const Direction new_direction)
{
    direction_ = new_direction;
}

int Snake::GetScore() const
{
    return score_;
}

void Snake::SetScore(const int new_score)
{
    score_ = new_score;
}

void Snake::IncreaseScore()
{
    score_ += 1;
}

int Snake::GetLives() const
{
    return lives_;
}

void Snake::SetLives(const int new_lives)
{
    lives_ = new_lives;
}

void Snake::DecreaseLives()
{
    if (lives_ > 0)
    {
        lives_ -= 1;
    }
}

bool Snake::CheckSelfCollision() const
{
    //for
    //цикл по body_ (начиная не с первого элемента), проверка на равенство координат с head_
    for (size_t i = 1; i < body_.size(); ++i)
    {
        if (body_[i].position == body_[0].position)
        {
            return true;
        }
    }
    return false;
}

sf::Vector2i Snake::GetHeadPosition() const
{
    assert(!body_.empty());
    return body_[0].position;
}

const std::vector<Snake::Segment>& Snake::GetBody() const
{
    return body_;
}

void Snake::Update(const float dt)
{
    MoveByOneCell();
}

void Snake::Render(sf::RenderWindow& window) const
{
    // цикл по body_ 
    // отрисовка всех сегментов из body_
    for (size_t i = 0; i < body_.size(); ++i)
    {
        sf::RectangleShape snake_segment_shape = body_[i].shape;
        snake_segment_shape.setFillColor(body_[i].color);
        
        snake_segment_shape.setPosition(sf::Vector2f(body_[i].position.x * BLOCK_SIZE + 1, body_[i].position.y * BLOCK_SIZE + 1));
        snake_segment_shape.setSize(sf::Vector2f(BLOCK_SIZE - 2, BLOCK_SIZE - 2));
        
        if (i == 0)
        {
            snake_segment_shape.setPosition(sf::Vector2f(body_[i].position.x * BLOCK_SIZE, body_[i].position.y * BLOCK_SIZE));
            snake_segment_shape.setSize(body_[i].shape.getSize());
        }
        window.draw(snake_segment_shape);
    }
}

void Snake::MoveByOneCell()
{
    // проходимся в цикле начиная с хвоста
    // мжоно гуглить, как лучше сделать
    // можно самим писать
    // можно ревёрс итераторы
    
    // проход по body_ в обратном направлении
    // передвинуть все сегменты, кроме головы, на место предыдущего
    // голову передвинуть согласно direction_ (вне цикла)

    for (int i = (int)body_.size() - 1; i > 0; --i)
    {
        body_[i].position = body_[i - 1].position;
    }

    sf::Vector2i delta(0, 0);
    if (direction_ == Up)
    {
        delta.y -= 1;
    }
    if (direction_ == Down)
    {
        delta.y += 1;
    }
    if (direction_ == Left)
    {
        delta.x -= 1;
    }
    if (direction_ == Right)
    {
        delta.x += 1;
    }
    body_[0].position += delta;
    //direction_ = None;
}

void Snake::Grow()
{
    assert(!body_.empty());
    // первый случай: длина змеи равна 1 (т.е. есть только голова)
    // добавление нового сегмента на основании direction_

    size_t body_size = body_.size();

    if (body_size == 1)
    {
        Snake::Segment new_segment;
        new_segment.color = sf::Color::Green;

        sf::Vector2i delta(0, 0);
        if (direction_ == Down)
        {
            delta.y -= 1;
        }
        if (direction_ == Up)
        {
            delta.y += 1;
        }
        if (direction_ == Right)
        {
            delta.x -= 1;
        }
        if (direction_ == Left)
        {
            delta.x += 1;
        }
        new_segment.position = sf::Vector2i(body_[0].position.x + delta.x, body_[0].position.y + delta.y);
        body_.push_back(std::move(new_segment));
    }

    // второй случай: длина змеи >= 2
    // увеличить длину змеи на основании двух последних сегментов
    
    if (body_size >= 2)
    {
        Snake::Segment new_segment;
        new_segment.color = sf::Color::Green;

        Snake::Segment last_segment = body_[body_size - 1];
        Snake::Segment penult_segment = body_[body_size - 2];

        if (last_segment.position.x == penult_segment.position.x)
        {
            new_segment.position.x = last_segment.position.x;
            new_segment.position.y = 2 * last_segment.position.y - penult_segment.position.y;
        }
        if (last_segment.position.y == penult_segment.position.y)
        {
            new_segment.position.y = last_segment.position.y;
            new_segment.position.x = 2 * last_segment.position.x - penult_segment.position.x;
        }

        body_.push_back(std::move(new_segment));
    }
}