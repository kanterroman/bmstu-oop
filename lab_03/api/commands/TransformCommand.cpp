//
// Created by Roman Kanterov on 20.05.2025.
//

#include "TransformCommand.hpp"

namespace api {
namespace commands {
TransformCommand::TransformCommand(const TransformData &data) : data(data)
{
    call = &managers::TransformManager::transform;
}

void TransformCommand::execute()
{
    (*transformManager.*call)(data, selectionManager);
}
} // commands
} // api