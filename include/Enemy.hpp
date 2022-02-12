#ifndef C14B8CCC_176F_4FC2_A6E4_02D0F4E6D911
#define C14B8CCC_176F_4FC2_A6E4_02D0F4E6D911

#include "MainMenu.hpp"
#include "Road.hpp"
typedef enum {PLOT, ENTREPRENEUR, BANANA} enemy_type;

class Enemy : public sf::Sprite
{
private:
    double m_x_velo;

public:
    Enemy(enemy_type const type, float const x_start);

    void update_pos(Road &r);
};

#endif /* C14B8CCC_176F_4FC2_A6E4_02D0F4E6D911 */
