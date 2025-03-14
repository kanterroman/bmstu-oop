#ifndef MODEL_DATA_H
#define MODEL_DATA_H

typedef struct model_rotate
{
    double x_rad;
    double y_rad;
    double z_rad;
} model_rotate_t;

typedef struct model_scale
{
    double factor;
} model_scale_t;

model_rotate_t init_model_rotate(const double x_rad, const double y_rad, const double z_rad);
model_scale_t init_model_scale(const double factor);

#endif //MODEL_DATA_H
