#include "Game.hpp"

void Game::lifeCheck(){
    for(auto obj = objects.begin(); obj != objects.end();)
    if(!(*obj)->stillAlive()){
        auto tmp = obj;
        obj++;
        objects.erase(tmp);
    }
    else obj++;
}
