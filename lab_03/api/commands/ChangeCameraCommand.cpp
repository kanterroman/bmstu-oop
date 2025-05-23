//
// Created by Roman Kanterov on 20.05.2025.
//

#include "ChangeCameraCommand.hpp"

namespace api {
namespace commands {
ChangeCameraCommand::ChangeCameraCommand(core::objects::SceneObject::idType id): id(id)
{
    call = &managers::ActiveCameraManager::resetActiveCamera;
}

void ChangeCameraCommand::execute()
{
    (*activeCameraManager.*call)(id, sceneManager);
}
} // commands
} // api