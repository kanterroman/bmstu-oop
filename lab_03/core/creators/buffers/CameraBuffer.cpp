//
// Created by Roman Kanterov on 18.05.2025.
//

#include "CameraBuffer.hpp"

namespace core {
namespace creators {
namespace buffers {
void CameraBuffer::addPoint(const Point &pt)
{
    visPoint = pt;
}

void CameraBuffer::addNormal(const Vector<double> &n)
{
    this->n = n;
}

Point CameraBuffer::readPoint() const
{
    return visPoint;
}

Vector<double> CameraBuffer::readNormal()
{
    return Vector(n);
}
} // buffers
} // creators
} // core