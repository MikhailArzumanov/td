#include "Game.hpp"

void Game::tick(){
    for(auto obj : objects)
        obj->tick();
}
