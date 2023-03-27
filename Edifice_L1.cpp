#include "Edifice_L1.hpp"

const visualData EDIFICE_L1T1_VDATA = visualData(sf::Color::Black, sf::Color::White, 1.2);


const point EDIFICE_L1_DIMS = {16.f,16.f};

const float EDIFICE_L1T1_ATKSPEED = 12.f;

const float EDIFICE_L1T1_RANGE = 70.f;

const float EDIFICE_L1T1_DMG = 1.2f;

const float EDIFICE_L1T1_HP  = 12.f;

const float EDIFICE_L1T1_PRJSPEED = 34.f;

const int EDIFICE_L1_MXLEVEL = 4;

Edifice_L1::Edifice_L1(Game* game, point position):
    Edifice(game, EDIFICE_L1T1_VDATA, edificeInitData(position,
    EDIFICE_L1_DIMS, EDIFICE_L1T1_ATKSPEED, EDIFICE_L1T1_RANGE,
    EDIFICE_L1T1_DMG, EDIFICE_L1T1_HP, EDIFICE_L1T1_PRJSPEED),
    EDIFICE_L1_MXLEVEL){
    eType = EdificeType::L1;
}
