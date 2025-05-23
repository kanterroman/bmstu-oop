//
// Created by Roman Kanterov on 20.05.2025.
//

#ifndef LOADCOMMAND_HPP
#define LOADCOMMAND_HPP
#include <utility>

#include "BaseCommand.hpp"

namespace api {
namespace commands {

class LoadCommand : public BaseCommand {
public:
    explicit LoadCommand(std::filesystem::path path);

    void execute() override;

private:
    using Action = void(managers::LoadingManager::*)(std::filesystem::path&, std::shared_ptr<managers::SceneManager>);
    Action call;
    std::filesystem::path path;
};

} // commands
} // api

#endif //LOADCOMMAND_HPP
