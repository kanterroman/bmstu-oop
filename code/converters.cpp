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
