//
// Created by Roman Kanterov on 15.05.2025.
//

#include "PlainCameraImpl.hpp"

namespace core {
namespace objects {
Point PlainCameraImpl::getVisPoint() const
{
    return visPoint;
}

void PlainCameraImpl::setVisPoint(const Point &vis_point)
{
    visPoint = vis_point;
}

Vector<double> PlainCameraImpl::getN() const
{
    return Vector(n);
}

void PlainCameraImpl::set_n(const Vector<double> &n)
{
    this->n = n;
}
} // objects
} // core