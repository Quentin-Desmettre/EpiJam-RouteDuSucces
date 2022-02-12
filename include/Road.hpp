
#ifndef ROAD_HPP_
    #define ROAD_HPP_

    #include <SFML/Window.hpp>
    #include <SFML/Graphics.hpp>
    #include "Window.hpp"

class Road {
    private:
        sf::Sprite road;
        sf::Sprite back;
        sf::Sprite **cones;

        sf::Vector2f pos_back;
    public:
        Road();

        void draw(Window &win);
};

#endif
