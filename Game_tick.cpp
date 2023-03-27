#include "Game.hpp"
#include "Circle_L1T1.hpp"
#include "Window.hpp"

int counter = 1;

const int L1_T1_TIMER = 120;

const float L1_CIRCLES_X = 410.f, L1_CIRCLES_Y = 0.f;

void Game::tick(){
    for(auto obj : objects)
        obj->tick();
    if(counter++ % L1_T1_TIMER == 0){
        auto circle = new Circle_L1T1(this, {L1_CIRCLES_X, L1_CIRCLES_Y});
        objects.push_back(circle);
    }
}
