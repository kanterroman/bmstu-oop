//
// Created by Roman Kanterov on 20.05.2025.
//

#include "TransformCommand.hpp"

namespace api {
namespace commands {
void TransformCommand::execute()
{
    transformManager->transform(data, selectionManager);
}
} // commands
} // api