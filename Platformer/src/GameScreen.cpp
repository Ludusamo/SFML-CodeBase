#include "GameScreen.h"

GameScreen::GameScreen() {
    //ctor
}

GameScreen::~GameScreen() {
    //dtor
}

void GameScreen::loadContent() {
    level.loadLevel("res/imgs/Tilesheet_A.png", "res/lvls/test.lvl");
    up.push_back(sf::Keyboard::Up);
    up.push_back(sf::Keyboard::W);
    down.push_back(sf::Keyboard::Down);
    down.push_back(sf::Keyboard::S);
    left.push_back(sf::Keyboard::Left);
    left.push_back(sf::Keyboard::A);
    right.push_back(sf::Keyboard::Right);
    right.push_back(sf::Keyboard::D);

}

void GameScreen::unloadContent() {
    level.unload();
}

void GameScreen::update() {
    level.update();
    if (input.keyPressed(up)) level.getPlayer().setAccelerationY(-2);
    else if (input.keyPressed(down)) level.getPlayer().setAccelerationY(2);
    else level.getPlayer().setAccelerationY(0);

    if (input.keyPressed(left)) level.getPlayer().setAccelerationX(-2);
    else if (input.keyPressed(right)) level.getPlayer().setAccelerationX(2);
    else level.getPlayer().setAccelerationX(0);
}

void GameScreen::render(sf::RenderWindow &window) {
    level.render(window);
}
