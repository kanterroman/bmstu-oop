//
// Created by Roman Kanterov on 15.05.2025.
//

#include "ListMeshFigure.hpp"

void core::objects::ListMeshFigure::accept(std::shared_ptr<visitor::SceneObjectVisitor> vis)
{
    vis->visit(*this);
}