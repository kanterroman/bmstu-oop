//
// Created by Roman Kanterov on 18.05.2025.
//

#ifndef PLAINCAMERABUFFER_HPP
#define PLAINCAMERABUFFER_HPP
#include "Vector/Vector/Vector.h"

#include <Point.hpp>

namespace core {
namespace creators {
namespace buffers {

class CameraBuffer {
private:
    Point visPoint{};
    Vector<double> n{3};
public:
    void addPoint(const Point &pt);
    void addNormal(const Vector<double> &n);
    Point readPoint() const;
    Vector<double> readNormal();
};

} // buffers
} // creators
} // core

#endif //PLAINCAMERABUFFER_HPP
