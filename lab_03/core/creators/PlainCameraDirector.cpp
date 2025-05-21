//
// Created by Roman Kanterov on 18.05.2025.
//

#include "PlainCameraDirector.hpp"

namespace core {
namespace creators {
std::shared_ptr<objects::SceneObject> PlainCameraDirector::create(std::any buffer)
{
    auto buf = std::any_cast<std::shared_ptr<buffers::CameraBuffer>>(buffer);
    builder.setBuf(std::make_shared<buffers::CameraBuffer>(*buf));
    return builder.build();
}
} // creators
} // core