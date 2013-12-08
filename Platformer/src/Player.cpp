#include "Player.h"

Player::Player() {
    //ctor
}

Player::~Player() {
    //dtor
}

void Player::load(sf::Vector2f pos, sf::Texture &texture, float MAX_VEL) {
    Mob::load(pos, texture, MAX_VEL);

    vertices[0].position = sf::Vector2f(0, 0);
    vertices[1].position = sf::Vector2f(16, 0);
    vertices[2].position = sf::Vector2f(16, 16);
    vertices[3].position = sf::Vector2f(0, 16);
    vertices[0].texCoords = sf::Vector2f(0, 0);
    vertices[1].texCoords = sf::Vector2f(16, 0);
    vertices[2].texCoords = sf::Vector2f(16, 16);
    vertices[3].texCoords = sf::Vector2f(0, 16);

    setPosition(pos);
}

void Player::unload() {

}
