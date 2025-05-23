//
// Created by Roman Kanterov on 15.05.2025.
//

#include "DrawVisitor.hpp"

#include "Graphics.hpp"

namespace core {
namespace visitor {
DrawVisitor::DrawVisitor(const std::shared_ptr<objects::PlainCamera> &cam,
    const std::shared_ptr<graphics::GraphicFactory> &factory, const std::shared_ptr<graphics::Canvas> &canvas): cam(cam), factory(factory), canvas(canvas)
{
    p = factory->createPainter(canvas);
    drawer = std::make_shared<Drawer>(cam->impl, p);
}

void DrawVisitor::visit(objects::PlainCamera& cam)
{

}

void DrawVisitor::visit(objects::MatrixMeshFigure& fig)
{
    drawer->draw(fig.impl, factory);
}

void DrawVisitor::visit(objects::ListMeshFigure &fig)
{
    drawer->draw(fig.impl, factory);
}

DrawVisitor::~DrawVisitor()
{
    p.reset();
}
} // visitor
} // core