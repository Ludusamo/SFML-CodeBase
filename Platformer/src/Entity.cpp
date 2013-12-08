#include "Entity.h"

Entity::Entity() {
    //ctor
}

Entity::~Entity() {
    //dtor
}

void Entity::load(sf::Texture &texture) {
    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(4);
    tex = texture;
}

void Entity::unload() {
    vertices.clear();
}

void Entity::update() {

}
