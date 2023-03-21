#ifndef PROJECTILE_HPP_INCLUDED
#define PROJECTILE_HPP_INCLUDED
#include "IGameObject.hpp"
#include <SFML/Graphics/RectangleShape.hpp>

class Projectile : public IGameObject{
private:
    sf::RectangleShape shape;
    float dmg;
public:
    Projectile(point _position, point target, float vModule, float _dmg);
    void collideWith(IGameObject& another);
    void draw();
    float getDmg() const;
};


#endif // PROJECTILE_HPP_INCLUDED
