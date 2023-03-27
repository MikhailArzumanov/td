#include "Game.hpp"

void Game::changeLevel(LevelsEnum level){
    clear();
    currentLevel = levelsMap[level];
    init();
}
