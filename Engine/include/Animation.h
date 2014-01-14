#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Animation {
public:
    Animation();
    ~Animation();

    void load(int startIndexX, int startIndexY, int totalFrames, float delay);
    void unload();
    void update(sf::VertexArray &vertices, sf::Vector2i mSize, sf::Time delta);
    void setModifier(int x);
protected:
private:
    int currentAnimationIndex, totalFrames, startIndexX, startIndexY, modifier;
    float delay, elapsedTime;
};

#endif // ANIMATION_H
