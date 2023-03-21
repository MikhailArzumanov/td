#ifndef ISHAPE_HPP_INCLUDED
#define ISHAPE_HPP_INCLUDED
#include "point.hpp"

class IShape{
protected:
    point position;
public:
    virtual bool contains(point p) = 0;
};
#endif // ISHAPE_HPP_INCLUDED
