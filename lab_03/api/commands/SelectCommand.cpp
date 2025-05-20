//
// Created by Roman Kanterov on 20.05.2025.
//

#include "SelectCommand.hpp"

namespace api {
namespace managers {
} // managers
void commands::SelectCommand::execute()
{
    selectionManager->select(id, sceneManager);
}
} // api