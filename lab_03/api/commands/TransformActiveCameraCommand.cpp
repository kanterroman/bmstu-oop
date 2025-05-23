//
// Created by Roman Kanterov on 20.05.2025.
//

#include "TransformActiveCameraCommand.hpp"

namespace api {
namespace commands {
TransformActiveCameraCommand::TransformActiveCameraCommand(const TransformData &data) : data(data)
{
    call = &managers::TransformActiveCameraManager::transformCamera;
}

void TransformActiveCameraCommand::execute()
{
    (*transformCamManager.*call)(data, activeCameraManager);
}
} // commands
} // api