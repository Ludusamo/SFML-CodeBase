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

bool InputManager::keyPressed(int key) {
    if (event.key.code == key && event.type == sf::Event::KeyPressed)
        return true;
    return false;
}

bool InputManager::keyPressed(std::vector<int> keys) {
    for (int i = 0; i < keys.size(); i++) {
        if (keyPressed(keys.at(i)))
            return true;
    }
    return false;
}

bool InputManager::keyReleased(int key) {
    if (event.key.code == key && event.type == sf::Event::KeyReleased)
        return true;
    return false;
}

bool InputManager::keyReleased(std::vector<int> keys) {
    for (int i = 0; i < keys.size(); i++) {
        if (keyReleased(keys.at(i)))
            return true;
    }
    return false;
}
