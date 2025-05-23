#ifndef PLAINCAMERA_HPP
#define PLAINCAMERA_HPP

#include "BasePlainCameraImpl.hpp"
#include <Camera.hpp>

namespace core::visitor
{
class SceneObjectVisitor;
class TransformVisitor;
class DrawVisitor;
}

namespace core {
namespace objects {
class PlainCameraImpl;

class PlainCamera : public Camera {
    friend class visitor::TransformVisitor;
    friend class visitor::DrawVisitor;
public:
    explicit PlainCamera(const std::shared_ptr<BasePlainCameraImpl> &impl)
        : impl(impl)
    {}

    void accept(std::shared_ptr<visitor::SceneObjectVisitor> vis) override;
private:
    std::shared_ptr<BasePlainCameraImpl> impl;
};

} // objects
} // core

#endif //PLAINCAMERA_HPP
