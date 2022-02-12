#ifndef FC771CB9_4F53_473A_8DE1_22E751EA9BA1
#define FC771CB9_4F53_473A_8DE1_22E751EA9BA1

#include "Window.hpp"

class Success : public sf::Clock
{
private:
    sf::Sprite m_box;
    sf::Text m_text;
    sf::Text m_achiev;

public:
    Success(std::string const name, sf::Vector2u const win_size);

    sf::Int32 msElapsed() const {return getElapsedTime().asMilliseconds();}

    void draw_to(Window &win);
    void setPosition(sf::Vector2f const pos);
    void setPosition(float x, float y);

    void move(sf::Vector2f const pos);
    void move(float x, float y);
};

#endif /* FC771CB9_4F53_473A_8DE1_22E751EA9BA1 */
