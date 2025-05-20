//
// Created by Roman Kanterov on 20.05.2025.
//

#ifndef REMOVEOBJECTCOMMAND_HPP
#define REMOVEOBJECTCOMMAND_HPP
#include "BaseCommand.hpp"

namespace api {
namespace commands {

class RemoveObjectCommand : public BaseCommand {
public:
    explicit RemoveObjectCommand(core::objects::SceneObject::idType id)
        : id(id)
    {
    }

    void execute() override;

private:
    core::objects::SceneObject::idType id;
};

} // commands
} // api

#endif //REMOVEOBJECTCOMMAND_HPP
