#ifndef MOB_H
#define MOB_H

#include <SFML/Graphics.hpp>
#include <Entity.h>
#include <iostream>
#include <math.h>

#define FRICTION 0.9

class Mob : public Entity {
public:
    Mob();
    ~Mob();

    virtual void load(sf::Vector2f pos, sf::Texture &texture, float MAX_VEL, sf::Vector2i mSize);
    virtual void unload();
    virtual void update(std::vector<std::vector<int>> colMap);
    void moveM(std::vector<std::vector<int>> colMap);
    void checkCollision(std::vector<std::vector<int>> colMap);
    void setAccelerationX(float a);
    void setAccelerationY(float a);
    void setVelocityX(float v);
    void setVelocityY(float v);
protected:
    sf::Vector2f velocity;
    sf::Vector2f acceleration;

    float MAX_VEL;
    sf::Vector2i mSize;

    // Collision
    std::vector<sf::FloatRect> collidable;
    sf::FloatRect collision;
    sf::FloatRect bounds;
    int startX, endX, startY, endY;
private:
    void collidableTiles(std::vector<std::vector<int>> colMap, int startX, int endX, int startY, int endY);
};

#endif // MOB_H
