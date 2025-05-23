//
// Created by Roman Kanterov on 20.05.2025.
//

#ifndef TRANSFORMACTIVECAMERAMANAGER_HPP
#define TRANSFORMACTIVECAMERAMANAGER_HPP
#include "ActiveCameraManager.hpp"
#include "TransformData.hpp"

#include <memory>

namespace api {
namespace managers {

class TransformActiveCameraManager {
public:
    void transformCamera(TransformData data ,std::shared_ptr<ActiveCameraManager> manager);
};

} // managers
} // api

#endif //TRANSFORMACTIVECAMERAMANAGER_HPP
