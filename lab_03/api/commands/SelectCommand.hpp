//
// Created by Roman Kanterov on 20.05.2025.
//

#ifndef SELECTCOMMAND_HPP
#define SELECTCOMMAND_HPP
#include "BaseCommand.hpp"

namespace api {
namespace commands {

class SelectCommand : public BaseCommand {
public:
    explicit SelectCommand(core::objects::SceneObject::idType id)
        : id(id)
    {
    }

    void execute() override;

private:
    core::objects::SceneObject::idType id;
};

} // managers
} // api

#endif //SELECTCOMMAND_HPP
