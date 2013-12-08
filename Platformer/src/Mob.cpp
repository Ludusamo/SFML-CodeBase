#include "Mob.h"

Mob::Mob() {
    //ctor
}

Mob::~Mob() {
    //dtor
}

void Mob::load(sf::Vector2f pos, sf::Texture &texture, float MAX_VEL) {
    this->MAX_VEL = MAX_VEL;
    setPosition(pos);

    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(4);
    tex = texture;
}

void Mob::unload() {
    vertices.clear();
}

void Mob::update() {
    moveM();
}

void Mob::moveM() {
    velocity += acceleration;
    checkCollision();
    velocity.x *= FRICTION;
    velocity.y *= FRICTION;
    if (velocity.x > MAX_VEL) velocity.x = MAX_VEL;
    if (velocity.x < -MAX_VEL) velocity.x = -MAX_VEL;
    if (velocity.y > MAX_VEL) velocity.y = MAX_VEL;
    if (velocity.y < -MAX_VEL) velocity.y = -MAX_VEL;
    move(velocity);
}

void Mob::checkCollision() {

}

void Mob::collidableTiles() {

}

void Mob::setAccelerationX(float a) {
    acceleration.x = a;
}

void Mob::setAccelerationY(float a) {
    acceleration.y = a;
}
