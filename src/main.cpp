#include "Window.hpp"
#include "MainMenu.hpp"

void poll_events(Window &win)
{
    sf::Event ev;

    while (win.pollEvent(ev)) {
        if (ev.type == sf::Event::Closed ||
        (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape))
            win.close();
    }
}

void draw_win(Window &win, MainMenu &menu)
{
    win.clear(sf::Color::Blue);
    if (win.getMode() == MAIN_MENU) {
        menu.draw_to(win);
    } else;
    win.display();
}

int main(void)
{
    Window win(sf::VideoMode(800, 600), "Route du succès", sf::Style::Close | sf::Style::Resize);
    MainMenu menu(sf::Vector2f(800, 600));

    while (win.isOpen()) {
        poll_events(win);
        draw_win(win, menu);
    }
    return 0;
}
