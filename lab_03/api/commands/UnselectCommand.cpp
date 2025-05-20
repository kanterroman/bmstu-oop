//
// Created by Roman Kanterov on 20.05.2025.
//

#include "UnselectCommand.hpp"

namespace api {
namespace commands {
void UnselectCommand::execute()
{
    selectionManager->unselect(id);
}
} // commands
} // api