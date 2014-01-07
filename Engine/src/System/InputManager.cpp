#include "System/InputManager.h"

InputManager::InputManager() {
    //ctor
}

InputManager::~InputManager() {
    //dtor
}

bool InputManager::keyPressed(sf::Keyboard::Key key) {
    if (sf::Keyboard::isKeyPressed(key))
        return true;
    return false;
}

bool InputManager::keyPressed(std::vector<sf::Keyboard::Key> keys) {
    for (unsigned int i = 0; i < keys.size(); i++) {
        if (keyPressed(keys.at(i)))
            return true;
    }
    return false;
}


