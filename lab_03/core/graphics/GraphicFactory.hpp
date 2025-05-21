//
// Created by Roman Kanterov on 15.05.2025.
//

#ifndef GRAPHICFACTORY_HPP
#define GRAPHICFACTORY_HPP
#include <Point.hpp>
#include <memory>

namespace core {
namespace graphics {

class Canvas;
class Painter;
class Graphics;
class GraphicPoint;

class GraphicFactory {
public:
    virtual std::shared_ptr<Canvas> createCanvas(int, int) = 0;
    virtual std::shared_ptr<Graphics> getGraphics();
    virtual std::shared_ptr<Painter> createPainter(std::shared_ptr<Canvas>) = 0;
    virtual std::shared_ptr<GraphicPoint> createGraphicPoint(double, double) = 0;
    virtual std::shared_ptr<GraphicPoint> createGraphicPoint(Point) = 0;
    virtual ~GraphicFactory();
protected:
    std::shared_ptr<Graphics> gr{nullptr};
    virtual std::shared_ptr<Graphics> createGraphics() = 0;
};

} // graphics
} // core

#endif //GRAPHICFACTORY_HPP
