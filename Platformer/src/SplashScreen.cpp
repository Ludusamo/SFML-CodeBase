#include <iostream>
#include "SplashScreen.h"

SplashScreen::SplashScreen() {
    //ctor
}

SplashScreen::~SplashScreen() {
    //dtor
}

void SplashScreen::loadContent() {
    if (!font.loadFromFile("Zenzai Itachi.ttf"))
        std::cout << "Could Not Find Specified Font." << std::endl;

    text.setFont(font);
    text.setString("SplashScreen");
    keys.push_back(sf::Keyboard::Z);
    keys.push_back(sf::Keyboard::Return);
}

void SplashScreen::unloadContent() {
    Screen::unloadContent();
}

void SplashScreen::update(float delta) {
    if (input.keyPressed(keys))
        ScreenManager::getInstance().addScreen(new MainMenuScreen);
}

void SplashScreen::render(sf::RenderWindow &window) {
    window.draw(text);
}
