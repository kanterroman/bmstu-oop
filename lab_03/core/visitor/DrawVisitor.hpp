//
// Created by Roman Kanterov on 15.05.2025.
//

#ifndef DRAWVISITOR_HPP
#define DRAWVISITOR_HPP
#include "Drawer.hpp"
#include "GraphicFactory.hpp"
#include "graphics/Painter.hpp"

#include <SceneObjectVisitor.hpp>
#include <SceneObjectVisitor.hpp>

namespace core {
namespace visitor {

class DrawVisitor : public SceneObjectVisitor {
public:
    void visit(objects::PlainCamera& cam) override;
    void visit(objects::MatrixMeshFigure& fig) override;
    void visit(objects::ListMeshFigure &fig) override;
private:
    std::shared_ptr<graphics::Painter> p;
    std::shared_ptr<objects::PlainCamera> cam;
    std::shared_ptr<graphics::GraphicFactory> factory;
    std::shared_ptr<Drawer> drawer;
};

} // visitor
} // core

#endif //DRAWVISITOR_HPP
