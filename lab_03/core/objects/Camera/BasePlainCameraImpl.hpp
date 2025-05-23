//
// Created by Roman Kanterov on 16.05.2025.
//

#ifndef BASEPLAINCAMERAIMPL_HPP
#define BASEPLAINCAMERAIMPL_HPP
#include "Vector.h"

#include <Point.hpp>

namespace core::objects
{
class BasePlainCameraImpl {
public:
    virtual Point getVisPoint() const = 0;
    virtual void setVisPoint(const Point &vis_point) = 0;
    virtual Vector<double> getN() const = 0;
    virtual void set_n(const Vector<double> &n) = 0;
    virtual ~BasePlainCameraImpl();
};
}



#endif //BASEPLAINCAMERAIMPL_HPP
