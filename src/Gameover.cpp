/*
** EPITECH PROJECT, 2022
** Gameover.cpp
** File description:
** Gameover
*/

#include "Window.hpp"

void init_text(sf::Text &t, std::string const name);

void load_text(sf::Text &t, std::string const name);

static const char *quotes[9] =
{"Béliève, croire en nos rêves !",
"Never (gonna) give (you) up",
"You did it !",
"Be you, be proud of you, because you can be do what we want to do.",
"Just do it !",
"Yes you can !",
"The road of success is always under construction.",
"Whatever you do, always give 100%... Unless you're donating blood...",
"J'ai couru jusqu'à quand ce que je pouvais."};

void draw_game_over(Window &win, int reset)
{
    static int num = rand() % 9;
    sf::Text over;
    sf::Text mot_quote;
    sf::Vector2u pos = win.getSize();

    if (reset) {
        num = rand() % 9;
        return;
    }
    pos.x /= 2;
    pos.y /= 2;

    init_text(over, "Game over");
    load_text(over, "Game over");

    init_text(mot_quote, quotes[num]);
    load_text(mot_quote, quotes[num]);

    sf::FloatRect size = mot_quote.getGlobalBounds();
    pos.x -= size.width / 2;
    pos.y -= size.height / 2;
    pos.y += 30;

    mot_quote.setPosition(pos.x, pos.y);

    pos = win.getSize();
    over.setCharacterSize(50);
    size = over.getGlobalBounds();

    pos.x /= 2;
    pos.y /= 2;
    pos.x -= size.width / 2;
    pos.y -= size.height / 2;
    pos.x -= 30;
    pos.y -= 100;

    over.setPosition(pos.x, pos.y);

    win.draw(mot_quote);
    win.draw(over);
}