//
// Created by Roman Kanterov on 20.05.2025.
//

#include "RemoveObjectCommand.hpp"

namespace api {
namespace commands {
void RemoveObjectCommand::execute()
{
    removeObjectManager->removeObject(id, sceneManager, selectionManager);
}
} // commands
} // api