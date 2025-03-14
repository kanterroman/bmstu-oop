#ifndef POINT_H
#define POINT_H

#include "model_data.h"

typedef struct point
{
    double x;
    double y;
    double z;
} point_t;

point_t init_point(const double x, const double y, const double z);
point_t add_points(const point_t &first, const point_t &second);
point_t substr_points(const point_t &first, const point_t &second);
point_t multip_point(const point_t &point, const double factor);
point_t divide_by_int(const point_t &point, const int divisor);

void rotate_point(point_t &point, const point_t &rotation_center, const model_rotate_t &angle);
void move_point(point_t &point, const point_t &move_vector);
void scale_point(point_t &point, const point_t &scale_center, const double factor);

#endif //POINT_H
