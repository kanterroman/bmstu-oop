//
// Created by Roman Kanterov on 18.05.2025.
//

#ifndef PLAINCAMERABUFFER_HPP
#define PLAINCAMERABUFFER_HPP
#include "ConstIterator.hpp"
#include "Iterator.hpp"
#include "Vector.hpp"
#include "ReverseIterator.h"
#include "ConstReverseIterator.h"
#include "ConstReverseIterator.hpp"
#include "ReverseIterator.hpp"

#include <Point.hpp>

namespace core {
namespace creators {
namespace buffers {

class CameraBuffer {
public:
    void addPoint(const Point &pt);
    void addNormal(const Vector<double> &n);
    Point readPoint() const;
    Vector<double> readNormal();
private:
    Point visPoint{};
    Vector<double> n{3};
};

} // buffers
} // creators
} // core

#endif //PLAINCAMERABUFFER_HPP
