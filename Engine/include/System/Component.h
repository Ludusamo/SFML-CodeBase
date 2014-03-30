#ifndef COMPONENT_H
#define COMPONENT_H

#include <vector>
#include "GUI/Button.h"
#include "SFML/Graphics.hpp"
#include "SFML/System/Vector2.hpp"

class Component : public sf::Drawable, public sf::Transformable{
    public:
        Component();
        ~Component();

        void load(sf::Vector2f pos, sf::Vector2f SIZE, sf::Texture texture);
        void unload();
        void update(sf::Vector2i &p);

        void addButton(Button &b);

        std::vector<Button> getButtons();
    protected:
    sf::VertexArray vertices;
    sf::Texture tex;
    std::vector<Button> buttons;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform *= getTransform();
        states.texture = &tex;
        target.draw(vertices, states);
        for (Button b : buttons) {
            target.draw(b, states);
        }
    }
    private:

};

#endif // COMPONENT_H
