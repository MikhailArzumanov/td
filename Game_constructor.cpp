#include "Game.hpp"
#include "Level1.hpp"

void Game::initLevelsMap(){
    levelsMap[LevelsEnum::First] = new Level1(this);
}

Game::Game(){
    initLevelsMap();
    currentLevel = levelsMap[LevelsEnum::First];
    init();
}
