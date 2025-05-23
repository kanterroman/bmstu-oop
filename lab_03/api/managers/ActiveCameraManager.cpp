//
// Created by Roman Kanterov on 20.05.2025.
//

#include "ActiveCameraManager.hpp"
#include "PlainCamera.hpp"
#include "PlainCameraImpl.hpp"
#include "../exceptions/NotACameraException.hpp"

namespace api {
namespace managers {
std::shared_ptr<core::objects::PlainCamera> ActiveCameraManager::get_active_camera() const
{
    return activeCamera;
}

void ActiveCameraManager::resetActiveCamera(core::objects::SceneObject::idType id, const std::shared_ptr<SceneManager>& sceneManager)
{
    auto cam = ::std::__1::ranges::find_if(*(sceneManager->getScene()), [id](auto obj){ return obj->id() == id; });
    if (!(*cam)->isCamera())
        throw exceptions::NotACameraException(__FILE__, __LINE__, __FUNCTION__);
    activeCamera.reset();
    activeCamera = std::static_pointer_cast<core::objects::PlainCamera>(*cam);
}
} // managers
} // api