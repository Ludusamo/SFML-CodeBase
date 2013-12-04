#include "GameScreen.h"

GameScreen::GameScreen() {
    //ctor
}

GameScreen::~GameScreen() {
    //dtor
}

void GameScreen::loadContent() {
    if (!font.loadFromFile("res/fonts/Zenzai Itachi.ttf"))
        std::cout << "Could Not Find Specified Font." << std::endl;

    text.setFont(font);
    text.setString("GameScreen");
}

void GameScreen::unloadContent() {

}

void GameScreen::update() {

}

void GameScreen::render(sf::RenderWindow &window) {
    window.draw(text);
}
