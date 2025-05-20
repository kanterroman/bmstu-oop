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

void PlainCameraBuilder::buildVisPoint() const
{
    cam->setVisPoint(buf->readPoint());
}

void PlainCameraBuilder::buildNormal()
{
    cam->set_n(buf->readNormal());
}

std::shared_ptr<objects::SceneObject> PlainCameraBuilder::build()
{
    return std::make_shared<objects::PlainCamera>(cam);
}
} // builders
} // creators
} // core