#ifndef IGAMEOBJECT_HPP_INCLUDED
#define IGAMEOBJECT_HPP_INCLUDED
#include "IDrawable.hpp"
#include "RectShape.hpp"

enum GameObjectType{
    edifice,
    projectile,
    circle,
    cprj,
    count
};

class IGameObject : public IDrawable, public RectShape{
protected:
    point          velocity = {0,0};
    bool           isAlive  = true;
    GameObjectType type     = count;
public:
    void kill();
    bool doesCollidesWith(IGameObject& another) const;
    virtual void collideWith(IGameObject& another) = 0;
    virtual void tick();

    point          getPosition() const;
    point          getVelocity() const;
    point          getDims()     const;
    bool           stillAlive()  const;
    GameObjectType getType()     const;
};

#endif // IGAMEOBJECT_HPP_INCLUDED
