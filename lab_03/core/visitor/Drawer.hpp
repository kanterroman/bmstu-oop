//
// Created by Roman Kanterov on 15.05.2025.
//

#ifndef DRAWER_HPP
#define DRAWER_HPP
#include "GraphicFactory.hpp"
#include "ListMeshFigureImpl.hpp"
#include "MatrixMeshFigureImpl.hpp"
#include "PlainCameraImpl.hpp"
#include "Painter.hpp"

#include <memory>

namespace core {
namespace visitor {

class Drawer {
public:
    Drawer(const std::shared_ptr<objects::BasePlainCameraImpl> &cam, const std::shared_ptr<graphics::Painter> &p)
        : cam(cam),
          p(p)
    {
    }

    void draw(std::shared_ptr<objects::BaseMatrixMeshFigureImpl> fig, std::shared_ptr<graphics::GraphicFactory> graphic);
    void draw(std::shared_ptr<objects::BaseListMeshFigureImpl> fig, std::shared_ptr<graphics::GraphicFactory> graphic);
private:
    Point projectOnCam(Point pt);
    bool checkVisibility(Point pt);
    Point tr(Point pr);
    std::shared_ptr<objects::BasePlainCameraImpl> cam;
    std::shared_ptr<graphics::Painter> p;
};

} // visitor
} // core

#endif //DRAWER_HPP
