//
// Created by Roman Kanterov on 19.05.2025.
//

#ifndef BASECOMMAND_HPP
#define BASECOMMAND_HPP
#include "../managers/ActiveCameraManager.hpp"
#include "../managers/DrawManager.hpp"
#include "../managers/LoadingManager.hpp"
#include "../managers/RemoveObjectManager.hpp"
#include "../managers/TransformActiveCameraManager.hpp"
#include "../managers/TransformManager.hpp"

#include <memory>

namespace api {
namespace commands {

class BaseCommand {
public:
    virtual void execute() = 0;
    virtual void setManagers(std::shared_ptr<managers::ActiveCameraManager> activeCameraManager,
        std::shared_ptr<managers::DrawManager> drawManager,
        std::shared_ptr<managers::SceneManager> sceneManager,
        std::shared_ptr<managers::RemoveObjectManager> removeObjectManager,
        std::shared_ptr<managers::LoadingManager> loadingManager,
        std::shared_ptr<managers::SelectionManager> selectionManager,
        std::shared_ptr<managers::TransformManager> transformManager,
        std::shared_ptr<managers::TransformActiveCameraManager> transformCamManager);
    virtual ~BaseCommand();
protected:
    std::shared_ptr<managers::ActiveCameraManager> activeCameraManager;
    std::shared_ptr<managers::DrawManager> drawManager;
    std::shared_ptr<managers::SceneManager> sceneManager;
    std::shared_ptr<managers::RemoveObjectManager> removeObjectManager;
    std::shared_ptr<managers::LoadingManager> loadingManager;
    std::shared_ptr<managers::SelectionManager> selectionManager;
    std::shared_ptr<managers::TransformManager> transformManager;
    std::shared_ptr<managers::TransformActiveCameraManager> transformCamManager;
};

} // commands
} // api

#endif //BASECOMMAND_HPP
