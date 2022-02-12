
#ifndef WINDOW_HPP
    #define WINDOW_HPP
    #include <SFML/Window.hpp>
    #include <SFML/Graphics.hpp>
    #include <string>

typedef enum {MAIN_MENU, PLAY} win_mode;

class Window : public sf::RenderWindow
{
private:
    win_mode m_mode;

public:
    Window(sf::VideoMode mode, std::string name, sf::Uint8 style);
    win_mode getMode(void) {return m_mode;}
    void setMode(win_mode new_mode) {m_mode = new_mode;}
};

#endif
