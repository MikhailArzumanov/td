#ifndef PROJECTILE_HPP_INCLUDED
#define PROJECTILE_HPP_INCLUDED
#include "IGameObject.hpp"
#include <SFML/Graphics/RectangleShape.hpp>

struct projectileInitData : public commonInitData{
    point target; float vModule, dmg;
    projectileInitData(point _position, point _dims, point _target, float _vModule, float _dmg)
        :commonInitData(_position, _dims){
        target = _target; vModule = _vModule; dmg = _dmg;
    }
};

class Projectile : public IGameObject{
private:
    sf::RectangleShape shape;
    float dmg;
public:
    Projectile(Game* _game, visualData vData , projectileInitData data);
    void collideWith(IGameObject& another);
    void draw();
    float getDmg() const;
};


#endif // PROJECTILE_HPP_INCLUDED
