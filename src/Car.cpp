#include "Window.hpp"
#include "MainMenu.hpp"
#include "Car.hpp"

Car::Car():
    speed_r(0),
    speed_l(0)
{
    sf::Texture *t = new sf::Texture;
    t->loadFromFile("assets/images/car/car.png");
    sf::Vector2u size = t->getSize();

    m_car.setTexture(*t);
    m_car.setOrigin(sf::Vector2f(size.x / 2.0, size.y / 2.0));
    m_car.setPosition(sf::Vector2f(400, 400));
    m_car.scale(0.2, 0.2);
}

void Car::move_left()
{
    int press = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            press = 1;
        else
            press = 0;
    sf::Vector2f pos = m_car.getPosition();
    if (press && speed_l < 20)
        speed_l += 1;
    if (!press && speed_l > 0)
        speed_l -= 3;
    if (!press && speed_l < 0)
        speed_l = 0;
    pos.x -= speed_l;
    if (press)
        m_car.setRotation(-20);
    m_car.setPosition(pos);
}

void Car::move_right()
{
    int press = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            press = 1;
        else
            press = 0;
    sf::Vector2f pos = m_car.getPosition();
    if (press && speed_r < 20)
        speed_r += 1;
    if (!press && speed_r > 0)
        speed_r -= 3;
    if (!press && speed_r < 0)
        speed_r = 0;
    pos.x += speed_r;
    if (press)
        m_car.setRotation(20);
    if ((speed_l == 0 && speed_r == 0) || (speed_l == 30 && speed_r == 30))
        m_car.setRotation(0);
    m_car.setPosition(pos);
}

void Car::draw_to(Window &win)
{
    win.draw(m_car);
}
