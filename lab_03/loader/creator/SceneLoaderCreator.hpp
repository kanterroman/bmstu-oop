//
// Created by Roman Kanterov on 20.05.2025.
//

#ifndef SCENELOADERCREATOR_HPP
#define SCENELOADERCREATOR_HPP
#include "../BaseSceneLoader.hpp"

#include <memory>

namespace loader {
namespace creator {

class SceneLoaderCreator {
public:
    virtual std::shared_ptr<BaseSceneLoader> create(std::shared_ptr<std::istream>) = 0;
    virtual ~SceneLoaderCreator();
};

} // creator
} // loader

#endif //SCENELOADERCREATOR_HPP
