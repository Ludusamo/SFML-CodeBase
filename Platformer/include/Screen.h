#ifndef SCREEN_H
#define SCREEN_H

#include "SFML/Graphics.hpp"
#include "InputManager.h"
class Screen {
public:
    Screen();
    ~Screen();

    virtual void loadContent();
    virtual void unloadContent();
    virtual void update(sf::Event event);
    virtual void render(sf::RenderWindow &window);
protected:
    InputManager input;
    std::vector<sf::Keyboard::Key> keys;
private:
};

#endif // SCREEN_H
