
#ifndef ROAD_HPP_
    #define ROAD_HPP_

    #include <SFML/Window.hpp>
    #include <SFML/Graphics.hpp>
    #include "Window.hpp"

class Road {
    private:
        sf::Texture *back_text;

        sf::Sprite road;
        sf::Sprite back_l;
        sf::Sprite back_r;
        sf::Sprite **cones;

        void move_back();
    public:
        Road(Window &win);

        void draw(Window &win);
};

#endif
