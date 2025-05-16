#include "game.hpp"

Game::Game()
    : window_(sf::VideoMode(920, 680), "Le Vin de la Mort") {
}

void Game::run() 
{
    while (window_.isOpen()) 
    {
        sf::Time deltaTime = clock_.restart();
        processEvents();
        update(deltaTime.asSeconds());
        render();
    }
}

void Game::processEvents() 
{
    sf::Event event;
    while (window_.pollEvent(event)) 
    {
        if (event.type == sf::Event::Closed)
        {
            window_.close();
        }
    }

    player_.handleInput();
}

void Game::update(float deltaTime) 
{
    player_.update(deltaTime);
}

void Game::render() 
{
    window_.clear(sf::Color::Black);
    player_.draw(window_);
    window_.display();
}
