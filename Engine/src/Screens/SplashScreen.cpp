#include <iostream>
#include "Screens/SplashScreen.h"

SplashScreen::SplashScreen() {
    //ctor
}

SplashScreen::~SplashScreen() {
    //dtor
}

void SplashScreen::loadContent() {
    if (!logoT.loadFromFile("res/imgs/LogoV1.png", sf::IntRect(0, 0, 500, 500)))
        std::cout << "Unable to load logo." << std::endl;
    logoT.setSmooth(true);
    logo.setTexture(logoT);
    logo.setPosition(sf::Vector2f((WIDTH / 2) - (250), (HEIGHT / 2) - (250)));
}

void SplashScreen::unloadContent() {
    Screen::unloadContent();
}

void SplashScreen::update(sf::Time &delta) {
    Screen::update(delta);
    elapsed += delta;
    if (elapsed.asSeconds() >= 2) {
        ScreenManager::getInstance().addScreen(new MainMenuScreen);
    }
}

void SplashScreen::render(sf::RenderWindow &window) {
    Screen::render(window);
    window.draw(logo);
}
