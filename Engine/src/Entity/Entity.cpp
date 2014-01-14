#include "Entity/Entity.h"

Entity::Entity() {
    //ctor
}

Entity::~Entity() {
    //dtor
}

void Entity::load(sf::Vector2f &pos, sf::Texture &texture) {
    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(4);
    tex = texture;

    pos.x *= 32;
    pos.y *= 32;

    setPosition(pos);
}

void Entity::unload() {
    vertices.clear();
}

void Entity::update(sf::Time delta) {

}
