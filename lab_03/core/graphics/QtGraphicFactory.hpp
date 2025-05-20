//
// Created by Roman Kanterov on 15.05.2025.
//

#ifndef QTGRAPHICFACTORY_HPP
#define QTGRAPHICFACTORY_HPP
#include "GraphicFactory.hpp"

#include <QGraphicsScene>

namespace core {
namespace graphics {

class QtGraphicFactory : public GraphicFactory {
public:
    explicit QtGraphicFactory(std::shared_ptr<QGraphicsScene> scene);
    std::shared_ptr<Canvas> createCanvas(int w, int h) override;
    std::shared_ptr<Painter> createPainter(std::shared_ptr<Canvas> c) override;
    std::shared_ptr<GraphicPoint> createGraphicPoint(double x, double y) override;
    std::shared_ptr<GraphicPoint> createGraphicPoint(Point p) override;
protected:
    std::shared_ptr<Graphics> createGraphics() override;
};

} // graphics
} // core

#endif //QTGRAPHICFACTORY_HPP
