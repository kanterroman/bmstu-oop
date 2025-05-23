//
// Created by Roman Kanterov on 20.05.2025.
//

#include "RemoveObjectCommand.hpp"

namespace api {
namespace commands {
RemoveObjectCommand::RemoveObjectCommand(core::objects::SceneObject::idType id): id(id)
{
    call = &managers::RemoveObjectManager::removeObject;
}

void RemoveObjectCommand::execute()
{
    (*removeObjectManager.*call)(id, sceneManager, selectionManager);
}
} // commands
} // api