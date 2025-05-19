//
// Created by Roman Kanterov on 15.05.2025.
//

#ifndef SCENEOBJECTCREATOR_HPP
#define SCENEOBJECTCREATOR_HPP
#include <memory>
#include "SceneObject.hpp"

#include <any>

namespace core {
namespace creators {

class SceneObjectCreator {
public:
    virtual std::shared_ptr<objects::SceneObject> create(std::any) = 0;
    virtual ~SceneObjectCreator();
};

} // creators
} // core

#endif //SCENEOBJECTCREATOR_HPP
