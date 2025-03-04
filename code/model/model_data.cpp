#include "model_data.h"

model_rotate_t init_model_rotate(double x_rad, double y_rad, double z_rad)
{
    model_rotate_t model_rotate;

    model_rotate.x_rad = x_rad;
    model_rotate.y_rad = y_rad;
    model_rotate.z_rad = z_rad;

    return model_rotate;
}

model_scale_t init_model_scale(double factor)
{
    model_scale_t model_scale;

    model_scale.factor = factor;

    return model_scale;
}
