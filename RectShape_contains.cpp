#include "RectShape.hpp"

bool RectShape::contains(point p){
    bool xCondition = position.x <= p.x && p.x <= (position.x + dims.x);
    bool yCondition = position.y <= p.y && p.y <= (position.y + dims.y);
    return xCondition && yCondition;
}
