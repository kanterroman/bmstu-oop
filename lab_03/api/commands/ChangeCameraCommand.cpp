//
// Created by Roman Kanterov on 20.05.2025.
//

#include "ChangeCameraCommand.hpp"

namespace api {
namespace commands {
void ChangeCameraCommand::execute()
{
    activeCameraManager->resetActiveCamera(id, sceneManager);
}
} // commands
} // api