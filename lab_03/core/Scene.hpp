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
public:
    using value_type = std::shared_ptr<objects::SceneObject>;
    using reference = std::shared_ptr<objects::SceneObject>&;
    using const_reference = const std::shared_ptr<objects::SceneObject>&;
    using iterator = std::vector<value_type>::iterator;
    using const_iterator = std::vector<value_type>::const_iterator;
    using size_type = size_t;

    iterator begin();
    iterator end();
    void remove(iterator &iter);
    void add(value_type obj);
private:
    dataType objs;
};

} // core

#endif //SCENE_HPP
