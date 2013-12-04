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

    confirm.push_back(sf::Keyboard::Return);
    confirm.push_back(sf::Keyboard::Space);
}

void MainMenuScreen::unloadContent() {
    Screen::unloadContent();
}

void MainMenuScreen::update() {
    if (input.keyPressed(confirm))
        ScreenManager::getInstance().addScreen(new GameScreen);
}

void MainMenuScreen::render(sf::RenderWindow &window) {
    window.draw(text);
}
