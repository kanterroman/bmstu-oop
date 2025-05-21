//
// Created by Roman Kanterov on 18.05.2025.
//

#include "PlainCameraBuilder.hpp"

namespace core {
namespace creators {
namespace builders {
void PlainCameraBuilder::setBuf(const std::shared_ptr<buffers::CameraBuffer> &buf)
{
    this->buf = buf;
}

std::shared_ptr<objects::SceneObject> PlainCameraBuilder::build()
{
    cam = std::static_pointer_cast<objects::BasePlainCameraImpl>(std::make_shared<objects::PlainCameraImpl>(buf->readPoint(), buf->readNormal()));
    return std::make_shared<objects::PlainCamera>(cam);
}
} // builders
} // creators
} // core