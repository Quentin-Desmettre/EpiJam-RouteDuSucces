#include "Road.hpp"
#include "Window.hpp"
#include "MainMenu.hpp"
#include "Car.hpp"
#include "Success.hpp"

void check_menu_event(Window &win, MainMenu &menu, sf::Event &ev)
{
    if (ev.type == sf::Event::MouseButtonPressed) {
        if (menu.is_exit(ev)) {
            win.addSuccess("Tried to exit");
            if (win.nbSuccess() == 0)
                win.close();
        }
        else if (menu.is_play(ev)) {
            win.addSuccess("Played the game");
            win.setMode(PLAY);
        }
    }
}

void poll_events(Window &win, MainMenu &menu)
{
    sf::Event ev;

    while (win.pollEvent(ev)) {
        if (ev.type == sf::Event::Closed ||
        (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape)) {
            win.addSuccess("Tried to exit");
            if (win.nbSuccess() == 0)
                win.close();
        }
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

void move(Road &road, Car &car, Window &win)
{
    if (!road.getCollisionRight(car.getSprite().getGlobalBounds())) {
        car.move_right(win);
    } else
        win.addSuccess("Touched the right wall");
    if (!road.getCollisionLeft(car.getSprite().getGlobalBounds())) {
        car.move_left(win);
    } else
        win.addSuccess("Touched the left wall");
}

void draw_win(Window &win, MainMenu &menu, Road &road, Car &car)
{
    win.clear(sf::Color::Blue);
    if (win.getMode() == MAIN_MENU) {
        menu.draw_to(win);
    } else {
        move(road, car, win);
        road.draw(win);
        car.draw_to(win);
    }
    if (win.nbSuccess() > 0)
        check_success(win);
    win.display();
}

int main(void)
{
    Window win(sf::VideoMode(800, 600), "Route du succès", sf::Style::Close | sf::Style::Resize);
    MainMenu menu(sf::Vector2f(800, 600));
    Road road(win);
    Car car;

    win.addSuccess("Launched the game");
    win.addSuccess("First success");
    while (win.isOpen()) {
        poll_events(win, menu);
        draw_win(win, menu, road, car);
    }
    return 0;
}
