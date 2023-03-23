#include "Game.hpp"
#include "Window.hpp"

void Game::draw(){
    window->clear();
    for(auto obj : objects)
        obj->draw();
    window->display();
}
