//
// Created by Roman Kanterov on 15.05.2025.
//

#ifndef DRAWVISITOR_HPP
#define DRAWVISITOR_HPP
#include "Drawer.hpp"
#include "GraphicFactory.hpp"
#include "graphics/Painter.hpp"

#include <SceneObjectVisitor.hpp>

namespace core {
namespace visitor {

class DrawVisitor : SceneObjectVisitor {
private:
    std::shared_ptr<graphics::Painter> p;
    std::shared_ptr<objects::PlainCamera> cam;
    std::shared_ptr<graphics::GraphicFactory> factory;
    std::shared_ptr<Drawer> drawer;
public:
    void visit(std::shared_ptr<objects::PlainCamera> cam) override;
    void visit(std::shared_ptr<objects::MatrixMeshFigure> fig) override;
    void visit(std::shared_ptr<objects::ListMeshFigure> fig) override;
};

} // visitor
} // core

#endif //DRAWVISITOR_HPP
