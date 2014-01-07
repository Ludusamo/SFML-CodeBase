#include "Entity/Player.h"

Player::Player() {
    //ctor
}

Player::~Player() {
    //dtor
}

void Player::load(sf::Vector2f pos, sf::Texture &texture, float MAX_VEL, sf::Vector2i mSize) {
    Mob::load(pos, texture, MAX_VEL, mSize);

    vertices[0].position = sf::Vector2f(0, 0);
    vertices[1].position = sf::Vector2f(mSize.x, 0);
    vertices[2].position = sf::Vector2f(mSize.x, mSize.y);
    vertices[3].position = sf::Vector2f(0, mSize.y);
    vertices[0].texCoords = sf::Vector2f(0, 0);
    vertices[1].texCoords = sf::Vector2f(mSize.x, 0);
    vertices[2].texCoords = sf::Vector2f(mSize.x, mSize.y);
    vertices[3].texCoords = sf::Vector2f(0, mSize.y);

    animation.load(0, 0, 3, .2);
}

void Player::unload() {

}
