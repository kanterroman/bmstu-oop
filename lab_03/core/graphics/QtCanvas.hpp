#ifndef QTCANVAS_HPP
#define QTCANVAS_HPP
#include "Canvas.hpp"

#include <memory>
#include <QImage>

namespace core {
namespace graphics {

class QtCanvas : public Canvas {
private:
    std::shared_ptr<QImage> image;
public:
    QtCanvas(int width, int height);
    int getWidth() override;
    int getHeight() override;
    void resize(int width, int height) override;
    std::any get() override;
};

} // graphics
} // core

#endif //QTCANVAS_HPP
