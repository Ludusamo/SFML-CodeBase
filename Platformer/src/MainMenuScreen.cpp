#include <iostream>
#include "MainMenuScreen.h"

MainMenuScreen::MainMenuScreen() {
    //ctor
}

MainMenuScreen::~MainMenuScreen() {
    //dtor
}

void MainMenuScreen::loadContent() {
    if (!font.loadFromFile("res/fonts/Zenzai Itachi.ttf"))
        std::cout << "Could Not Find Specified Font." << std::endl;

    text.setFont(font);
    text.setString("MainMenuScreen");
    loaded = true;
}

void MainMenuScreen::unloadContent() {
    Screen::unloadContent();
}

void MainMenuScreen::update() {

}

void MainMenuScreen::render(sf::RenderWindow &window) {
    window.draw(text);
}
