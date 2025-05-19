//
// Created by Roman Kanterov on 14.05.2025.
//

#ifndef SCENEOBJECTVISITOR_HPP
#define SCENEOBJECTVISITOR_HPP
#include "Camera.hpp"
#include "Figure.hpp"
#include "ListMeshFigure.hpp"
#include "MatrixMeshFigure.hpp"
#include "PlainCamera.hpp"

namespace core {
namespace visitor {

class SceneObjectVisitor {
public:
    virtual void visit(std::shared_ptr<objects::PlainCamera> cam) = 0;
    virtual void visit(std::shared_ptr<objects::MatrixMeshFigure> fig) = 0;
    virtual void visit(std::shared_ptr<objects::ListMeshFigure> fig) = 0;
    virtual ~SceneObjectVisitor();
};

} // visitor
} // core

#endif //SCENEOBJECTVISITOR_HPP
