#ifndef CAR_H
    #define CAR_H
    #include "Window.hpp"
    #include "Road.hpp"


class Car
{
private:
    sf::Sprite m_car;
    int speed_r;
    int speed_l;

public:
    Car();
    void draw_to(Window &win);
    void move_left(Window &win);
    void move_right(Window &win);
    sf::Sprite getSprite() const {return m_car;};
};


#endif /* MAIN_MENU */
