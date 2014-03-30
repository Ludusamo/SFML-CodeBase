#include "Screens/Screen.h"

Screen::Screen() {
    //ctor
}

Screen::~Screen() {
    //dtor
}

void Screen::loadContent() {

}

void Screen::unloadContent() {

}

void Screen::update(sf::Time &delta) {
    for (Component &c : components)
        c.update(mousePos);
}

void Screen::render(sf::RenderWindow &window) {
    mousePos = sf::Mouse::getPosition(window);
    for (Component &c : components)
        window.draw(c);
}

