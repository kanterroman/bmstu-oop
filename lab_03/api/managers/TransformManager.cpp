//
// Created by Roman Kanterov on 20.05.2025.
//

#include "TransformManager.hpp"

#include "TransformVisitor.hpp"
#include "Transformer.hpp"

namespace api {
namespace managers {
void TransformManager::transform(TransformData data, const std::shared_ptr<SelectionManager> &manager)
{
    auto focused = manager->getSelected();
    auto transformer = std::make_shared<core::visitor::Transformer>(data);
    auto vis = std::static_pointer_cast<core::visitor::SceneObjectVisitor>(std::make_shared<core::visitor::TransformVisitor>(transformer));
    focused->accept(vis);
}
} // managers
} // api
