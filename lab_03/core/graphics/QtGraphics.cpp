//
// Created by Roman Kanterov on 15.05.2025.
//

#include "QtGraphics.hpp"

std::pair<int, int> core::graphics::QtGraphics::getSize()
{
    return { scene->width(), scene->height() };
}

void core::graphics::QtGraphics::displayCanvas(std::shared_ptr<Canvas> canvas)
{
    auto im = std::any_cast<std::shared_ptr<QImage>>(canvas->get());
    QPixmap pixmap = QPixmap::fromImage(*im);
    scene->clear();
    scene->addPixmap(pixmap);
}