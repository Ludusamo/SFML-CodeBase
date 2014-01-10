#ifndef PHYSICS_H
#define PHYSICS_H

#include <vector>
#include "Entity/Mob.h"
#include <SFML/System/Vector2.hpp>

class Physics {
public:
    Physics();
    ~Physics();

    void load(float GRAVITY);
    void unload();
    void update();
    void addMob(Mob mob);
    void addMob(std::vector<Mob> mobs);
protected:
private:
    std::vector<Mob> pem;
    sf::Vector2f GRAVITY;
};

#endif // PHYSICS_H
