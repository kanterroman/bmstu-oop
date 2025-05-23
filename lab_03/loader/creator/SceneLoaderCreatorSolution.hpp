//
// Created by Roman Kanterov on 20.05.2025.
//

#ifndef SCENELOADERCREATORSOLUTION_HPP
#define SCENELOADERCREATORSOLUTION_HPP
#include "SceneLoaderCreator.hpp"
#include "StreamSceneLoaderCreator.hpp"

#include <memory>

namespace loader {
namespace creator {

class SceneLoaderCreatorSolution {
public:
    using idType = enum { STREAM };
    std::shared_ptr<SceneLoaderCreator> createCreator(idType id);
    void register_(idType id, std::shared_ptr<SceneLoaderCreator> cr);
private:
    std::unordered_map<idType, std::shared_ptr<SceneLoaderCreator>> map = { { STREAM, std::make_shared<StreamSceneLoaderCreator>() } };
};

} // creator
} // loader

#endif //SCENELOADERCREATORSOLUTION_HPP
