//
// Created by Roman Kanterov on 18.05.2025.
//

#ifndef PLAINCAMERABUILDER_HPP
#define PLAINCAMERABUILDER_HPP
#include "PlainCamera.hpp"
#include "buffers/CameraBuffer.hpp"

#include <memory>

namespace core {
namespace creators {
namespace builders {

class PlainCameraBuilder {
public:
    void setBuf(const std::shared_ptr<buffers::CameraBuffer> &buf);
    void buildVisPoint() const;
    void buildNormal();
    std::shared_ptr<objects::SceneObject> build();
private:
    std::shared_ptr<buffers::CameraBuffer> buf{};
    std::shared_ptr<objects::BasePlainCameraImpl> cam{};
};

} // builders
} // creators
} // core

#endif //PLAINCAMERABUILDER_HPP
