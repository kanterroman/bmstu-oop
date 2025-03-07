#include "converters.h"

static double to_rad(const double ang);
static void append_edge(QList<QLineF> &edges, const point_t &first, const point_t &second);
static QPointF to_qpointf(const point_t &point);

point_t convert_move_data(const move_data_t &data)
{
    return init_point(data.dx, data.dy, 0);
}

model_rotate_t convert_rotate_data(const rotate_data_t &data)
{
    double x_rad = to_rad(data.x_dg);
    double y_rad = to_rad(data.y_dg);
    double z_rad = to_rad(data.z_dg);

    return init_model_rotate(x_rad, y_rad, z_rad);
}

model_scale_t convert_scale_data(const scale_data_t &data)
{
    return init_model_scale(data.scale_factor);
}

void convert_draw_data(draw_data_t &data, const model_t &model)
{
    for (size_t i = 0; i < model.edges_size; i++)
    {
        edge_t cur_edge = model.edges[i];
        append_edge(data.edges, model.points[cur_edge.first - 1],
            model.points[cur_edge.second - 1]);
    }
}

double to_rad(const double ang)
{
    return ang * M_PI / 180;
}

void append_edge(QList<QLineF> &edges, const point_t &first, const point_t &second)
{
    edges.append(QLineF(to_qpointf(first), to_qpointf(second)));
}

QPointF to_qpointf(const point_t &point)
{
    return QPointF(point.x, point.y);
}
