#ifndef PLAINCAMERADIRECTOR_HPP
#define PLAINCAMERADIRECTOR_HPP
#include "CameraCreator.hpp"
#include "builders/PlainCameraBuilder.hpp"

namespace core {
namespace creators {

class PlainCameraDirector : public CameraCreator {
public:
    std::shared_ptr<objects::SceneObject> create(std::any buffer) override;
private:
    builders::PlainCameraBuilder builder{};
};

} // creators
} // core

#endif //PLAINCAMERADIRECTOR_HPP
