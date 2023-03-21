#include "IGameObject.hpp"

const float V_COEF = 12.f;

void IGameObject::tick(){
    position += velocity/V_COEF;
}
