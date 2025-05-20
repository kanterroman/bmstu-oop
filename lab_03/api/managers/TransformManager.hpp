//
// Created by Roman Kanterov on 20.05.2025.
//

#ifndef TRANSFORMMANAGER_HPP
#define TRANSFORMMANAGER_HPP
#include "SceneManager.hpp"

#include <Point.hpp>
#include <memory>
#include <utility>

namespace api {
namespace managers {

class TransformManager {
public:
    explicit TransformManager(std::shared_ptr<SceneManager> manager)
        : manager(std::move(manager))
    {
    }
    void transform(TransformData data);
private:
    std::shared_ptr<SceneManager> manager;
};

} // managers
} // api

#endif //TRANSFORMMANAGER_HPP
