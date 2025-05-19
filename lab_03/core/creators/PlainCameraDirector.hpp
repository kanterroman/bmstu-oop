#ifndef PLAINCAMERADIRECTOR_HPP
#define PLAINCAMERADIRECTOR_HPP
#include "CameraCreator.hpp"
#include "builders/PlainCameraBuilder.hpp"

namespace core {
namespace creators {

class PlainCameraDirector : public CameraCreator {
private:
    builders::PlainCameraBuilder builder{};
public:
    std::shared_ptr<objects::SceneObject> create(std::any buffer) override;
};

} // creators
} // core

#endif //PLAINCAMERADIRECTOR_HPP
