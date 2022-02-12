
#ifndef WINDOW_HPP
    #define WINDOW_HPP
    #include <SFML/Window.hpp>
    #include <SFML/Graphics.hpp>
    #include <string>

class Window : public sf::RenderWindow
{
private:

public:
    Window(sf::VideoMode mode, std::string name, sf::Uint8 style);
};

#endif
