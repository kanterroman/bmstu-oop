#ifndef DRAWER_IMPL_H
#define DRAWER_IMPL_H

#include "task_data.h"

#include <QImage>
#include <QPainter>

typedef struct canvas_tools
{
    QImage image;
    QPainter *painter;
} canvas_tools_t;

void init_canvas_tools(canvas_tools_t &tools);
void destroy_canvas_tools(canvas_tools_t &tools);
void draw_figure(canvas_tools_t &canvas_tools, const draw_data_t &data);
void draw_on_screen(draw_data_t &data, const canvas_tools_t &canvas_tools);

#endif //DRAWER_IMPL_H
