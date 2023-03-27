#include "Level1.hpp"
#include "Edifice_L1.hpp"
#include "Game.hpp"

Level1::Level1(Game* game): Level(game){
    level = LevelsEnum::First;
}


const float L1_EDIFICIES_LEFT_LINE_X  = 340.f;
const float L1_EDIFICIES_RIGHT_LINE_X = 480.f;

const float L1_EDIFICIES_Y_START = 120.f;
const float L1_EDIFICIES_Y_END   = 480.f;
const float L1_EDIFICIES_Y_STEP  = 120.f;

void Level1::init(){
    float x1 = L1_EDIFICIES_LEFT_LINE_X,
          x2 = L1_EDIFICIES_RIGHT_LINE_X;
    for(float y = L1_EDIFICIES_Y_START; y <= L1_EDIFICIES_Y_END;
         y += L1_EDIFICIES_Y_STEP){
        auto edifice = new Edifice_L1(game, {x1, y});
        game->pushGameObject(edifice);
        edifice = new Edifice_L1(game, {x2, y});
        game->pushGameObject(edifice);
    }
}
