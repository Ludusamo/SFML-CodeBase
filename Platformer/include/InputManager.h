#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <vector>
#include <SFML/Graphics.hpp>

class InputManager {
public:
    InputManager();
    ~InputManager();

    void update(sf::Event event);
    bool keyPressed(int key);
    bool keyPressed(std::vector<int> keys);
    bool keyReleased(int key);
    bool keyReleased(std::vector<int> keys);
protected:
private:
    sf::Event event;
};

#endif // INPUTMANAGER_H
