#include "Window.hpp"
#include "Gorilla.hpp"
#include "MainMenu.hpp"

#define GORILLA "assets/images/pnj/gorillas.png"

void Gorilla::move()
{
    if (sprite.getPosition().x <= 270 || sprite.getPosition().x >= 550 || rand() % 80 == 0)
        dir = -dir;
    sprite.move(2.5 * dir, 0);
}

void Gorilla::draw(Window &win)
{
    win.draw(sprite);
    move();
}

Gorilla::Gorilla()
{
    dir = rand() % 1;
    dir = dir ? 1 : -1;

    sprite_from_file(sprite, GORILLA, (sf::IntRect*)(gori_sprites));
    sprite.scale(3.3, 3.3);
    sprite.setTextureRect(gori_sprites[4]);
    sprite.setPosition(rand() % 278 + 271, 80);
}