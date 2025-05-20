//
// Created by Roman Kanterov on 19.05.2025.
//

#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP
#include "QtGraphicFactory.hpp"

#include <Scene.hpp>
#include <memory>

namespace api {
namespace managers {

class SceneManager {
public:
    SceneManager();
    std::shared_ptr<core::Scene> get_scene() const;
    void set_scene(const std::shared_ptr<core::Scene> &scene);
    std::shared_ptr<core::objects::SceneObject> getFocused() const;
    void set_focused(const std::shared_ptr<core::objects::SceneObject> &focused);
private:
    std::shared_ptr<core::Scene> scene;
    std::shared_ptr<core::objects::SceneObject> focused;
};

} // managers
} // api

#endif //SCENEMANAGER_HPP
