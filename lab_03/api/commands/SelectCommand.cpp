//
// Created by Roman Kanterov on 20.05.2025.
//

#include "SelectCommand.hpp"

namespace api {
namespace managers {
} // managers
commands::SelectCommand::SelectCommand(core::objects::SceneObject::idType id) : id(id)
{
    call = &managers::SelectionManager::select;
}

void commands::SelectCommand::execute()
{
    (*selectionManager.*call)(id, sceneManager);
}
} // api