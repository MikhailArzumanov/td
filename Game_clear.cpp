#include "Game.hpp"
#include "Window.hpp"

void Game::lose(){
    window->close();
}

void Game::clear(){
    for(auto obj : objects)
        delete obj;
    window.clear();
}
