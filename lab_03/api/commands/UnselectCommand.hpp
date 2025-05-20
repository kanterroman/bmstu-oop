//
// Created by Roman Kanterov on 20.05.2025.
//

#ifndef UNSELECTCOMMAND_HPP
#define UNSELECTCOMMAND_HPP
#include "BaseCommand.hpp"

#include <SceneObject.hpp>

namespace api {
namespace commands {

class UnselectCommand : public BaseCommand {
public:
    explicit UnselectCommand(core::objects::SceneObject::idType id)
        : id(id)
    {
    }

    void execute() override;

private:
    core::objects::SceneObject::idType id;
};

} // commands
} // api

#endif //UNSELECTCOMMAND_HPP
