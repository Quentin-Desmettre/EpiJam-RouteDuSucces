/*
** EPITECH PROJECT, 2022
** Route_du_succes
** File description:
** Road
*/

#ifndef RROAD_HPP_
#define RROAD_HPP_

/* INCLUDES */

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Window.hpp"




class RRoad {
    public:
        // CONSTRUCTOR && DESTRUCTOR
        RRoad();
        ~RRoad();

        // GETTERS && SETTERS
        sf::Sprite getSprite() const {return _sprite;};

        // METHODS
        void update(Window &win);
    protected:
    private:
        sf::Sprite _sprite;
        sf::Texture _texture;
        sf::IntRect _rect;
        
};

#endif /* !ROAD_HPP_ */
