#include "GUI/Button.h"

Button::Button()
{
    //ctor
}

Button::~Button()
{
    //dtor
}

void Button::load(const std::string& message, sf::Vector2f pos, const sf::Texture& sprites, const sf::Font& font) {
    this->pos = pos;
    this->sprites = sprites;
    this->font = font;
    msg = message;
    this->message.setString(message);
    this->message.setFont(font);
    this->message.setPosition(pos.x + 32, pos.y);
    this->message.setColor(sf::Color::Black);

    vertices.setPrimitiveType(sf::Quads);
    vertices.resize((message.length() + 2) * 4);
    sf::Vertex* quad = &vertices[0];
    quad[0].position = sf::Vector2f(pos.x, pos.y);
    quad[1].position = sf::Vector2f(pos.x + 32, pos.y);
    quad[2].position = sf::Vector2f(pos.x + 32, pos.y + 32);
    quad[3].position = sf::Vector2f(pos.x, pos.y + 32);
    quad[0].texCoords = sf::Vector2f(0, 0);
    quad[1].texCoords = sf::Vector2f(32, 0);
    quad[2].texCoords = sf::Vector2f(32, 32);
    quad[3].texCoords = sf::Vector2f(0, 32);
    for (int i = 1; i < message.length() + 1; i++) {
        quad = &vertices[i * 4];
        quad[0].position = sf::Vector2f(pos.x + (32 * i), pos.y);
        quad[1].position = sf::Vector2f(pos.x + (32 * i) + 32, pos.y);
        quad[2].position = sf::Vector2f(pos.x + (32 * i) + 32, pos.y + 32);
        quad[3].position = sf::Vector2f(pos.x + (32 * i), pos.y + 32);
        quad[0].texCoords = sf::Vector2f(32, 0);
        quad[1].texCoords = sf::Vector2f(64, 0);
        quad[2].texCoords = sf::Vector2f(64, 32);
        quad[3].texCoords = sf::Vector2f(32, 32);
    }
    quad = &vertices[(message.length() + 1) * 4];
    quad[0].position = sf::Vector2f(pos.x + (32 * (message.length() + 1)), pos.y);
    quad[1].position = sf::Vector2f(pos.x + (32 * (message.length() + 1)) + 32, pos.y);
    quad[2].position = sf::Vector2f(pos.x + (32 * (message.length() + 1)) + 32, pos.y + 32);
    quad[3].position = sf::Vector2f(pos.x + (32 * (message.length() + 1)), pos.y + 32);
    quad[0].texCoords = sf::Vector2f(64, 0);
    quad[1].texCoords = sf::Vector2f(96, 0);
    quad[2].texCoords = sf::Vector2f(96, 32);
    quad[3].texCoords = sf::Vector2f(64, 32);

    bounds.left = pos.x;
    bounds.top = pos.y;
    bounds.width = (message.length() + 2) * 32;
    bounds.height = 32;
}

void Button::unload() {
    Entity::unload();
}

void Button::update(sf::Vector2i p) {
    if (bounds.contains(p.x, p.y)) {
        change = 1;
        highlight(change);
    } else if (change == 1 && !bounds.contains(p.x, p.y)){
        change = 0;
        highlight(change);
    }
}

void Button::highlight(int change) {
    sf::Vertex* quad = &vertices[0];
    quad[0].texCoords = sf::Vector2f(0, change * 32);
    quad[1].texCoords = sf::Vector2f(32, change * 32);
    quad[2].texCoords = sf::Vector2f(32, (1 + change) * 32);
    quad[3].texCoords = sf::Vector2f(0, (1 + change) * 32);
    for (int i = 1; i < msg.length() + 1; i++) {
        quad = &vertices[i * 4];
        quad[0].texCoords = sf::Vector2f(32, change * 32);
        quad[1].texCoords = sf::Vector2f(64, change * 32);
        quad[2].texCoords = sf::Vector2f(64, (1 + change) * 32);
        quad[3].texCoords = sf::Vector2f(32, (1 + change) * 32);
    }
    quad = &vertices[(msg.length() + 1) * 4];
    quad[0].texCoords = sf::Vector2f(64, change * 32);
    quad[1].texCoords = sf::Vector2f(96, change * 32);
    quad[2].texCoords = sf::Vector2f(96, (1 + change) * 32);
    quad[3].texCoords = sf::Vector2f(64, (1 + change) * 32);
}
