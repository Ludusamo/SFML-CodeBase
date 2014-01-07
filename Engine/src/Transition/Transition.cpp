#include "Transition/Transition.h"

Transition::Transition() {
    //ctor
}

Transition::~Transition() {
    //dtor
}

void Transition::loadContent(std::string text, sf::Texture texture, sf::Vector2f pos) {
    this->preText = text;
    this->texture = texture;
    this->pos = pos;

    alpha = 1.0f;
    color = sf::Color(114, 77, 255);
    sprite.setTexture(texture);
    this->text.setString(preText);
    active= false;
}

void Transition::unloadContent() {

}

void Transition::update(sf::RenderWindow &window) {

}

void Transition::render(sf::RenderWindow &window) {
    std::string str = text.getString();
    if (str != "")
        window.draw(text);
    if (sprite.getTexture() != nullptr)
        window.draw(sprite);
}

float Transition::getAlpha() {
    return alpha;
}

void Transition::setActive(bool x) {
    active = x;
}

void Transition::setAlpha(float a) {
}
