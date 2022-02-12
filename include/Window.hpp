
#ifndef WINDOW_HPP
    #define WINDOW_HPP
    #include <SFML/Window.hpp>
    #include <SFML/Graphics.hpp>
    #include <string>
    #include "Success.hpp"
    #include <list>
    #include "Enemy.hpp"

typedef enum {MAIN_MENU, PLAY} win_mode;

class Success;

class Window : public sf::RenderWindow
{
private:
    win_mode m_mode;
    std::list<Success*> m_sc;
    std::vector<std::string> m_viewed_sc;
    sf::RectangleShape dark;

    std::vector<Enemy> _enemies;

public:
    int stop;
    void draw_dark();
    Window(sf::VideoMode mode, std::string name, sf::Uint8 style);
    win_mode getMode(void) {return m_mode;}
    void setMode(win_mode new_mode) {m_mode = new_mode;}

    void addSuccess(std::string const what);
    void popSuccess();
    Success *curSuccess(void);
    std::size_t nbSuccess(void) const {return m_sc.size();}

    void addEnemy(enemy_type type, float x_start);
    void drawEnemies(void);
    void moveEnemies(Road &r);
    ~Window();
};

#endif
