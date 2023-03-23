#include "Game.hpp"
#include "Circle_L1T1.hpp"
#include "Window.hpp"

int counter = 1;

const int L1_T1_TIMER = 120;

void Game::tick(){
    for(auto obj : objects)
        obj->tick();
    if(counter++ % L1_T1_TIMER == 0){
        auto circle = new Circle_L1T1(this, {100.f, 40.f});
        objects.push_back(circle);
    }
}
