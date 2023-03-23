#include "Game.hpp"
#include "Window.hpp"
#include "Edifice.hpp"

const sf::Color EDIFICE_STD_COLOR   = sf::Color::Black;
const sf::Color EDIFICE_STD_OUT_CLR = sf::Color::White;
const float     EDIFICE_STD_OUT_WDT = 1.2f;

void Game::init(){
    window.initWindow("Example", 1200, 700);

    theClock.restart();

    auto edificeVData = visualData(EDIFICE_STD_COLOR, EDIFICE_STD_OUT_CLR, EDIFICE_STD_OUT_WDT);
    auto edificeIData = edificeInitData({70.f, 70.f}, {16.f, 16.f}, 30.f, 100.f, 1.f, 1.0f, 12.f);
    auto edifice = new Edifice(this, edificeVData, edificeIData);

    objects.push_back(edifice);
}
