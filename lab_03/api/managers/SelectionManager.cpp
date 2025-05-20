//
// Created by Roman Kanterov on 20.05.2025.
//

#include "SelectionManager.hpp"
#include <ranges>

namespace api {
namespace managers {
SelectionManager::SelectionManager()
{
    focused = std::make_shared<core::objects::SceneComposite>();
}

void SelectionManager::select(core::objects::SceneObject::idType id, const std::shared_ptr<SceneManager>& sceneManager)
{
    auto it = std::__1::ranges::find_if(*(sceneManager->get_scene()), [id](auto obj){ return obj->id() == id; });
    auto item = *it;
    focused->add(item);
}

void SelectionManager::unselect(core::objects::SceneObject::idType id)
{
    auto it = std::__1::ranges::find_if(*focused, [id](const std::shared_ptr<core::objects::SceneObject>& obj){ return obj->id() == id; });
    focused->remove(it);
}

std::shared_ptr<core::objects::SceneComposite> SelectionManager::getSelected()
{
    return focused;
}
} // managers
} // api