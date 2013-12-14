#ifndef BUTTON_H
#define BUTTON_H

#include "SFML/Graphics.hpp"
#include "Entity.h"

class Button : public Entity
{
    public:
        Button();
        ~Button();

        void load(const std::string& message, sf::Vector2f pos, const sf::Texture& sprites, const sf::Font& font);
        void unload();
        void update(sf::Vector2i p);

        enum State { SAME, HIGHLIGHTED };
    protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform *= getTransform();
        states.texture = &sprites;
        target.draw(vertices, states);
        target.draw(message, states);
    }
    private:
    void highlight(int change);
    sf::Vector2f pos;
    sf::FloatRect bounds;
    int change;
    std::string msg;
    sf::Texture sprites;
    sf::Text message;
    sf::Font font;
};

#endif // BUTTON_H
