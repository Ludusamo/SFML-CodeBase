#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Entity/Mob.h"

#define FRICTION 0.9

class Player : public Mob {
public:
    Player();
    ~Player();

    void load(sf::Vector2f pos, sf::Texture &texture, float MAX_VEL, sf::Vector2i mSize);
    void unload();
protected:
private:
    sf::Sprite p_sprite;
    sf::Texture p_tex;
};

#endif // PLAYER_H
