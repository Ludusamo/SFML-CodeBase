#include "GameScreen.h"

GameScreen::GameScreen() {
    //ctor
}

GameScreen::~GameScreen() {
    //dtor
}

void GameScreen::loadContent() {
    std::cout << "Loading GameScreen" << std::endl;
    if (!font.loadFromFile("res/fonts/Zenzai Itachi.ttf"))
        std::cout << "Could Not Find Specified Font." << std::endl;

    text.setFont(font);
    text.setString("GameScreen");

    level.loadLevel("res/imgs/Tilesheet_A.png", "res/lvls/test.lvl", 5, 5);
}

void GameScreen::unloadContent() {

}

void GameScreen::update() {

}

void GameScreen::render(sf::RenderWindow &window) {
    window.draw(text);
    level.render(window);
}
