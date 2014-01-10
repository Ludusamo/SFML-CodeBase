#include "System/Physics.h"

Physics::Physics() {
    //ctor
}

Physics::~Physics() {
    //dtor
}

void Physics::load(float GRAVITY) {
    this->GRAVITY = sf::Vector2f(0, GRAVITY);
}

void Physics::unload() {

}

void Physics::update() {
    for (Mob m : pem) {
        m.addAcceleration(GRAVITY);
    }
}

void Physics::addMob(Mob mob) {
    pem.push_back(mob);
}

void Physics::addMob(std::vector<Mob> mobs) {
    for (Mob m : mobs) addMob(m);
}
