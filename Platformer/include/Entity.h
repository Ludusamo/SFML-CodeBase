#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity {
public:
    Entity();
    ~Entity();

    virtual void update();
    virtual void render(sf::Window &window);
protected:
    sf::Vector2f pos;
    sf::Sprite sprite;
private:
};

#endif // ENTITY_H
