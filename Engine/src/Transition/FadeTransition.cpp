#include "Transition/FadeTransition.h"

FadeTransition::FadeTransition() {
    //ctor
}

FadeTransition::~FadeTransition() {
    //dtor
}

void FadeTransition::loadContent(std::string text, sf::Texture texture, sf::Vector2f pos) {
    Transition::loadContent(text, texture, pos);
    increase = false;
    fadeSpeed = 0.01;
}

void FadeTransition::unloadContent() {

}

void FadeTransition::update(sf::RenderWindow &window) {
    if (active) {
        if (!increase)
            alpha -= fadeSpeed;
        else
            alpha += fadeSpeed;

        if (alpha >= 1.0f) {
            alpha = 1.0f;
            increase = false;
        } else if (alpha <= 0.0f) {
            alpha = 0.0f;
            increase = true;
        }
    } else
        alpha = 1.0f;
}

void FadeTransition::render(sf::RenderWindow &window) {
    Transition::render(window);
}

void FadeTransition::setAlpha(float a) {
    alpha = a;
    if (alpha == 0.0f)
        increase = true;
    else
        increase = false;
}
