//
// Created by Roman Kanterov on 20.05.2025.
//

#ifndef DRAWMANAGER_HPP
#define DRAWMANAGER_HPP
#include "ActiveCameraManager.hpp"
#include "GraphicFactory.hpp"
#include "SceneManager.hpp"

#include <memory>

namespace api {
namespace managers {

class DrawManager {
public:
    using FactoryType = core::graphics::QtGraphicFactory;

    explicit DrawManager(const std::shared_ptr<QGraphicsScene>& scene);
    void draw(const std::shared_ptr<SceneManager>& sceneManager, const std::shared_ptr<ActiveCameraManager>& cameraManager);
private:
    std::shared_ptr<FactoryType> graphics;
};

} // managers
} // api

#endif //DRAWMANAGER_HPP
