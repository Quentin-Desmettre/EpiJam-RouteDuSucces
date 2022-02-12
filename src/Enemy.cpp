#include "Enemy.hpp"
#define PLOT_PNG ""
#define ENTREPRENEUR_PNG ""
#define BANANA_PNG ""

static const sf::Texture *textures[3] = {
    from_file(PLOT_PNG),
    from_file(ENTREPRENEUR_PNG),
    from_file(BANANA_PNG)
};

Enemy::Enemy(int const type, float const x_start)
{
    setTexture(*(textures[type]));
    setPosition(x_start, 0);
}

void Enemy::update_pos(Road &r)
{
    move(0, r.getSpeed());
}
