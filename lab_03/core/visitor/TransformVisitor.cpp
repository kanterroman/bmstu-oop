//
// Created by Roman Kanterov on 15.05.2025.
//

#include "TransformVisitor.hpp"
#include "Transformer.hpp"

namespace core {
namespace visitor {
void TransformVisitor::visit(objects::PlainCamera& cam)
{
    transformer->transform(cam.impl);
}

void TransformVisitor::visit(objects::MatrixMeshFigure& fig)
{
    transformer->transform(fig.impl);
}

void TransformVisitor::visit(objects::ListMeshFigure& fig)
{
    transformer->transform(fig.impl);
}

} // visitor
} // core