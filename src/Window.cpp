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

Window::~Window()
{
    while (m_sc.size())
        popSuccess();
}
