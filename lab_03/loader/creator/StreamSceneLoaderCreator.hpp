//
// Created by Roman Kanterov on 20.05.2025.
//

#ifndef STREAMSCENELOADERCREATOR_HPP
#define STREAMSCENELOADERCREATOR_HPP
#include "SceneLoaderCreator.hpp"

namespace loader {
namespace creator {

class StreamSceneLoaderCreator : public SceneLoaderCreator {
public:
    std::shared_ptr<BaseSceneLoader> create(std::shared_ptr<std::istream> stream) override;
};

} // creator
} // loader

#endif //STREAMSCENELOADERCREATOR_HPP
