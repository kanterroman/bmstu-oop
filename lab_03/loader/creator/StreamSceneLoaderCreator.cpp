//
// Created by Roman Kanterov on 20.05.2025.
//

#include "StreamSceneLoaderCreator.hpp"

#include "../StreamSceneLoader.hpp"

namespace loader {
namespace creator {
std::shared_ptr<BaseSceneLoader> StreamSceneLoaderCreator::create()
{
    return std::make_shared<StreamSceneLoader>();
}
} // creator
} // loader