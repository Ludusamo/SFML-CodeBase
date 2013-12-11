#ifndef TRANSITION_H
#define TRANSITION_H

#include <SFML/Graphics.hpp>
#include <string>

class Transition {
public:
    Transition();
    ~Transition();

    virtual void loadContent(std::string text, sf::Texture texture, sf::Vector2f pos);
    virtual void unloadContent();
    virtual void update(sf::RenderWindow &window);
    virtual void render(sf::RenderWindow &window);
    virtual void setAlpha(float a);
    void setActive(bool x);

    float getAlpha();
protected:
    float alpha;
    std::string preText;
    sf::Text text;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f pos;
    sf::Color color;
    sf::IntRect srcRect;
    bool active;
private:
};

#endif // TRANSITION_H
