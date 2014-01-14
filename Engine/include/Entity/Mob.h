#ifndef MOB_H
#define MOB_H

#include <SFML/Graphics.hpp>
#include "Entity/Mob.h"
#include "Entity/Entity.h"
#include <Animation.h>
#include <iostream>
#include <math.h>

#define FRICTION 0.9

class Mob : public Entity {
public:
    Mob();
    ~Mob();

    virtual void load(sf::Vector2f pos, sf::Texture &texture, float MAX_VEL, sf::Vector2i mSize);
    virtual void unload();
    virtual void update(std::vector<std::vector<int>> colMap, sf::Time delta);
    void moveM(std::vector<std::vector<int>> colMap, sf::Time delta);
    void checkCollision(std::vector<std::vector<int>> colMap, sf::Time delta);
    void setAccelerationX(float a);
    void setAccelerationY(float a);
    void setVelocityX(float v);
    void setVelocityY(float v);
    void addAcceleration(sf::Vector2f v);
    Animation &getAnimation();
protected:
    // Physics
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    float MAX_VEL;

    // Graphics
    sf::Vector2i mSize;
    Animation animation;

    // Collision
    std::vector<sf::FloatRect> collidable;
    sf::FloatRect collision;
    sf::FloatRect bounds;
    int startX, endX, startY, endY;
private:
    void collidableTiles(std::vector<std::vector<int>> colMap, int startX, int endX, int startY, int endY);
    bool contains(sf::FloatRect x, sf::FloatRect y);
    enum direction { UP, DOWN, LEFT, RIGHT };
};

#endif // MOB_H
