#include "Game.hpp"
#include "Window.hpp"
#include <SFML/Window/Event.hpp>

void Game::processMbPressed(sf::Event event){
    point p = {event.mouseButton.x, event.mouseButton.y};
    for(IGameObject* obj : objects)
        if(obj->contains(p))
            obj->onMouseClick(event);
}

void Game::processMouseMoved(sf::Event event){
    for(IGameObject* obj : objects)
        obj->onMouseMove(event);
}

void Game::processKeyPressed(sf::Event event){
    //...
}

void Game::handleEvents(){
    sf::Event event;
    while(window->pollEvent(event)){
        switch(event.type){
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::KeyPressed:
            processKeyPressed(event);
            break;
        case sf::Event::MouseButtonPressed:
            processMbPressed(event);
            break;
        case sf::Event::MouseMoved:
            processMouseMoved(event);
            break;
        }
    }
}
