#include "IGameObject.hpp"

bool IGameObject::doesCollidesWith(IGameObject& another) const{
    point aD = another.getDims(), d = dims;
    point aP = another.getPosition(), p = position;
    bool vCondition =  p.y <= aP.y && p.y+d.y >= aP.y
                    || p.y >= aP.y && p.y <= aP.y+aD.y;
    bool hCondition =  p.x <= aP.x && p.x+d.x >= aP.x
                    || p.x >= aP.x && p.x <= aP.x+aD.x;
    return vCondition && hCondition;
}
