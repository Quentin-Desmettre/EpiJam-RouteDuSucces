#include "Road.hpp"
#include "Window.hpp"
#include "MainMenu.hpp"
#include "Gorilla.hpp"
#include "Car.hpp"
#include "Success.hpp"
#include "Score.hpp"

void draw_game_over(Window &win, int reset);

void check_car_collision(Road &road, Car &car, Window &win);

void check_menu_event(Window &win, MainMenu &menu, sf::Event &ev, Road &r, Car &car, Score &sc)
{
    if (ev.type == sf::Event::MouseButtonPressed) {
        if (menu.is_exit(ev) && win.stop == 0) {
            win.addSuccess("Tried to exit");
            if (win.nbSuccess() == 0)
                win.close();
        }
        if (menu.is_exit(ev) && win.stop == 1) {
            win.addSuccess("Back to menu");
            win.setMode(MAIN_MENU);
            r.setSpeed(5);
            win.stop = 0;
        } else if (menu.is_play(ev)) {
            win.addSuccess("Played the game");
            if (win.getMode() == MAIN_MENU) {
                win.clearEnemies();
                car.setState(0);
                car.resetDamage();
                sc.resetScore();
                draw_game_over(win, 1);
            }
            win.setMode(PLAY);
            win.stop = 0;
        }
    }
}

void poll_events(Window &win, MainMenu &menu, Road &r, Car &c, Score &sc)
{
    sf::Event ev;

    while (win.pollEvent(ev)) {
        if (ev.type == sf::Event::Closed ||
        ((ev.type == sf::Event::KeyPressed && win.getMode() == MAIN_MENU) && ev.key.code == sf::Keyboard::Escape)) {
            win.addSuccess("Tried to exit");
            if (win.nbSuccess() == 0)
                win.close();
        }
        if (
        (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape && win.getMode() != MAIN_MENU)) {
            win.addSuccess("Do you want a little break?");
            win.stop = !win.stop;
        }
        if (win.getMode() == MAIN_MENU || win.stop)
            check_menu_event(win, menu, ev, r, c, sc);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        win.addSuccess("Drift god");
}

void check_success(Window &win)
{
    Success *cur = win.curSuccess();
    if (cur->msElapsed() < 2000) {
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

void draw_win(Window &win, MainMenu &menu, Road &road, Car &car, Gorilla &gorilla, Score &sc)
{
    win.clear(sf::Color::Black);
    if (win.getMode() == MAIN_MENU) {
        menu.draw_to(win);
    } else {
        road.draw(win);
        car.draw_to(win);
        win.drawEnemies();
        if (car.isGameOver())
            draw_game_over(win, 0);
    }
    if (win.stop) {
        win.draw_dark();
        menu.draw_to(win);
    } else if (win.getMode() != MAIN_MENU) {
        gorilla.draw(win);
        sc.drawTo(win);
    }
    if (win.nbSuccess() > 0)
        check_success(win);
    win.display();
}

void move_all(Window &win, Road &road, Car &car, Gorilla &g, Score &sc)
{
    if (win.getMode() != MAIN_MENU && !car.isGameOver()) {
        check_car_collision(road, car, win);
        move(road, car, win);
        g.move(win);
        road.move_back();
        win.moveEnemies(road);
        if (sc.msElapsed().asMilliseconds() > 75) {
            sc.restartClock();
            sc.addScore(road.getSpeed());
        }
    }
}

int main(int ac, char **av)
{
    Window win(sf::VideoMode(800, 600), "Route du succès", sf::Style::Close | sf::Style::Resize);
    MainMenu menu(sf::Vector2f(800, 600));
    Road road(win);
    Car car;
    Gorilla gorilla;
    Score sc(win.getSize().x * 0.03, win.getSize().y * 0.85);

    if (ac == 2 && av[1] == std::string("tg"))
        win.ferme_ta_gueule(true);
    win.addSuccess("Launched the game");
    win.addSuccess("First success");
    while (win.isOpen()) {
        if (win.stop == 0)
            move_all(win, road, car, gorilla, sc);
        poll_events(win, menu, road, car, sc);
        draw_win(win, menu, road, car, gorilla, sc);
    }
    return 0;
}
