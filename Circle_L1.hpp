#ifndef CIRCLE_L1_HPP_INCLUDED
#define CIRCLE_L1_HPP_INCLUDED
#include "Circle.hpp"

class Circle_L1 : public Circle{
protected:
    Circle_L1(Game* _game, commonInitData data, visualData vData, float hp, float dmg);
    void onTriggerred(TriggerType type);
};

#endif // CIRCLE_L1_HPP_INCLUDED
