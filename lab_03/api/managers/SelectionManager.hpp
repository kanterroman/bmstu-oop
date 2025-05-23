//
// Created by Roman Kanterov on 20.05.2025.
//

#ifndef SELECTIONMANAGER_HPP
#define SELECTIONMANAGER_HPP
#include "SceneManager.hpp"

#include <SceneComposite.hpp>
#include <utility>

namespace api {
namespace managers {

class SelectionManager {
public:
    SelectionManager();

    void select(core::objects::SceneObject::idType id, const std::shared_ptr<SceneManager>& sceneManager);
    void unselect(core::objects::SceneObject::idType id);
    std::shared_ptr<core::objects::SceneComposite> getSelected();
private:
    void checkIfFound(core::Scene::iterator iter, core::Scene::iterator end);
    std::shared_ptr<core::objects::SceneComposite> focused;
};

} // managers
} // api

#endif //SELECTIONMANAGER_HPP
