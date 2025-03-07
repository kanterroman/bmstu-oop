#include "task.h"

move_data_t init_move_task(const int dx, const int dy)
{
    move_data_t data;

    data.dx = dx;
    data.dy = dy;

    return data;
}

rotate_data_t init_rotate_task(const int dx, const int dy, const int dz)
{
    rotate_data_t data;

    data.x_dg = dx;
    data.y_dg = dy;
    data.z_dg = dz;

    return data;
}

scale_data_t init_scale_task(const double factor)
{
    scale_data_t data;

    data.scale_factor = factor;

    return data;
}

load_data_t init_load_task(const char *filepath)
{
    load_data_t data = filepath;

    return data;
}

draw_data_t init_draw_task(const QGraphicsView *view)
{
    draw_data_t data;

    data.view = view;
    data.edges = QList<QLineF>();

    return data;
}

void clear_edges(QList<QLineF> &edges)
{
    edges.clear();
}

void clear_draw_data(draw_data_t &data)
{
    clear_edges(data.edges);
}