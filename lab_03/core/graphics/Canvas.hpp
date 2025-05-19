//
// Created by Roman Kanterov on 15.05.2025.
//

#ifndef CANVAS_HPP
#define CANVAS_HPP
#include <any>

namespace core {
namespace graphics {

class Canvas {
public:
    virtual int getWidth() = 0;
    virtual int getHeight() = 0;
    virtual void resize(int, int) = 0;
    virtual std::any get() = 0;
    virtual ~Canvas() = 0;
};

} // graphics
} // core

#endif //CANVAS_HPP
