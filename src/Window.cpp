#include "Window.hpp"

Window::Window(sf::VideoMode mode, std::string name, sf::Uint8 style):
    sf::RenderWindow(mode, name, style),
    m_mode(MAIN_MENU)
{
    setFramerateLimit(60);
}