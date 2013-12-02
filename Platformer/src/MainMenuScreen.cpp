#include <iostream>
#include "MainMenuScreen.h"

MainMenuScreen::MainMenuScreen() {
    //ctor
}

MainMenuScreen::~MainMenuScreen() {
    //dtor
}

void MainMenuScreen::loadContent() {
    if (!font.loadFromFile("Zenzai Itachi.ttf"))
        std::cout << "Could Not Find Specified Font." << std::endl;

    text.setFont(font);
    text.setString("MainMenuScreen");
    keys.push_back(sf::Keyboard::Z);
    keys.push_back(sf::Keyboard::Return);
}

void MainMenuScreen::unloadContent() {
    Screen::unloadContent();
}

void MainMenuScreen::update(sf::Event event) {
    input.update(event);

    if (input.keyPressed(keys))
        ScreenManager::getInstance().addScreen(new SplashScreen);
}

void MainMenuScreen::render(sf::RenderWindow &window) {
    window.draw(text);
}
