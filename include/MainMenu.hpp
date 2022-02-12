#ifndef MAIN_MENU_H
    #define MAIN_MENU_H
    #include "Window.hpp"

static const sf::IntRect gori_sprites[4] {
    {5, 0, 39, 48},
    {0, 0, 39, 48},
    {0, 0, 39, 48},
    {0, 0, 48, 48},
};

class MainMenu
{
private:
    sf::Sprite m_gorille, m_play, m_exit;
    sf::Sprite m_background;

    sf::Vector2f m_size;
    sf::Vector2f m_gor_dir;

    void move_gori();
public:
    MainMenu(sf::Vector2f win_size);

    void draw_to(Window &win);
};


#endif /* MAIN_MENU */
