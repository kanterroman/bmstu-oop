//
// Created by Roman Kanterov on 15.05.2025.
//

#include "DrawVisitor.hpp"

namespace core {
namespace visitor {
void DrawVisitor::visit(objects::PlainCamera& cam)
{

}

void DrawVisitor::visit(objects::MatrixMeshFigure& fig)
{
    drawer->draw(fig.impl);
}

void DrawVisitor::visit(objects::ListMeshFigure &fig)
{
    drawer->draw(fig.impl);
}
} // visitor
} // core