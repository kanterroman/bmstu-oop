//
// Created by Roman Kanterov on 20.05.2025.
//

#ifndef DRAWCOMMAND_HPP
#define DRAWCOMMAND_HPP
#include "BaseCommand.hpp"


namespace api::commands
{
class DrawCommand : public BaseCommand {
public:
    DrawCommand();
    void execute() override;
private:
    using Action = void(managers::DrawManager::*)(const std::shared_ptr<managers::SceneManager>&, const std::shared_ptr<managers::ActiveCameraManager>&);
    Action call;
};
}



#endif //DRAWCOMMAND_HPP
