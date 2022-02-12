#include "Window.hpp"
#include <iostream>

Window::Window(sf::VideoMode mode, std::string name, sf::Uint8 style):
    sf::RenderWindow(mode, name, style),
    m_mode(MAIN_MENU),
    stop(0)
{
    dark.setFillColor(sf::Color(0, 0, 0, 100));
    dark.setSize(sf::Vector2f(800, 600));
    setFramerateLimit(60);
}

void Window::addSuccess(std::string const what)
{
    if (std::find(m_viewed_sc.begin(), m_viewed_sc.end(), what) != m_viewed_sc.end())
        return;
    m_sc.push_back(new Success(what, getSize()));
    m_viewed_sc.push_back(what);
}

void Window::popSuccess()
{
    if (nbSuccess()) {
        delete m_sc.front();
        m_sc.pop_front();
    }
}

void Window::draw_dark()
{
    draw(dark);
}

Success *Window::curSuccess(void)
{
    if (!nbSuccess())
        return nullptr;
    return m_sc.front();
}

void Window::addEnemy(Enemy e)
{
    _enemies.push_back(e);
}

void Window::drawEnemies(void)
{
    for (Enemy i: _enemies)
        draw(i);
}

void Window::moveEnemies(Road &r)
{
    std::vector<std::vector<Enemy>::iterator> to_remove;
    for (std::vector<Enemy>::iterator it = _enemies.begin();
    it != _enemies.end(); it++) {
        (*it).update_pos(r);
        if ((*it).getPosition().y > getSize().y)
            to_remove.push_back(it);
    }
    for (int i = 0, n = to_remove.size(); i < n; i++)
        _enemies.erase(to_remove[i]);
}

Window::~Window()
{
    while (m_sc.size())
        popSuccess();
}
