//
// Created by Roman Kanterov on 19.05.2025.
//

#include "SceneManager.hpp"

#include <SceneComposite.hpp>

namespace api {
namespace managers {
SceneManager::SceneManager()
{
    scene = std::make_shared<core::Scene>();
    focused = std::make_shared<core::objects::SceneObject>(core::objects::SceneComposite());
}

std::shared_ptr<core::Scene> SceneManager::get_scene() const
{
    return scene;
}

void SceneManager::set_scene(const std::shared_ptr<core::Scene> &scene)
{
    this->scene = scene;
}

std::shared_ptr<core::objects::SceneObject> SceneManager::get_focused() const
{
    return focused;
}

void SceneManager::set_focused(const std::shared_ptr<core::objects::SceneObject> &focused)
{
    this->focused = focused;
}
} // managers
} // api