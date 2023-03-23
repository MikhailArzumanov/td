#ifndef POINT_HPP_INCLUDED
#define POINT_HPP_INCLUDED

struct point{
    float x, y;
    point operator+(point another) const;
    point operator-(point another) const;
    point operator/(float scalar)  const;

    void operator+=(point another);
    void operator/=(float scalar);
    void operator*=(float scalar);

    float getModule() const;
    float getSqrModule() const;
};


#endif // POINT_HPP_INCLUDED
