#include "Game.hpp"
#include "Window.hpp"
#include "Edifice_L1.hpp"



void Game::init(){
    window.initWindow("Example", 1200, 700);
    theClock.restart();
    currentLevel->init();
}
