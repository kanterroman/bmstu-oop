#ifndef PLAINCAMERA_HPP
#define PLAINCAMERA_HPP
#include <Camera.hpp>
#include "TransformVisitor.hpp"
#include "DrawVisitor.hpp"

#include <Camera.hpp>

namespace core {
namespace objects {
class PlainCameraImpl;

class PlainCamera : public Camera {
    friend class visitor::TransformVisitor;
    friend class visitor::DrawVisitor;
public:
    explicit PlainCamera(const std::shared_ptr<PlainCameraImpl> &impl)
        : impl(impl)
    {}

    void accept(std::shared_ptr<visitor::SceneObjectVisitor> vis) override;
private:
    std::shared_ptr<PlainCameraImpl> impl;
};

} // objects
} // core

#endif //PLAINCAMERA_HPP
