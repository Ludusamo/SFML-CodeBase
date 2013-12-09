#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

#define FRICTION 0.9

class Entity : public sf::Drawable, public sf::Transformable {
public:
    Entity();
    ~Entity();

    virtual void load(sf::Texture &texture);
    virtual void unload();
    virtual void update();
protected:
    sf::VertexArray vertices;
    sf::Texture tex;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform *= getTransform();
        states.texture = &tex;
        target.draw(vertices, states);
    }
private:

};

#endif // ENTITY_H
