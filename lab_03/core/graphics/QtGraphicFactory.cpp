//
// Created by Roman Kanterov on 15.05.2025.
//

#include "QtGraphicFactory.hpp"

#include "QtCanvas.hpp"
#include "QtGraphicPoint.hpp"
#include "QtGraphics.hpp"
#include "QtPainter.hpp"

namespace core {
namespace graphics {
std::shared_ptr<Graphics> QtGraphicFactory::createGraphics()
{
    return gr;
}

QtGraphicFactory::QtGraphicFactory(std::shared_ptr<QGraphicsScene> scene)
{
    gr = std::make_shared<QtGraphics>(scene);
}

std::shared_ptr<Canvas> QtGraphicFactory::createCanvas(int w, int h)
{
    return std::make_shared<QtCanvas>(w, h);
}

std::shared_ptr<Painter> QtGraphicFactory::createPainter(std::shared_ptr<Canvas> c)
{
    return std::make_shared<QtPainter>(std::any_cast<std::shared_ptr<QImage>>(c->get()));
}

std::shared_ptr<GraphicPoint> QtGraphicFactory::createGraphicPoint(double x, double y)
{
    return std::make_shared<QtGraphicPoint>(x, y);
}

std::shared_ptr<GraphicPoint> QtGraphicFactory::createGraphicPoint(Point p)
{
    return std::make_shared<QtGraphicPoint>(p);
}
} // graphics
} // core