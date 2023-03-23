#include "Game.hpp"

void Game::encycle(){
    if(theClock.getElapsedTime().asSeconds()*60.f < 1.f)
        return;
    theClock.restart();
    handleEvents();
    lifeCheck();
    tick();
    collide();
    draw();
}
