#ifndef SCREEN_H
#define SCREEN_H

#include "SFML/Graphics.hpp"
#include "System/InputManager.h"
class Screen {
public:
    Screen();
    ~Screen();

    virtual void loadContent();
    virtual void unloadContent();
    virtual void update(sf::Time delta);
    virtual void render(sf::RenderWindow &window);
protected:
    InputManager input;
private:
};

#endif // SCREEN_H
