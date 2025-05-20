#ifndef POINT_HPP
#define POINT_HPP

namespace core {

struct Point {
    double x;
    double y;
    double z;

    Point operator+(const Point &p) const
    {
        Point pt(*this);
        pt.x += p.x;
        pt.y += p.y;
        pt.z += p.z;
        return pt;
    }
    Point &operator+=(const Point &p)
    {
        this->x += p.x;
        this->y += p.y;
        this->z += p.z;
        return *this;
    }
    Point operator/(double div) const
    {
        Point pt(*this);
        pt.x /= div;
        pt.y /= div;
        pt.z /= div;
        return pt;
    }
    Point &operator/=(double div)
    {
        this->x /= div;
        this->y /= div;
        this->z /= div;
        return *this;
    }
    Point &operator-()
    {
        this->x *= -1;
        this->y *= -1;
        this->z *= -1;
        return *this;
    }
    Point operator*(double mul) const
    {
        Point pt(*this);
        pt.x *= mul;
        pt.y *= mul;
        pt.z *= mul;
        return pt;
    }
    Point &operator*=(double mul)
    {
        this->x *= mul;
        this->y *= mul;
        this->z *= mul;
        return *this;
    }

    bool operator==(const Point & p) const
    {
        return (this->x == p.x && this->y == p.y && this->z == p.z);
    }
};

} // core

#endif //POINT_HPP
