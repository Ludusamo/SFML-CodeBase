#include "Mob.h"

Mob::Mob() {
    //ctor
}

Mob::~Mob() {
    //dtor
}

void Mob::load(sf::Vector2f pos, sf::Texture &texture, float MAX_VEL, sf::Vector2i mSize) {
    this->MAX_VEL = MAX_VEL;
    this->mSize = mSize;
    setPosition(pos);

    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(4);
    tex = texture;

    bounds.top = getPosition().y / 32;
    bounds.left = getPosition().x / 32;
    bounds.width = mSize.x / 32;
    bounds.height = mSize.y / 32;
}

void Mob::unload() {
    vertices.clear();
}

void Mob::update(std::vector<std::vector<int>> colMap) {
    moveM(colMap);
}

void Mob::moveM(std::vector<std::vector<int>> colMap) {
    velocity += acceleration;
    checkCollision(colMap);
    velocity.x *= FRICTION;
    velocity.y *= FRICTION;
    if (velocity.x > MAX_VEL) velocity.x = MAX_VEL;
    if (velocity.x < -MAX_VEL) velocity.x = -MAX_VEL;
    if (velocity.y > MAX_VEL) velocity.y = MAX_VEL;
    if (velocity.y < -MAX_VEL) velocity.y = -MAX_VEL;
}

void Mob::checkCollision(std::vector<std::vector<int>> colMap) {
    collision = bounds;

    // Checking x-axis
    if (velocity.x < 0) startX = endX = (int) floor(bounds.left
            + (velocity.x / 32));
    else startX = endX = (int) floor(bounds.left + bounds.width
            + (velocity.x / 32));
    startY = (int) (bounds.top);
    endY = (int) (bounds.top + bounds.height);

    collidableTiles(colMap, startX, endX, startY, endY);

//    for (int i = 0; i < collidable.size(); i++) {
//        std::cout << collidable[i].left << " " << bounds.left << std::endl;
//    }

    collision.left += velocity.x / 32;
    for (unsigned int i = 0; i < collidable.size(); i++) {
        if (collision.top < collidable[i].top + collidable[i].height || collision.top + collision.height > collidable[i].top
                || collision.left < collidable[i].left + collidable[i].width || collision.left + collision.width > collidable[i].left) {
            setVelocityX(0);
            break;
        }
    }
    collision.left = getPosition().x;

    // Checking y-axis
    startX = (int) bounds.left;
    endX = (int) (bounds.left + bounds.width);
    if (velocity.y < 0) startY = endY = (int) floor(bounds.top
            + (velocity.y / 32));
    else startY = endY = (int) floor(bounds.top + bounds.height
            + (velocity.y / 32));

    collidableTiles(colMap, startX, endX, startY, endY);

    collision.top += velocity.y / 32;
    for (unsigned int i = 0; i < collidable.size(); i++) {
        if (collision.top < collidable[i].top + collidable[i].height || collision.top + collision.height > collidable[i].top
                || collision.left < collidable[i].left + collidable[i].width || collision.left + collision.width > collidable[i].left) {
            setVelocityY(0);
            break;
        }
    }
    collision.top = getPosition().y;

    std::cout << velocity.x << std::endl;

    move(velocity);
    bounds.left = getPosition().x / 32;
    bounds.top = getPosition().y / 32;
}

void Mob::collidableTiles(std::vector<std::vector<int>> colMap, int startX, int endX, int startY, int endY) {
    collidable.clear();
    for (int y = startY; y <= endY; y++) {
        for (int x = startX; x <= endX; x++) {
            if (colMap[y][x] == 1) {
                collidable.push_back(sf::FloatRect(x, y, 1, 1));
            }
        }
    }
}

void Mob::setAccelerationX(float a) {
    acceleration.x = a;
}

void Mob::setAccelerationY(float a) {
    acceleration.y = a;
}

void Mob::setVelocityX(float v) {
    velocity.x = v;
}

void Mob::setVelocityY(float v) {
    velocity.y = v;
}
