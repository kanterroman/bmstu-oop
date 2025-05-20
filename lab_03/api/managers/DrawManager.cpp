//
// Created by Roman Kanterov on 20.05.2025.
//

#include "DrawManager.hpp"

#include "DrawVisitor.hpp"
#include "Graphics.hpp"

namespace api {
namespace managers {
DrawManager::DrawManager(const std::shared_ptr<QGraphicsScene>& scene)
{
    graphics = std::make_shared<FactoryType>(scene);
}

void DrawManager::draw(const std::shared_ptr<SceneManager>& sceneManager, const std::shared_ptr<ActiveCameraManager>&
                       cameraManager)
{
    auto scene = sceneManager->get_scene();

    auto sizes = graphics->getGraphics()->getSize();
    auto canvas = graphics->createCanvas(sizes.first, sizes.second);
    auto drawer = std::make_shared<core::visitor::DrawVisitor>(cameraManager->get_active_camera(), graphics, canvas);
    for (auto &obj : *scene)
    {
        obj->accept(std::static_pointer_cast<core::visitor::SceneObjectVisitor>(drawer));
    }
    graphics->getGraphics()->displayCanvas(canvas);
}
} // managers
} // api