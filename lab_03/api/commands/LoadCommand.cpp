//
// Created by Roman Kanterov on 20.05.2025.
//

#include "LoadCommand.hpp"

namespace api {
namespace commands {
void LoadCommand::execute()
{
    loadingManager->loadToScene(path, sceneManager);
}
} // commands
} // api