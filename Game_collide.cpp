#include "Game.hpp"

void Game::collide(){
    for(auto objL = objects.begin();  objL != objects.end(); objL++)
    for(auto objR = std::next(objL,1);objR != objects.end(); objR++)
    if((*objL)->doesCollidesWith(**objR)){
        (*objL)->collideWith(**objR);
        (*objR)->collideWith(**objL);
    }
}
