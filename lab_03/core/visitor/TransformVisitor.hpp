//
// Created by Roman Kanterov on 15.05.2025.
//

#ifndef TRANSFORMVISITOR_HPP
#define TRANSFORMVISITOR_HPP
#include "Transformer.hpp"

#include <SceneObjectVisitor.hpp>

namespace core {
namespace visitor {

class TransformVisitor : SceneObjectVisitor {
private:
    std::shared_ptr<Transformer> transformer;
public:
    explicit TransformVisitor(std::shared_ptr<Transformer> transformer);
    void visit(std::shared_ptr<objects::PlainCamera> cam) override;
    void visit(std::shared_ptr<objects::MatrixMeshFigure> fig) override;
    void visit(std::shared_ptr<objects::ListMeshFigure> fig) override;
};

} // visitor
} // core

#endif //TRANSFORMVISITOR_HPP
