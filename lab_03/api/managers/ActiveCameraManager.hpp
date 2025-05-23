//
// Created by Roman Kanterov on 20.05.2025.
//

#ifndef ACTIVECAMERAMANAGER_HPP
#define ACTIVECAMERAMANAGER_HPP
#include "SceneManager.hpp"

#include <Camera.hpp>
#include <memory>

namespace core::objects
{
class PlainCamera;
}

namespace api {
namespace managers {

class ActiveCameraManager {
public:
    std::shared_ptr<core::objects::PlainCamera> get_active_camera() const;
    void resetActiveCamera(core::objects::SceneObject::idType id, const std::shared_ptr<SceneManager>& sceneManager);
private:
    std::shared_ptr<core::objects::PlainCamera> activeCamera{};
};

} // managers
} // api

#endif //ACTIVECAMERAMANAGER_HPP
