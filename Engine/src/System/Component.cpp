#include "System/Component.h"

Component::Component()
{
    //ctor
}

Component::~Component()
{
    //dtor
}

void Component::load(sf::Vector2f pos, sf::Vector2f SIZE, sf::Texture texture) {
    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(4);
    vertices[0].position = sf::Vector2f(0, 0);
    vertices[1].position = sf::Vector2f(SIZE.x, 0);
    vertices[2].position = sf::Vector2f(SIZE.x, SIZE.y);
    vertices[3].position = sf::Vector2f(0, SIZE.y);
    vertices[0].texCoords = sf::Vector2f(0, 0);
    vertices[1].texCoords = sf::Vector2f(SIZE.x, 0);
    vertices[2].texCoords = sf::Vector2f(SIZE.x, SIZE.y);
    vertices[3].texCoords = sf::Vector2f(0, SIZE.y);
    tex = texture;

    setPosition(pos);
}

void Component::unload() {
    vertices.clear();
}

void Component::update(sf::Vector2i &p) {
    for (Button &b: buttons) {
        b.update(p);
    }
}

void Component::addButton(Button &b) {
    buttons.push_back(b);
}

std::vector<Button> Component::getButtons() {
    return buttons;
}
