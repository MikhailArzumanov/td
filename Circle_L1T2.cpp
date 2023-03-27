#include "Circle_L1T2.hpp"

const point CL1T2_DIMS = {23.f, 23.f};

const sf::Color CL1T2_FILL_CLR     = sf::Color::Black;
const sf::Color CL1T2_OUTLINE_CLR  = sf::Color::Red;
const float     CL1T2_OUTLINE_WDTH = 1.4f;
const visualData CL1T2_VDATA = visualData(CL1T2_FILL_CLR, CL1T2_OUTLINE_CLR, CL1T2_OUTLINE_WDTH);

const float CL1T2_HP  = 7.f;
const float CL1T2_DMG = 3.f;

const point CL1T2_V = {0.f, 4.f};

Circle_L1T2::Circle_L1T2(Game* game, point position)
    :Circle(game, commonInitData{position, CL1T2_DIMS}, CL1T2_VDATA, CL1T2_HP, CL1T2_DMG){
    velocity = CL1T2_V; cType = CircleType::L1T2;
}
