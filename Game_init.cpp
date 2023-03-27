#include "Game.hpp"
#include "Window.hpp"
#include "Edifice_L1.hpp"

const sf::Color EDIFICE_STD_COLOR   = sf::Color::Black;
const sf::Color EDIFICE_STD_OUT_CLR = sf::Color::White;
const float     EDIFICE_STD_OUT_WDT = 1.2f;

void Game::init(){
    window.initWindow("Example", 1200, 700);
    theClock.restart();

    float x1 = 340.f, x2 = 480.f;
    for(float y = 120.f; y <= 480.f; y += 120.f){
        auto edifice = new Edifice_L1(this, {x1, y});
        objects.push_back(edifice);
        edifice = new Edifice_L1(this, {x2, y});
        objects.push_back(edifice);
    }
}
