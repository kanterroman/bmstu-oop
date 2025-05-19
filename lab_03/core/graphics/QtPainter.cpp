//
// Created by Roman Kanterov on 15.05.2025.
//

#include "QtPainter.hpp"

namespace core {
namespace graphics {
QtPainter::QtPainter(const std::shared_ptr<QImage>& img)
{
    p = std::make_shared<QPainter>(img.get());
}

void QtPainter::drawLine(std::shared_ptr<GraphicPoint> p1, std::shared_ptr<GraphicPoint> p2)
{
    p->drawLine(QPointF(p1->getX(), p1->gety()), QPointF(p2->getX(), p2->gety()));
}

QtPainter::~QtPainter()
{
    p->end();
}
} // graphics
} // core