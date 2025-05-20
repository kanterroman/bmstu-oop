//
// Created by Roman Kanterov on 19.05.2025.
//

#include "BaseCommand.hpp"

#include <utility>

namespace api {
namespace commands {
void BaseCommand::setManagers(std::shared_ptr<managers::ActiveCameraManager> activeCameraManager,
    std::shared_ptr<managers::DrawManager> drawManager, std::shared_ptr<managers::SceneManager> sceneManager,
    std::shared_ptr<managers::RemoveObjectManager> removeObjectManager,
    std::shared_ptr<managers::LoadingManager> loadingManager,
    std::shared_ptr<managers::SelectionManager> selectionManager,
    std::shared_ptr<managers::TransformManager> transformManager,
    std::shared_ptr<managers::TransformActiveCameraManager> transformCamManager)
{
    this->activeCameraManager = std::move(activeCameraManager);
    this->sceneManager = std::move(sceneManager);
    this->drawManager = std::move(drawManager);
    this->removeObjectManager = std::move(removeObjectManager);
    this->loadingManager = std::move(loadingManager);
    this->selectionManager = std::move(selectionManager);
    this->transformManager = std::move(transformManager);
    this->transformCamManager = std::move(transformCamManager);
}

BaseCommand::~BaseCommand() = default;
} // commands
} // api