//
// Created by Roman Kanterov on 20.05.2025.
//

#include "TransformActiveCameraCommand.hpp"

namespace api {
namespace commands {
void TransformActiveCameraCommand::execute()
{
    transformCamManager->transformCamera(data, activeCameraManager);
}
} // commands
} // api