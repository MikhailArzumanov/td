#include "Game.hpp"
#include "Window.hpp"

int main(){
    auto game = Game();
    while(window->isOpen())
        game.encycle();
    game.clear();
    return 0;
}
