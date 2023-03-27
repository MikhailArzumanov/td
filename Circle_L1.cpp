#include "Circle_L1.hpp"
#include "Trigger.hpp"
#include "Game.hpp"

Circle_L1::Circle_L1(Game* _game, commonInitData data, visualData vData, float hp, float dmg)
    :Circle(_game, data, vData, hp, dmg){}

void Circle_L1::onTriggerred(TriggerType type){
    switch(type){
    case TriggerType::L1_A1:
        game->lose();
        break;
    }
}
