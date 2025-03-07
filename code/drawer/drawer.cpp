#include "../include/drawer.h"

#define WIDTH 1200
#define HEIGHT 800

#define MODEL_COLOR_R 0
#define MODEL_COLOR_G 0
#define MODEL_COLOR_B 0

#define CANVAS_COLOR_R 255
#define CANVAS_COLOR_G 255
#define CANVAS_COLOR_B 255

#define POINT_RADIUS 2

void draw_point(QPainter &p, const QPointF &point)
{
    p.drawEllipse(point, POINT_RADIUS, POINT_RADIUS);
}

void draw_edge(QPainter &p, const QLineF &edge)
{
    p.drawLine(edge);
}

status_t draw(draw_data_t &data)
{
    if (!data.view)
        return GRAPHICS_ERROR;

    QImage image(WIDTH, HEIGHT, QImage::Format_RGB32);

    image.fill(QColor(CANVAS_COLOR_R, CANVAS_COLOR_G, CANVAS_COLOR_B));

    QPainter p(&image);
    p.setPen(QPen(QColor(MODEL_COLOR_R, MODEL_COLOR_G, MODEL_COLOR_B)));

    for (auto edge : data.edges)
    {
        draw_point(p, edge.p1());
        draw_point(p, edge.p2());
        draw_edge(p, edge);
    }

    p.end();

    QPixmap pixmap = QPixmap::fromImage(image);
    data.view->scene()->clear();
    data.view->scene()->addPixmap(pixmap);

    return OK;
}
