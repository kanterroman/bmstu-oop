//
// Created by Roman Kanterov on 20.05.2025.
//

#ifndef CHANGECAMERACOMMAND_HPP
#define CHANGECAMERACOMMAND_HPP
#include "BaseCommand.hpp"

namespace api {
namespace commands {

class ChangeCameraCommand : public BaseCommand {
public:
    explicit ChangeCameraCommand(core::objects::SceneObject::idType id)
        : id(id)
    {
    }

    void execute() override;

private:
    core::objects::SceneObject::idType id;
};

} // commands
} // api

#endif //CHANGECAMERACOMMAND_HPP
