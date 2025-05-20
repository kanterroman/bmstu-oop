//
// Created by Roman Kanterov on 20.05.2025.
//

#ifndef REMOVEOBJECTMANAGER_HPP
#define REMOVEOBJECTMANAGER_HPP
#include "SceneManager.hpp"
#include "SelectionManager.hpp"

#include <SceneObject.hpp>

namespace api {
namespace managers {

class RemoveObjectManager {
public:
    void removeObject(core::objects::SceneObject::idType id, const std::shared_ptr<SceneManager>& sceneManager, const std::shared_ptr<SelectionManager>& selManager);
};

} // managers
} // api

#endif //REMOVEOBJECTMANAGER_HPP
