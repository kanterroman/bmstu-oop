#ifndef FIGURE_HPP
#define FIGURE_HPP
#include "Camera.hpp"

class Painter;

namespace core::objects
{
class Figure : public SceneObject {
public:
    ~Figure() override;
};
}


#endif //FIGURE_HPP
