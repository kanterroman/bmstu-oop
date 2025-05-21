#ifndef PAINTER_HPP
#define PAINTER_HPP
#include "Canvas.hpp"
#include "GraphicPoint.hpp"

#include <memory>

namespace core {
namespace graphics {

class Painter {
public:
    virtual void drawLine(std::shared_ptr<GraphicPoint>, std::shared_ptr<GraphicPoint>) = 0;
    virtual ~Painter();
};

} // graphics
} // core

#endif //PAINTER_HPP
