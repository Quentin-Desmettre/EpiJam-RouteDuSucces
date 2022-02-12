#include "Window.hpp"

void poll_events(Window &win)
{
    sf::Event ev;

    while (win.pollEvent(ev)) {
        if (ev.type == sf::Event::Closed || (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape))
            win.close();
    }
}

int main(void)
{
    Window win(sf::VideoMode(800, 600), "Route du succès", sf::Style::Close | sf::Style::Resize);

    while (win.isOpen()) {
        poll_events(win);
        // draw_win(win);
    }
    return 0;
}