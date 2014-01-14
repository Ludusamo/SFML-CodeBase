#include "Screens/GameScreen.h"

GameScreen::GameScreen() {
    //ctor
}

GameScreen::~GameScreen() {
    //dtor
}

void GameScreen::loadContent() {
    level.load();
    level.loadLevel("res/imgs/Tilesheet_A.png", "bigger_level.png");

    if (level.getPlayer().getPosition().x - (WIDTH / SCALE / 2) < 0) center.x = (WIDTH / SCALE / 2);
    else if (level.getPlayer().getPosition().x + (WIDTH / SCALE / 2) > (level.getWidth() * TILE_SIZE)) center.x = (level.getWidth() * TILE_SIZE) - (WIDTH / SCALE / 2);
    else center.x = level.getPlayer().getPosition().x;
    if (level.getPlayer().getPosition().y - (HEIGHT / SCALE / 2) < 0) center.y = (HEIGHT / SCALE / 2);
    else if (level.getPlayer().getPosition().y + (HEIGHT / SCALE / 2) > (level.getHeight() * TILE_SIZE)) center.y = (level.getHeight() * TILE_SIZE) - (WIDTH / SCALE / 2);
    else center.y = level.getPlayer().getPosition().y;

    up.push_back(sf::Keyboard::Up);
    up.push_back(sf::Keyboard::W);
    down.push_back(sf::Keyboard::Down);
    down.push_back(sf::Keyboard::S);
    left.push_back(sf::Keyboard::Left);
    left.push_back(sf::Keyboard::A);
    right.push_back(sf::Keyboard::Right);
    right.push_back(sf::Keyboard::D);
}

void GameScreen::unloadContent() {
    level.unload();
}

void GameScreen::update(sf::Time delta) {
    level.update(delta);

    if (level.getPlayer().getPosition().x - (WIDTH / SCALE / 2) < 0) center.x = (WIDTH / SCALE / 2);
    else if (level.getPlayer().getPosition().x + (WIDTH / SCALE / 2) > (level.getWidth() * TILE_SIZE)) center.x = (level.getWidth() * TILE_SIZE) - (WIDTH / SCALE / 2);
    else center.x = level.getPlayer().getPosition().x;
    if (level.getPlayer().getPosition().y - (HEIGHT / SCALE / 2) < 0) center.y = (HEIGHT / SCALE / 2);
    else if (level.getPlayer().getPosition().y + (HEIGHT / SCALE / 2) > (level.getHeight() * TILE_SIZE)) center.y = (level.getHeight() * TILE_SIZE) - (HEIGHT / SCALE / 2);
    else center.y = level.getPlayer().getPosition().y;

    // Player movements
    if (input.keyPressed(up)) level.getPlayer().setAccelerationY(-2);
    else if (input.keyPressed(down)) level.getPlayer().setAccelerationY(2);
    else level.getPlayer().setAccelerationY(0);

    if (input.keyPressed(left)) level.getPlayer().setAccelerationX(-2);
    else if (input.keyPressed(right)) level.getPlayer().setAccelerationX(2);
    else level.getPlayer().setAccelerationX(0);

    // TEMPORARY
    if (input.keyPressed(sf::Keyboard::O)) level.switchTime(true);
    if (input.keyPressed(sf::Keyboard::P)) level.switchTime(false);
    if (input.keyPressed(sf::Keyboard::L)) level.saveLevel();
}

void GameScreen::render(sf::RenderWindow &window) {
    level.render(window);
    mainView = window.getDefaultView();
    mainView.zoom(1 / SCALE);
    mainView.setCenter(center);
    window.setView(mainView);
}
