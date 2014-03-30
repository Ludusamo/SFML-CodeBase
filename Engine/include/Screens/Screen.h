#ifndef SCREEN_H
#define SCREEN_H

#include <vector>
#include "SFML/Graphics.hpp"
#include "System/InputManager.h"
#include "System/Component.h"

class Screen {
public:
    Screen();
    ~Screen();

    virtual void loadContent();
    virtual void unloadContent();
    virtual void update(sf::Time &delta);
    virtual void render(sf::RenderWindow &window);
protected:
    InputManager input;
    std::vector<Component> components;
    sf::Vector2i mousePos;
private:
};

#endif // SCREEN_H
