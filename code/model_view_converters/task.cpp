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
    load_data_t data;

    data.filepath = filepath;

    return data;
}

draw_data_t init_draw_task()
{
    draw_data_t data;

    data.edges = QList<QLineF>();

    return data;
}