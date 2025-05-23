//
// Created by Roman Kanterov on 15.05.2025.
//

#ifndef GRAPHICPOINT_HPP
#define GRAPHICPOINT_HPP

namespace core {
namespace graphics {

class GraphicPoint {
public:
    virtual double getX() = 0;
    virtual double gety() = 0;
    virtual ~GraphicPoint();
};

} // graphics
} // core

#endif //GRAPHICPOINT_HPP
