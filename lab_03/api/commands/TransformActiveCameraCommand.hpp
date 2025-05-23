//
// Created by Roman Kanterov on 20.05.2025.
//

#ifndef TRANSFORMACTIVECAMERACOMMAND_HPP
#define TRANSFORMACTIVECAMERACOMMAND_HPP
#include "BaseCommand.hpp"

namespace api {
namespace commands {

class TransformActiveCameraCommand : public BaseCommand {
public:
    explicit TransformActiveCameraCommand(const TransformData &data);

    void execute() override;
private:
    using Action = void(managers::TransformActiveCameraManager::*)(TransformData, std::shared_ptr<managers::ActiveCameraManager>);
    Action call;
    TransformData data;
};

} // commands
} // api

#endif //TRANSFORMACTIVECAMERACOMMAND_HPP
