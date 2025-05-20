//
// Created by Roman Kanterov on 20.05.2025.
//

#include "DrawCommand.hpp"

void api::commands::DrawCommand::execute()
{
    drawManager->draw(sceneManager, activeCameraManager);
}