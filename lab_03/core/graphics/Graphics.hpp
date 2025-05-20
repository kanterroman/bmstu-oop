#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP
#include "Canvas.hpp"

#include <memory>

namespace core::graphics
{
class Graphics {
public:
    virtual void displayCanvas(std::shared_ptr<core::graphics::Canvas>) = 0;
    virtual std::pair<int, int> getSize() = 0;
    virtual ~Graphics() = 0;
};
}



#endif //GRAPHICS_HPP
