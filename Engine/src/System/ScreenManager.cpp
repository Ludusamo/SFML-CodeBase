#include "System/ScreenManager.h"

Screen *currentScreen, *newScreen;

ScreenManager::ScreenManager() {
    //ctor
}

ScreenManager::~ScreenManager() {
    //dtor
}

ScreenManager &ScreenManager::getInstance() {
    static ScreenManager instance;
    return instance;
}

void ScreenManager::Transition(sf::RenderWindow &window) {
    if (transition) {
        fade.update(window);
        if (fade.getAlpha() >= 1.0f) {
            switchScreen();
            newScreen = nullptr;
        } else if (fade.getAlpha() <= 0.0f) {
            transition = false;
            fade.setActive(false);
        }
    }
}

void ScreenManager::addScreen(Screen *screen) {
    transition = true;
    newScreen = screen;
    fade.setActive(true);
    fade.setAlpha(0.0f);
}

void ScreenManager::initialize() {
    currentScreen = new SplashScreen();
    transition = false;
}

void ScreenManager::loadContent() {
    currentScreen->loadContent();

    sf::Texture tex;
    sf::Vector2f pos;
    fade.loadContent("", tex, pos);
    fade.setAlpha(0.1f);

    fadeBackground.setSize(sf::Vector2f(WIDTH, HEIGHT));
    fadeBackground.setFillColor(sf::Color(255, 255, 255));
}

void ScreenManager::switchScreen() {
    currentScreen->unloadContent();
    delete currentScreen;
    currentScreen = newScreen;
    currentScreen->loadContent();
}

void ScreenManager::update(sf::RenderWindow &window, sf::Time delta) {
    if (!transition) currentScreen->update(delta);
    else Transition(window);
}

void ScreenManager::render(sf::RenderWindow &window) {
    currentScreen->render(window);
    fadeBackground.setFillColor(sf::Color(0, 0, 0, 255 * ScreenManager::getInstance().getAlpha()));
    window.draw(fadeBackground);
}

float ScreenManager::getAlpha() {
    return fade.getAlpha();
}
