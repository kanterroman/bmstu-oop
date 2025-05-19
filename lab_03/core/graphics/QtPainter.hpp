#ifndef QTPAINTER_HPP
#define QTPAINTER_HPP
#include "Painter.hpp"
#include <QPainter>

namespace core {
namespace graphics {

class QtPainter : public Painter {
private:
    std::shared_ptr<QPainter> p{nullptr};
public:
    explicit QtPainter(const std::shared_ptr<QImage>& img);
    void drawLine(std::shared_ptr<GraphicPoint> p1, std::shared_ptr<GraphicPoint> p2) override;
    ~QtPainter() override;
};

} // graphics
} // core

#endif //QTPAINTER_HPP
