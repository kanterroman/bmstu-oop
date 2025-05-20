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
    explicit LoadCommand(std::filesystem::path path)
        : path(std::move(path))
    {
    }

    void execute() override;

private:
    std::filesystem::path path;
};

} // commands
} // api

#endif //LOADCOMMAND_HPP
