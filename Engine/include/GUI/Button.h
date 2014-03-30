#ifndef BUTTON_H
#define BUTTON_H

#include "SFML/Graphics.hpp"
#include "Entity/Entity.h"

class Button : public Entity
{
    public:
        Button();
        ~Button();

        void load(sf::Vector2f pos, const sf::Texture& tex, sf::Vector2f texCoord, sf::Vector2f texDimensions);
        void unload();
        void update(sf::Vector2i &p);

        enum State { SAME, HIGHLIGHTED };
    protected:
    void highlight(int change);
    sf::Vector2f pos, texCoord, texDimensions;
    sf::FloatRect bounds;
    int change;
    private:

    std::string msg;
};

#endif // BUTTON_H
