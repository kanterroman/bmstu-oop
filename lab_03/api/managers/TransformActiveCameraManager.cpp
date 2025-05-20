//
// Created by Roman Kanterov on 20.05.2025.
//

#include "TransformActiveCameraManager.hpp"

#include "TransformVisitor.hpp"
#include "Transformer.hpp"

namespace api {
namespace managers {
void TransformActiveCameraManager::transformCamera(TransformData data, std::shared_ptr<ActiveCameraManager> manager)
{
    auto cam = manager->get_active_camera();
    auto transformer = std::make_shared<core::visitor::Transformer>(data);
    auto vis = std::static_pointer_cast<core::visitor::SceneObjectVisitor>(std::make_shared<core::visitor::TransformVisitor>(transformer));
    cam->accept(vis);
}
} // managers
} // api