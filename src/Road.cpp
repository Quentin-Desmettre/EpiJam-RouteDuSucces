#include "Road.hpp"

#define BACK "assets/images/env/building.png"
#define ROAD ""

void sprite_from_file(sf::Sprite &s, std::string file, sf::IntRect *rect = nullptr);

void Road::draw(Window &win)
{
    back.move(0, 1);

    win.draw(road);
    win.draw(back);
}

Road::Road()
{
    sprite_from_file(road, ROAD);
    sprite_from_file(back, BACK);

    pos_back = {0, 0};
}