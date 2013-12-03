#include <iostream>
#include "SplashScreen.h"

SplashScreen::SplashScreen() {
    //ctor
}

SplashScreen::~SplashScreen() {
    //dtor
}

void SplashScreen::loadContent() {
    loaded = true;
}

void SplashScreen::unloadContent() {
    Screen::unloadContent();
}

void SplashScreen::update() {
    ScreenManager::getInstance().addScreen(new MainMenuScreen);
}

void SplashScreen::render(sf::RenderWindow &window) {
}
