#include "Game.hpp"
#include "Circle_L1T1.hpp"
#include "Circle_L1T2.hpp"
#include "Window.hpp"


void Game::tick(){
    for(auto obj : objects)
        obj->tick();
    currentLevel->tick();
}
