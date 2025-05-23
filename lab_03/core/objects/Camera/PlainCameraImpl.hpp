//
// Created by Roman Kanterov on 15.05.2025.
//

#ifndef PLAINCAMERAIMPL_HPP
#define PLAINCAMERAIMPL_HPP
#include "BasePlainCameraImpl.hpp"
#include "ConstIterator.hpp"
#include "Iterator.hpp"
#include "Vector.hpp"
#include "ReverseIterator.h"
#include "ConstReverseIterator.h"
#include "ConstReverseIterator.hpp"
#include "ReverseIterator.hpp"

#include <Point.hpp>

namespace core {
namespace objects {

class PlainCameraImpl : public BasePlainCameraImpl {
public:
    PlainCameraImpl(const Point &vis_point, const Vector<double> &n)
        : visPoint(vis_point),
          n(n)
    {
    }

    Point getVisPoint() const override;
    void setVisPoint(const Point &vis_point) override;
    Vector<double> getN() const;
    void set_n(const Vector<double> &n);
private:
    Point visPoint;
    Vector<double> n;
};

} // objects
} // core

#endif //PLAINCAMERAIMPL_HPP
