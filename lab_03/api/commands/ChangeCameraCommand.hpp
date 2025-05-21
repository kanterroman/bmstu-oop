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
    explicit ChangeCameraCommand(core::objects::SceneObject::idType id);

    void execute() override;

private:
    using Action = void(managers::ActiveCameraManager::*)(core::objects::SceneObject::idType, const std::shared_ptr<managers::SceneManager> &);
    Action call;
    core::objects::SceneObject::idType id;
};

} // commands
} // api

#endif //CHANGECAMERACOMMAND_HPP
