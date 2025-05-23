//
// Created by Roman Kanterov on 20.05.2025.
//

#include "UnselectCommand.hpp"

namespace api {
namespace commands {
UnselectCommand::UnselectCommand(core::objects::SceneObject::idType id) : id(id)
{
    call = &managers::SelectionManager::unselect;
}

void UnselectCommand::execute()
{
    (*selectionManager.*call)(id);
}
} // commands
} // api