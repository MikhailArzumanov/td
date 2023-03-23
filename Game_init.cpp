#include "Game.hpp"
#include "Window.hpp"
#include "Edifice.hpp"

const point     CRCL_DIMS          = {34.f, 34.f};

const sf::Color CIRCLE_FILL_COLOR    = sf::Color::Black;
const sf::Color CIRCLE_OUTLINE_COLOR = sf::Color::White;
const float     CIRCLE_OUTLINE_WIDTH = 1.2f;

const sf::Color EDIFICE_STD_COLOR   = sf::Color::Black;
const sf::Color EDIFICE_STD_OUT_CLR = sf::Color::White;
const float     EDIFICE_STD_OUT_WDT = 1.2f;

void Game::init(){
    window.initWindow("Example", 1200, 700);

    auto crclVData = visualData(CIRCLE_FILL_COLOR, CIRCLE_OUTLINE_COLOR, CIRCLE_OUTLINE_WIDTH);
    auto crclIData = commonInitData({0,0}, CRCL_DIMS);
    auto crcl    = new Circle(this, crclIData, crclVData, 12.f);

    auto edificeVData = visualData(EDIFICE_STD_COLOR, EDIFICE_STD_OUT_CLR, EDIFICE_STD_OUT_WDT);
    auto edificeIData = edificeInitData({70.f, 70.f}, {16.f, 16.f}, 1000.f, 100.f, 0.1f, 1.0f, 1.f);
    auto edifice = new Edifice(this, edificeVData, edificeIData);

    objects.push_back(edifice);
    objects.push_back(crcl);
}
