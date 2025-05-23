//
// Created by Roman Kanterov on 20.05.2025.
//

#include "LoadCommand.hpp"

namespace api {
namespace commands {
LoadCommand::LoadCommand(std::filesystem::path path) : path(std::move(path))
{
    call = &managers::LoadingManager::loadToScene;
}

void LoadCommand::execute()
{
    (*loadingManager.*call)(path, sceneManager);
}
} // commands
} // api