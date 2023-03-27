#ifndef CIRCLE_HPP_INCLUDED
#define CIRCLE_HPP_INCLUDED
#include "IGameObject.hpp"
#include <SFML/Graphics/CircleShape.hpp>

enum class CircleType{
    L1T1,
    L1T2,
    L1T3,
    count
};

class Circle : public IGameObject{
protected:
    sf::CircleShape shape;
    float hp; float dmg;
    CircleType cType = CircleType::count;
    virtual void onTriggerred(TriggerType type);
public:
    Circle(Game* _game, commonInitData data, visualData vData, float _hp, float _dmg);
    virtual void collideWith(IGameObject& another);
    virtual void tick();
    virtual void draw();
};


#endif // CIRCLE_HPP_INCLUDED
