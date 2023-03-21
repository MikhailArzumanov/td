#ifndef CIRCLE_HPP_INCLUDED
#define CIRCLE_HPP_INCLUDED
#include "IGameObject.hpp"
#include <SFML/Graphics/CircleShape.hpp>

class Circle : public IGameObject{
private:
    sf::CircleShape shape;
    int hp;
public:
    Circle(point _position);
    void collideWith(IGameObject& another);
    void tick();
    void draw();
};


#endif // CIRCLE_HPP_INCLUDED
