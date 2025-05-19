//
// Created by Roman Kanterov on 15.05.2025.
//

#include "TransformVisitor.hpp"

namespace core {
namespace visitor {
TransformVisitor::TransformVisitor(std::shared_ptr<Transformer> transformer)
{
    this->transformer = transformer;
}

void TransformVisitor::visit(std::shared_ptr<objects::PlainCamera> cam)
{
    transformer->transform(cam->impl);
}

void TransformVisitor::visit(std::shared_ptr<objects::MatrixMeshFigure> fig)
{
    transformer->transform(fig->impl);
}

void TransformVisitor::visit(std::shared_ptr<objects::ListMeshFigure> fig)
{
    transformer->transform(fig->impl);
}

} // visitor
} // core