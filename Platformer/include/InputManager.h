#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <vector>
#include <SFML/Graphics.hpp>

class InputManager {
public:
    InputManager();
    ~InputManager();

    bool keyPressed(sf::Keyboard::Key key);
    bool keyPressed(std::vector<sf::Keyboard::Key> keys);
protected:
private:
    sf::Event event;
};

#endif // INPUTMANAGER_H
