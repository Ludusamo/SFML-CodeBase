#ifndef MOB_H
#define MOB_H

#include <SFML/Graphics.hpp>
#include <Entity.h>

#define FRICTION 0.9

class Mob : public Entity {
public:
    Mob();
    ~Mob();

    virtual void load(sf::Vector2f pos, sf::Texture &texture, float MAX_VEL);
    virtual void unload();
    virtual void update();
    void moveM();
    void setAccelerationX(float a);
    void setAccelerationY(float a);
protected:
    sf::Vector2f velocity;
    sf::Vector2f acceleration;

    float MAX_VEL;
    sf::FloatRect bounds;
private:
    void checkCollision();
    void collidableTiles();
};

#endif // MOB_H
