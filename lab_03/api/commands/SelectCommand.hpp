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
    explicit SelectCommand(core::objects::SceneObject::idType id);

    void execute() override;

private:
    using Action = void(managers::SelectionManager::*)(core::objects::SceneObject::idType, const std::shared_ptr<managers::SceneManager> &);
    Action call;
    core::objects::SceneObject::idType id;
};

} // managers
} // api

#endif //SELECTCOMMAND_HPP
