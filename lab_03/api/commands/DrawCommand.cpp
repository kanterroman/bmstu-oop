//
// Created by Roman Kanterov on 20.05.2025.
//

#include "DrawCommand.hpp"

api::commands::DrawCommand::DrawCommand()
{
    call = &managers::DrawManager::draw;
}
void api::commands::DrawCommand::execute()
{
    (*drawManager.*call)(sceneManager, activeCameraManager);
}