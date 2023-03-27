#ifndef TRIGGER_HPP_INCLUDED
#define TRIGGER_HPP_INCLUDED
#include <SFML/Graphics/RectangleShape.hpp>
#include "IGameObject.hpp"

enum class TriggerType{
    L1_A1,
    L2_A1,
    count
};

class Trigger : public IGameObject{
private:
    sf::RectangleShape shape;
    bool debugMode = true;
protected:
    TriggerType tType = TriggerType::count;
public:
    Trigger(Game* _game, commonInitData data, TriggerType _type);
    TriggerType getTriggerType(){return tType;}
    void collideWith(IGameObject& another){}
    void draw();
};

#endif // TRIGGER_HPP_INCLUDED
