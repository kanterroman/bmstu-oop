//
// Created by Roman Kanterov on 20.05.2025.
//

#include "RemoveObjectManager.hpp"

namespace api {
namespace managers {
void RemoveObjectManager::removeObject(core::objects::SceneObject::idType id,
    const std::shared_ptr<SceneManager>& sceneManager, const std::shared_ptr<SelectionManager>& selManager)
{
    selManager->unselect(id);
    auto scene = sceneManager->getScene();
    for (auto i = scene->begin(); i != scene->end(); ++i)
        if ((*i)->id() == id)
        {
            scene->remove(i);
            return;
        }

}
} // managers
} // api