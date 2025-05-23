//
// Created by Roman Kanterov on 20.05.2025.
//

#ifndef FACADE_HPP
#define FACADE_HPP
#include "../commands/BaseCommand.hpp"

namespace api {
namespace facade {

class Facade {
public:
    explicit Facade(const std::shared_ptr<QGraphicsScene>& scene);
    void execute(const std::shared_ptr<commands::BaseCommand> &command);
private:
    std::shared_ptr<managers::ActiveCameraManager> activeCameraManager;
    std::shared_ptr<managers::DrawManager> drawManager;
    std::shared_ptr<managers::SceneManager> sceneManager;
    std::shared_ptr<managers::RemoveObjectManager> removeObjectManager;
    std::shared_ptr<managers::LoadingManager> loadingManager;
    std::shared_ptr<managers::SelectionManager> selectionManager;
    std::shared_ptr<managers::TransformManager> transformManager;
    std::shared_ptr<managers::TransformActiveCameraManager> transformCamManager;
};

} // facade
} // api

#endif //FACADE_HPP
