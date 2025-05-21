//
// Created by Roman Kanterov on 20.05.2025.
//

#include "ActiveCameraManager.hpp"
#include "PlainCamera.hpp"
#include "PlainCameraImpl.hpp"

namespace api {
namespace managers {
ActiveCameraManager::ActiveCameraManager()
{
    core::Point visPoint = { 0, 0, 0 };
    Vector<double> n = { 0.0, 0.0, -0.5 };
    activeCamera = std::make_shared<core::objects::PlainCamera>(std::make_shared<core::objects::PlainCameraImpl>(visPoint, n));
}

std::shared_ptr<core::objects::PlainCamera> ActiveCameraManager::get_active_camera() const
{
    return activeCamera;
}

void ActiveCameraManager::resetActiveCamera(core::objects::SceneObject::idType id, const std::shared_ptr<SceneManager>& sceneManager)
{
    auto cam = ::std::__1::ranges::find_if(*(sceneManager->get_scene()), [id](auto obj){ return obj->id() == id; });
    activeCamera.reset();
    activeCamera = std::static_pointer_cast<core::objects::PlainCamera>(*cam);
}
} // managers
} // api