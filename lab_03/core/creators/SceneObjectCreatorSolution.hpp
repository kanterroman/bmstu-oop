//
// Created by Roman Kanterov on 18.05.2025.
//

#ifndef SCENEOBJECTCREATORSOLUTION_HPP
#define SCENEOBJECTCREATORSOLUTION_HPP

#include "SceneObjectCreator.hpp"
#include "../util/concepts.hpp"

#include <memory>

namespace core {
namespace creators {

class SceneObjectCreatorSolution {
public:
    template <DerivedFrom<SceneObjectCreator> T>
    std::shared_ptr<SceneObjectCreator> createCreator() const;
};

template <DerivedFrom<SceneObjectCreator> T>
std::shared_ptr<SceneObjectCreator> SceneObjectCreatorSolution::createCreator() const
{
    return std::make_shared<T>();
}

} // creators
} // core

#endif //SCENEOBJECTCREATORSOLUTION_HPP
