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
public:
    explicit QtGraphics(const std::shared_ptr<QGraphicsScene> &scene)
        : scene(scene)
    {
    }

    std::pair<int, int> getSize() override;
    void displayCanvas(std::shared_ptr<Canvas> canvas) override;
private:
    std::shared_ptr<QGraphicsScene> scene;
};
}



#endif //QTGRAPHICS_HPP
