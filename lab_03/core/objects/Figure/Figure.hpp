#ifndef FIGURE_HPP
#define FIGURE_HPP
#include "Camera.hpp"
#include "Point.hpp"
#include "SceneObject.hpp"

#include <list>

class Painter;

namespace core::objects
{
class Figure : public SceneObject {
public:
    ~Figure() override = 0;
};
}


#endif //FIGURE_HPP
