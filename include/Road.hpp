
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
        sf::Sprite _sprite;
        sf::Texture _texture;
        sf::IntRect _rect;

        void move_back();
    public:
        // CONSTRUCTOR && DESTRUCTOR
        ~Road();

        // GETTERS && SETTERS
        sf::Sprite getSprite() const {return _sprite;};

        // METHODS
        void update(Window &win);
        Road(Window &win);

        void draw(Window &win);
};

#endif
