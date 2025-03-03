#include "converters.h"
#include "math.h"

double to_rad(double ang)
{
    return ang * M_PI / 180;
}

model_move_t convert_move_data(const move_data_t &data)
{
    return init_model_vector(data.dx, data.dy, 0);
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

QPointF to_qpointf(const point_t &point)
{
    return QPointF(point.x, point.y);
}

void append_edge(QList<QLineF> &edges, node_t &first, node_t &second)
{
    edges.append(QLineF(to_qpointf(first.point), to_qpointf(second.point)));
}

void convert_draw_data(draw_data_t &data, const model_t &model)
{
    for (size_t i = 0; i < model.edges_size; i++)
    {
        edge_t cur_edge = model.edges[i];
        append_edge(data.edges, model.nodes[cur_edge.first - 1], model.nodes[cur_edge.second - 1]);
    }
}
