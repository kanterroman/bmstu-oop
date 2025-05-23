//
// Created by Roman Kanterov on 15.05.2025.
//

#ifndef TRANSFORMVISITOR_HPP
#define TRANSFORMVISITOR_HPP


#include <SceneObjectVisitor.hpp>
#include "Transformer.hpp"
#include <utility>



namespace core {
namespace visitor {


class TransformVisitor : public SceneObjectVisitor {
public:
    explicit TransformVisitor(std::shared_ptr<Transformer> transformer)
        : transformer(std::move(transformer))
    {
    }

    void visit(objects::PlainCamera& cam) override;
    void visit(objects::MatrixMeshFigure& fig) override;
    void visit(objects::ListMeshFigure& fig) override;
private:
    std::shared_ptr<Transformer> transformer{};
};

} // visitor
} // core

#endif //TRANSFORMVISITOR_HPP
