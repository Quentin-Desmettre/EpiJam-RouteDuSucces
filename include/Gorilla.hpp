#ifndef GORILLA_HPP_
    #define GORILLA_HPP_

    #include "Window.hpp"

class Gorilla {
    private:
        int dir;

        sf::Sprite sprite;
    public:
        Gorilla();

        void add_enemy();
        void move();
        void draw(Window &win);
};

#endif
