//
// Created by Roman Kanterov on 15.05.2025.
//

#include "QtGraphicPoint.hpp"

namespace core {
namespace graphics {
QtGraphicPoint::QtGraphicPoint(double x, double y)
{
    pt = std::make_shared<QPointF>(x, y);
}

QtGraphicPoint::QtGraphicPoint(Point p)
{
    pt = std::make_shared<QPointF>(p.x, p.y);
}

double QtGraphicPoint::getX()
{
    return pt->x();
}

double QtGraphicPoint::gety()
{
    return pt->y();
}
} // graphics
} // core