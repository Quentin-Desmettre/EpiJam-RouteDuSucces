/*
** EPITECH PROJECT, 2022
** Route_du_succes
** File description:
** Road
*/

#include "RRoad.hpp"

#define ROAD "assets/images/env/road.png"

int PARALLAX_SPEED = 2;

RRoad::RRoad()
{
    _rect = sf::IntRect(0, 0, 101, 427);   
    _texture.loadFromFile(ROAD);
    _texture.setRepeated(true);
    _sprite.setOrigin(50, 213);
    _sprite.setTexture(_texture);
    _sprite.setTextureRect(_rect);
    _sprite.setScale((sf::Vector2f){4.5, 4.5});
    _sprite.setPosition((sf::Vector2f){400, 300});
}

void RRoad::update(Window &win)
{
    _rect.top -= PARALLAX_SPEED;
    _sprite.setTextureRect(_rect);
    win.draw(_sprite);
}

RRoad::~RRoad()
{
}
