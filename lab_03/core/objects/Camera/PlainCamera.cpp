//
// Created by Roman Kanterov on 15.05.2025.
//

#include "PlainCamera.hpp"
#include "SceneObjectVisitor.hpp"

namespace core {
namespace objects {
void PlainCamera::accept(std::shared_ptr<visitor::SceneObjectVisitor> vis)
{
    vis->visit(*this);
}
} // objects
} // core