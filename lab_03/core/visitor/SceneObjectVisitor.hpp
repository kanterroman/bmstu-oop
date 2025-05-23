//
// Created by Roman Kanterov on 14.05.2025.
//

#ifndef SCENEOBJECTVISITOR_HPP
#define SCENEOBJECTVISITOR_HPP

#include "ListMeshFigure.hpp"
#include "MatrixMeshFigure.hpp"
#include "PlainCamera.hpp"

namespace core {
namespace visitor {

class SceneObjectVisitor {
public:
    virtual void visit(objects::PlainCamera& cam) = 0;
    virtual void visit(objects::MatrixMeshFigure& fig) = 0;
    virtual void visit(objects::ListMeshFigure& fig) = 0;
    virtual ~SceneObjectVisitor();
};

} // visitor
} // core

#endif //SCENEOBJECTVISITOR_HPP
