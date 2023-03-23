#ifndef CIRCLE_HPP_INCLUDED
#define CIRCLE_HPP_INCLUDED
#include "IGameObject.hpp"
#include <SFML/Graphics/CircleShape.hpp>

class Circle : public IGameObject{
protected:
    sf::CircleShape shape;
    float hp;
public:
    Circle(Game* _game, commonInitData data, visualData vData, float _hp);
    virtual void collideWith(IGameObject& another);
    virtual void tick();
    virtual void draw();
};


#endif // CIRCLE_HPP_INCLUDED
