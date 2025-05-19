//
// Created by Roman Kanterov on 15.05.2025.
//

#include "DrawVisitor.hpp"

namespace core {
namespace visitor {
void DrawVisitor::visit(std::shared_ptr<objects::PlainCamera> cam)
{

}

void DrawVisitor::visit(std::shared_ptr<objects::MatrixMeshFigure> fig)
{
    drawer->draw(fig->impl);
}

void DrawVisitor::visit(std::shared_ptr<objects::ListMeshFigure> fig)
{
    drawer->draw(fig->impl);
}
} // visitor
} // core