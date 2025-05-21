//
// Created by Roman Kanterov on 15.05.2025.
//

#include "QtCanvas.hpp"

namespace core {
namespace graphics {
QtCanvas::QtCanvas(int width, int height)
{
    image = std::make_shared<QImage>(width, height, QImage::Format_RGB32);
    image->fill(Qt::white);
}

int QtCanvas::getWidth()
{
    return image->width();
}

int QtCanvas::getHeight()
{
    return image->height();
}

void QtCanvas::resize(int width, int height)
{
    image.reset();
    image = std::make_shared<QImage>(width, height, QImage::Format_RGB32);
}

std::any QtCanvas::get()
{
    return std::any(image);
}
} // graphics
} // core