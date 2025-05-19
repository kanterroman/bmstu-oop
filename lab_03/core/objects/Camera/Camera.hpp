#ifndef CAMERA_HPP
#define CAMERA_HPP
#include "SceneObject.hpp"
#include "Point.hpp"

namespace core::objects
{
class Camera : public SceneObject {
public:
    bool isCamera() override;
    void accept(std::shared_ptr<visitor::SceneObjectVisitor> vis) override = 0;
};

}


#endif //CAMERA_HPP
