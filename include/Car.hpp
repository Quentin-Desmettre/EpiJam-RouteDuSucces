#ifndef CAR_H
    #define CAR_H
    #include "Window.hpp"


class Car
{
private:
    sf::Sprite m_car;
    int speed_r;
    int speed_l;

public:
    Car();
    void draw_to(Window &win);
    void move_left();
    void move_right();
};


#endif /* MAIN_MENU */
