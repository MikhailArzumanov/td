#ifndef RECTSHAPE_HPP_INCLUDED
#define RECTSHAPE_HPP_INCLUDED
#include "IShape.hpp"

class RectShape : public IShape{
protected:
    point dims;
public:
    bool contains(point p);
};


#endif // RECTSHAPE_HPP_INCLUDED
