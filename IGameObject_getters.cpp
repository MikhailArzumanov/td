#include "IGameObject.hpp"

point          IGameObject::getPosition() const { return position;}
point          IGameObject::getVelocity() const { return velocity;}
point          IGameObject::getDims()     const { return dims;    }
bool           IGameObject::stillAlive()  const { return isAlive; }
GameObjectType IGameObject::getType()     const { return type;    }

void IGameObject::kill() { isAlive = false; }
