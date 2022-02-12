#include "MainMenu.hpp"

#define GORILLA "assets/images/pnj/gorillas.png"
#define PLAY ""
#define EXIT ""
#define BACK ""

sf::Texture *from_file(std::string file)
{
    sf::Texture *t = new sf::Texture;

    t->loadFromFile(file);
    return t;
}

void sprite_from_file(sf::Sprite &s, std::string file)
{
    sf::Texture *t = from_file(file);
    sf::Vector2u size = t->getSize();

    s.setTexture(*t);
    s.setOrigin(sf::Vector2f(size.x / 2.0, size.y / 2.0));
}

MainMenu::MainMenu(sf::Vector2f win_size):
    m_size(win_size),
    m_gor_dir(10, 10)
{
    sprite_from_file(m_gorille, GORILLA);
    sprite_from_file(m_play, PLAY);
    sprite_from_file(m_exit, EXIT);
    sprite_from_file(m_background, BACK);
}

void MainMenu::move_gori()
{
    auto pos = m_gorille.getPosition();

    sf::Vector2f new_pos(pos.x + m_gor_dir.x, pos.y + m_gor_dir.y);
    if (new_pos.x > m_size.x || new_pos.x < 0)
        m_gor_dir.x *= -1;
    if (new_pos.y > m_size.y || new_pos.y < 0)
        m_gor_dir.y *= -1;
    m_gorille.move(m_gor_dir);
}

void MainMenu::draw_to(Window &win)
{
    move_gori();

    win.draw(m_background);
    win.draw(m_gorille);
    win.draw(m_play);
    win.draw(m_exit);
}
