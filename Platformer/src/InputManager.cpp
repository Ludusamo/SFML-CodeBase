#include "InputManager.h"

InputManager::InputManager() {
    //ctor
}

InputManager::~InputManager() {
    //dtor
}

void InputManager::update(sf::Event event) {
    this->event = event;
}

bool InputManager::keyPressed(sf::Keyboard::Key key) {
    if (sf::Keyboard::isKeyPressed(key))
        return true;
    return false;
}

bool InputManager::keyPressed(std::vector<sf::Keyboard::Key> keys) {
    for (int i = 0; i < keys.size(); i++) {
        if (keyPressed(keys.at(i)))
            return true;
    }
    return false;
}


