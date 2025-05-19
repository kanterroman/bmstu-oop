//
// Created by Roman Kanterov on 15.05.2025.
//

#ifndef QTGRAPHICS_HPP
#define QTGRAPHICS_HPP
#include "Graphics.hpp"
#include <QGraphicsScene>

namespace core::graphics
{
class QtGraphics : public Graphics {
private:
    std::shared_ptr<QGraphicsScene> scene;
public:
    explicit QtGraphics(const std::shared_ptr<QGraphicsScene> &scene)
        : scene(scene)
    {
    }

    void displayCanvas(std::shared_ptr<Canvas> canvas) override;
};
}



#endif //QTGRAPHICS_HPP
