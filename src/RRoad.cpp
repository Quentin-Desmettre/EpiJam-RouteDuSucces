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
    _rect = sf::IntRect(0, 0, 131, 427);
    _texture.loadFromFile(ROAD);
    _texture.setRepeated(true);
    _sprite.setOrigin(50, 213);
    _sprite.setTexture(_texture);
    _sprite.setTextureRect(_rect);
    _sprite.setScale(2.7, 2.7);
    _sprite.setPosition(358, 300);
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
