#include "Entity/Mob.h"

Mob::Mob() {
    //ctor
}

Mob::~Mob() {
    //dtor
}

void Mob::load(sf::Vector2f pos, sf::Texture &texture, float MAX_VEL, sf::Vector2i mSize) {
    Entity::load(pos, texture);
    this->MAX_VEL = MAX_VEL;
    this->mSize = mSize;
    setPosition(pos);

    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(4);
    tex = texture;

    bounds.top = getPosition().y;
    bounds.left = getPosition().x;
    bounds.width = mSize.x;
    bounds.height = mSize.y;
}

void Mob::unload() {
    vertices.clear();
}

void Mob::update(std::vector<std::vector<int>> colMap, sf::Time delta) {
    moveM(colMap, delta);

    if (acceleration.y < 0) {
        animation.setModifier(UP);
        animation.update(vertices, mSize, delta);
    } else if (acceleration.y > 0) {
        animation.setModifier(DOWN);
        animation.update(vertices, mSize, delta);
    }

    if (acceleration.x < 0) {
        animation.setModifier(LEFT);
        animation.update(vertices, mSize, delta);
    } else if (acceleration.x > 0) {
        animation.setModifier(RIGHT);
        animation.update(vertices, mSize, delta);
    }
}

void Mob::moveM(std::vector<std::vector<int>> colMap, sf::Time delta) {
    velocity += acceleration;
    checkCollision(colMap, delta);
}

void Mob::checkCollision(std::vector<std::vector<int>> colMap, sf::Time delta) {
    collision = bounds;

    // Checking x-axis
    if (velocity.x < 0) startX = endX = (int) floor(bounds.left + (velocity.x));
    else startX = endX = (int) floor(bounds.left + bounds.width + (velocity.x));
    startY = (int) (bounds.top);
    endY = (int) (bounds.top + bounds.height);

    collidableTiles(colMap, startX, endX, startY, endY);

    collision.left += velocity.x;
    for (unsigned int i = 0; i < collidable.size(); i++) {
        if (contains(collision, collidable[i])) {
            setVelocityX(0);
            break;
        }
    }
    collision.left = getPosition().x;

    // Checking y-axis
    startX = (int) bounds.left;
    endX = (int) (bounds.left + bounds.width);
    if (velocity.y < 0) startY = endY = (int) floor(bounds.top + (velocity.y));
    else startY = endY = (int) floor(bounds.top + bounds.height + (velocity.y));

    collidableTiles(colMap, startX, endX, startY, endY);

    collision.top += velocity.y;
    for (unsigned int i = 0; i < collidable.size(); i++) {
        if (collision.top < collidable[i].top + collidable[i].height || collision.top + collision.height > collidable[i].top
                || collision.left < collidable[i].left + collidable[i].width || collision.left + collision.width < collidable[i].left) {
            setVelocityY(0);
            break;
        }
    }
    collision.top = getPosition().y;

    velocity.x *= FRICTION;
    velocity.y *= FRICTION;
    if (velocity.x > MAX_VEL) velocity.x = MAX_VEL;
    if (velocity.x < -MAX_VEL) velocity.x = -MAX_VEL;
    if (velocity.y > MAX_VEL) velocity.y = MAX_VEL;
    if (velocity.y < -MAX_VEL) velocity.y = -MAX_VEL;

    move(velocity);
    bounds.left = getPosition().x;
    bounds.top = getPosition().y;
}

void Mob::collidableTiles(std::vector<std::vector<int>> colMap, int startX, int endX, int startY, int endY) {
    collidable.clear();
    for (int y = startY / 32; y <= endY / 32; y++) {
        for (int x = startX / 32; x <= endX / 32; x++) {
            if (colMap[y][x] == 1) {
                collidable.push_back(sf::FloatRect(x, y, 1, 1));
            }
        }
    }
}

Animation &Mob::getAnimation() {
    return animation;
}

bool Mob::contains(sf::FloatRect x, sf::FloatRect y) {
    if (x.top < y.top + y.height || x.top + x.height > y.top || x.left < y.left + y.width || x.left + x.width > y.left)
        return true;
    return false;
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

void Mob::addAcceleration(sf::Vector2f v) {
    acceleration += v;
}
