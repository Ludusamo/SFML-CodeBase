#include <iostream>
#include "Screens/MainMenuScreen.h"

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

    sf::Texture tex1;
    tex1.loadFromFile("res/imgs/player.png");
    b.load(sf::Vector2f(320, 500), tex1, sf::Vector2f(0, 0), sf::Vector2f(64, 32));

    if (tex.loadFromFile("res/imgs/TitleScreen.png")) std::cout << "success";
    main.load(sf::Vector2f(0,0), sf::Vector2f(640,640), tex);
    main.addButton(b);
    components.push_back(main);

    std::cout << components[0].getButtons().size() << std::endl;
}

void MainMenuScreen::unloadContent() {
    Screen::unloadContent();
}

void MainMenuScreen::update(sf::Time &delta) {
    Screen::update(delta);
    if (input.keyPressed(confirm))
        ScreenManager::getInstance().addScreen(new GameScreen);
}

void MainMenuScreen::render(sf::RenderWindow &window) {
    Screen::render(window);
    window.draw(text);
}
