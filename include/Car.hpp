#ifndef CAR_H
    #define CAR_H
    #include "Window.hpp"
    #include "Road.hpp"


class Car
{
private:
    sf::Sprite m_car;
    sf::Sound _damage_sfx;
    sf::Sound _crash_sfx;
    int speed_r;
    int speed_l;

    int _state;

public:
    Car();
    void draw_to(Window &win);
    void move_left(Window &win);
    void move_right(Window &win);
    sf::Sprite getSprite() const {return m_car;};

    void resetDamage();
    void takeDamage();
    bool isGameOver() {return _state >= 3;}
};


#endif /* MAIN_MENU */
