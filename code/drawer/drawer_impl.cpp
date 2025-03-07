#include "drawer_impl.h"

#include <QImage>
#include <QPainter>

#define WIDTH 1200
#define HEIGHT 800

#define MODEL_COLOR_R 0
#define MODEL_COLOR_G 0
#define MODEL_COLOR_B 0

#define CANVAS_COLOR_R 255
#define CANVAS_COLOR_G 255
#define CANVAS_COLOR_B 255

#define POINT_RADIUS 2

void init_canvas_tools(canvas_tools_t &tools)
{
    QImage image(WIDTH, HEIGHT, QImage::Format_RGB32);
    image.fill(QColor(CANVAS_COLOR_R, CANVAS_COLOR_G, CANVAS_COLOR_B));

    tools.image = image;
    tools.painter = new QPainter(&tools.image);
    tools.painter->setPen(QPen(QColor(MODEL_COLOR_R, MODEL_COLOR_G, MODEL_COLOR_B)));
}

void destroy_canvas_tools(canvas_tools_t &tools)
{
    tools.painter->end();
    delete tools.painter;
};

void draw_point(QPainter *p, const QPointF &point)
{
    p->drawEllipse(point, POINT_RADIUS, POINT_RADIUS);
}

void draw_edge(QPainter *p, const QLineF &edge)
{
    p->drawLine(edge);
}

void draw_figure(canvas_tools_t &canvas_tools, const draw_data_t &data)
{
    for (auto edge : data.edges)
    {
        draw_point(canvas_tools.painter, edge.p1());
        draw_point(canvas_tools.painter, edge.p2());
        draw_edge(canvas_tools.painter, edge);
    }
}

void draw_on_screen(draw_data_t &data, const canvas_tools_t &canvas_tools)
{
    QPixmap pixmap = QPixmap::fromImage(canvas_tools.image);
    data.view->scene()->clear();
    data.view->scene()->addPixmap(pixmap);
}
