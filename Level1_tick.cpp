#include "Level1.hpp"
#include "Circle_L1T1.hpp"
#include "Circle_L1T2.hpp"
#include "Game.hpp"

int l1T1Counter = 0;
int l1T2Counter = 0;

int l1T1Peak = 100;
int l1T2Peak = 1;

int l1T1Timer = 120;
int l1T2Timer = 12;


const float L1_CIRCLES_X = 410.f, L1_CIRCLES_Y = 0.f;

void Level1::tick(){
    if(++l1T1Counter % l1T1Timer == 0){
        l1T1Counter = 0;
        if(l1T1Timer > l1T1Peak)
            l1T1Timer--;
        if(++l1T2Counter % l1T2Timer == 0){
            l1T2Counter = 0;
            if(l1T2Timer > l1T2Peak)
                l1T2Timer--;
            auto circle = new Circle_L1T2(game, {L1_CIRCLES_X, L1_CIRCLES_Y});
            game->pushGameObject(circle);
        }
        else{
            auto circle = new Circle_L1T1(game, {L1_CIRCLES_X, L1_CIRCLES_Y});
            game->pushGameObject(circle);
        }
    }
}
