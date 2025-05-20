//
// Created by Roman Kanterov on 15.05.2025.
//

#ifndef MATRIXMESHFIGURE_HPP
#define MATRIXMESHFIGURE_HPP
#include "Figure.hpp"
#include "TransformVisitor.hpp"
#include "MatrixMeshFigureImpl.hpp"
#include "DrawVisitor.hpp"


namespace core::objects {

class MatrixMeshFigure : public Figure {
    friend class visitor::TransformVisitor;
    friend class visitor::DrawVisitor;
public:
    explicit MatrixMeshFigure(const std::shared_ptr<BaseMatrixMeshFigureImpl> &impl)
        : impl(impl)
    {}

    void accept(std::shared_ptr<visitor::SceneObjectVisitor> vis) override;
private:
    std::shared_ptr<BaseMatrixMeshFigureImpl> impl;
};

} // objects
// core

#endif //MATRIXMESHFIGURE_HPP
