//
// Created by Roman Kanterov on 20.05.2025.
//

#include "Facade.hpp"

namespace api {
namespace facade {
Facade::Facade(const std::shared_ptr<QGraphicsScene>& scene)
{
    sceneManager = std::make_shared<managers::SceneManager>();
    activeCameraManager = std::make_shared<managers::ActiveCameraManager>();
    selectionManager = std::make_shared<managers::SelectionManager>();
    transformManager = std::make_shared<managers::TransformManager>();
    drawManager = std::make_shared<managers::DrawManager>(scene);
    removeObjectManager = std::make_shared<managers::RemoveObjectManager>();
    loadingManager = std::make_shared<managers::LoadingManager>();
    transformCamManager = std::make_shared<managers::TransformActiveCameraManager>();
}

void Facade::execute(const std::shared_ptr<commands::BaseCommand> &command)
{
    command->setManagers(activeCameraManager, drawManager, sceneManager, removeObjectManager,
        loadingManager, selectionManager, transformManager, transformCamManager);
    command->execute();
}
} // facade
} // api