#include "Circle_L1T1.hpp"

const point CL1T1_DIMS = {23.f, 23.f};

const sf::Color CL1T1_FILL_CLR     = sf::Color::Black;
const sf::Color CL1T1_OUTLINE_CLR  = sf::Color::White;
const float     CL1T1_OUTLINE_WDTH = 1.2f;
const visualData CL1T1_VDATA = visualData(CL1T1_FILL_CLR, CL1T1_OUTLINE_CLR, CL1T1_OUTLINE_WDTH);

const float CL1T1_HP  = 4.f;
const float CL1T1_DMG = 1.f;

const point CL1T1_V = {0.f, 4.f};

Circle_L1T1::Circle_L1T1(Game* _game, point _position)
        :Circle(_game, commonInitData{_position, CL1T1_DIMS}, CL1T1_VDATA, CL1T1_HP, CL1T1_DMG){
    velocity = CL1T1_V; cType = CircleType::L1T1;
}
