//
// Created by Roman Kanterov on 14.05.2025.
//

#ifndef SCENE_HPP
#define SCENE_HPP

#include "SceneObject.hpp"
#include <vector>
#include <memory>

namespace core {

class Scene {
    using dataType = std::vector<std::shared_ptr<objects::SceneObject>>;
    using Iterator = std::vector<std::shared_ptr<objects::SceneObject>>::iterator;
public:
    Iterator begin();
    Iterator end();
    void remove(Iterator &iter);
    void add(std::shared_ptr<objects::SceneObject> obj);
private:
    dataType objs;
};

} // core

#endif //SCENE_HPP
