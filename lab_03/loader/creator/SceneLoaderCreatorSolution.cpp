//
// Created by Roman Kanterov on 20.05.2025.
//

#include "SceneLoaderCreatorSolution.hpp"

#include <utility>

namespace loader {
namespace creator {
std::shared_ptr<SceneLoaderCreator> SceneLoaderCreatorSolution::createCreator(idType id)
{
    return map[id];
}

void SceneLoaderCreatorSolution::register_(idType id, std::shared_ptr<SceneLoaderCreator> cr)
{
    map[id] = std::move(cr);
}
} // creator
} // loader