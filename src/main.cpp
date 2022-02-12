#include "Road.hpp"
#include "Window.hpp"
#include "MainMenu.hpp"
#include "Car.hpp"
#include "Success.hpp"

void check_menu_event(Window &win, MainMenu &menu, sf::Event &ev)
{
    if (ev.type == sf::Event::MouseButtonPressed) {
        if (menu.is_exit(ev))
            win.close();
        else if (menu.is_play(ev))
            win.setMode(PLAY);
    }
}

void poll_events(Window &win, MainMenu &menu)
{
    sf::Event ev;

    while (win.pollEvent(ev)) {
        if (ev.type == sf::Event::Closed ||
        (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape))
            win.close();
        if (win.getMode() == MAIN_MENU)
            check_menu_event(win, menu, ev);
    }
}

void check_success(Window &win)
{
    Success *cur = win.curSuccess();
    if (cur->msElapsed() < 3000) {
        if (!cur->hasPlayed())
            cur->play();
        cur->draw_to(win);
    } else {
        win.popSuccess();
        if (win.curSuccess())
            win.curSuccess()->reset();
    }
}

void draw_win(Window &win, MainMenu &menu, Road &road, Car car)
{
    win.clear(sf::Color::Blue);
    if (win.getMode() == MAIN_MENU) {
        menu.draw_to(win);
    } else {
        road.draw(win);
        car.draw_to(win);
    }
    if (win.nbSuccess() > 0)
        check_success(win);
    win.display();
}

void move(Road &road, Car &car, Window &win)
{
    if (!road.getCollisionRight(car.getSprite().getGlobalBounds()))
        car.move_right();
    else
        win.addSuccess("Touch the right wall");
    if (!road.getCollisionLeft(car.getSprite().getGlobalBounds()))
        car.move_left();
    else
        win.addSuccess("Touch the left wall");
}

int main(void)
{
    Window win(sf::VideoMode(800, 600), "Route du succès", sf::Style::Close | sf::Style::Resize);
    MainMenu menu(sf::Vector2f(800, 600));
    Road road(win);
    Car car;

    win.addSuccess("Launched the game");
    while (win.isOpen()) {
        move(road, car, win);
        poll_events(win, menu);
        draw_win(win, menu, road, car);
    }
    return 0;
}
