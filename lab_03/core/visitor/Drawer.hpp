//
// Created by Roman Kanterov on 15.05.2025.
//

#ifndef DRAWER_HPP
#define DRAWER_HPP
#include "DrawVisitor.hpp"
#include "GraphicFactory.hpp"
#include "PlainCameraImpl.hpp"
#include "Painter.hpp"

#include <memory>

namespace core {
namespace visitor {

class Drawer {
private:
    std::shared_ptr<objects::PlainCameraImpl> cam;
    std::shared_ptr<graphics::Painter> p;
public:
    Drawer(const std::shared_ptr<objects::PlainCameraImpl> &cam, const std::shared_ptr<graphics::Painter> &p)
        : cam(cam),
          p(p)
    {
    }

    void draw(std::shared_ptr<objects::MatrixMeshFigureImpl> fig, std::shared_ptr<graphics::GraphicFactory> graphic);
    void draw(std::shared_ptr<objects::ListMeshFigureImpl> fig, std::shared_ptr<graphics::GraphicFactory> graphic);
private:
    Point projectOnCam(Point pt);
};

} // visitor
} // core

#endif //DRAWER_HPP
