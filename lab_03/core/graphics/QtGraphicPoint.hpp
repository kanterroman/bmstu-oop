//
// Created by Roman Kanterov on 15.05.2025.
//

#ifndef QTGRAPHICPOINT_HPP
#define QTGRAPHICPOINT_HPP
#include "GraphicPoint.hpp"

#include <Point.hpp>
#include <QPointF>

namespace core {
namespace graphics {

class QtGraphicPoint : public GraphicPoint {
public:
    QtGraphicPoint(double x, double y);
    QtGraphicPoint(Point p);
    double getX() override;
    double gety() override;
private:
    std::shared_ptr<QPointF> pt;
};

} // graphics
} // core

#endif //QTGRAPHICPOINT_HPP
