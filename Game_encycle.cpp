#include "Game.hpp"

void Game::encycle(){
    handleEvents();
    lifeCheck();
    tick();
    collide();
    draw();
}
