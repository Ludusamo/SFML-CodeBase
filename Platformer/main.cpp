#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "ScreenManager.h"

int main() {
    // Window
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT, 32), "SFML Platformer");

    // Window Manager
    ScreenManager::getInstance().initialize();
    ScreenManager::getInstance().loadContent();

    // Timing
    sf::Clock clock;
    float delta;

    // Main Game Loop
    while (window.isOpen()) {
        sf::Event event;

        if (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Resets the Window
        window.clear();

        // Timing
        delta = clock.restart().asSeconds();
        std::cout << delta << std::endl;

        // Update and Render Cycles
        ScreenManager::getInstance().update(window, delta);
        ScreenManager::getInstance().render(window);

        // Just Displays the Screen
        window.display();
    }

    return 0;
}
