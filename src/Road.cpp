#include "Road.hpp"

#define BACK "assets/images/env/building.png"
#define ROAD ""

sf::Texture *from_file(std::string file);

void sprite_from_file(sf::Sprite &s, std::string file, sf::IntRect *rect = nullptr);

void Road::move_back()
{
    sf::IntRect rect_l = back_l.getTextureRect();
    sf::IntRect rect_r = back_r.getTextureRect();

    rect_l.left += 5;
    rect_r.left -= 5;
    back_l.setTextureRect(rect_l);
    back_r.setTextureRect(rect_r);
}

void Road::draw(Window &win)
{
    move_back();

    win.draw(road);
    win.draw(back_l);
    win.draw(back_r);
}

Road::Road(Window &win)
{
    back_text = from_file(BACK);
    back_text->setRepeated(true);

    sprite_from_file(road, ROAD);

    back_l.setTexture(*back_text);
    back_l.setOrigin(0, 0);
    back_l.setRotation(-90);
    back_l.setPosition(-20, 485 * 1.25);
    back_l.setScale(1.25, 1.25);

    back_r = back_l;

    back_r.setRotation(90);
    back_r.setPosition(win.getSize().x + 20, 0);
    sf::IntRect rect_r = back_r.getTextureRect();
    rect_r.left += 50;
    back_r.setTextureRect(rect_r);
}

bool Road::getCollisionLeft(sf::FloatRect car_hb)
{
    sf::FloatRect left_hb = back_l.getGlobalBounds();
    // left_hb.left -= 5;
    return (left_hb.intersects(car_hb)) ? true : false;
}

bool Road::getCollisionRight(sf::FloatRect car_hb)
{
    sf::FloatRect right_hb = back_r.getGlobalBounds();
    // right_hb.width += 5;
    return (right_hb.intersects(car_hb)) ? true : false;
}