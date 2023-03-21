#include "point.hpp"
#include <cmath>

point point::operator+(point another) const{
    return {x+another.x, y+another.y};
}
point point::operator-(point another) const{
    return {x-another.x, y-another.y};
}
point point::operator/(float scalar) const{
    return {x/scalar, y/scalar};
}

void point::operator/=(float scalar){
    x /= scalar; y /= scalar;
}
void point::operator*=(float scalar){
    x *= scalar; y *= scalar;
}
void point::operator+=(point another){
    x += another.x; y += another.y;
}

float point::getModule() const{
    return sqrt(x*x + y*y);
}
