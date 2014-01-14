#include "Animation.h"

Animation::Animation() {
    //ctor
}

Animation::~Animation() {
    //dtor
}

void Animation::load(int startIndexX, int startIndexY, int totalFrames, float delay) {
    this->startIndexX = startIndexX;
    this->startIndexY = startIndexY;
    this->totalFrames = totalFrames;
    this->delay = delay;
    elapsedTime = 0;
    currentAnimationIndex = 0;
    modifier = 0;
}

void Animation::unload() {

}

void Animation::update(sf::VertexArray &vertices, sf::Vector2i mSize, sf::Time delta) {
    elapsedTime += delta.asSeconds();
    if (elapsedTime > delay) {
        if (currentAnimationIndex + 1 < totalFrames) currentAnimationIndex++;
        else currentAnimationIndex = 0;
        elapsedTime = 0;
    }
    vertices[0].texCoords = sf::Vector2f((startIndexX * mSize.x) + (currentAnimationIndex * mSize.x), (startIndexY * mSize.y) + (modifier * mSize.y));
    vertices[1].texCoords = sf::Vector2f((startIndexX * mSize.x) + (currentAnimationIndex * mSize.x) + mSize.x, (startIndexY * mSize.y) + (modifier * mSize.y));
    vertices[2].texCoords = sf::Vector2f((startIndexX * mSize.x) + (currentAnimationIndex * mSize.x) + mSize.x, (startIndexY * mSize.y) + mSize.y + (modifier * mSize.y));
    vertices[3].texCoords = sf::Vector2f((startIndexX * mSize.x) + (currentAnimationIndex * mSize.x), (startIndexY * mSize.y) + mSize.y + (modifier * mSize.y));
}

void Animation::setModifier(int x) {
    modifier = x;
}
