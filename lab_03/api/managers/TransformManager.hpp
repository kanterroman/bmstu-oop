//
// Created by Roman Kanterov on 20.05.2025.
//

#ifndef TRANSFORMMANAGER_HPP
#define TRANSFORMMANAGER_HPP
#include "SceneManager.hpp"
#include "SelectionManager.hpp"
#include "TransformData.hpp"

#include <Point.hpp>
#include <memory>
#include <utility>

namespace api {
namespace managers {

class TransformManager {
public:
    void transform(TransformData data, const std::shared_ptr<SelectionManager> &manager);
};

} // managers
} // api

#endif //TRANSFORMMANAGER_HPP
