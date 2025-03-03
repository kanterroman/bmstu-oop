#ifndef POINT_H
#define POINT_H
#include "model_data.h"

typedef struct point
{
    double x;
    double y;
    double z;
} point_t;

point_t init_point(double x, double y, double z);
point_t from_point(point_t &point);
point_t add_points(const point_t &first, const point_t &second);
point_t substr_points(const point_t &first, const point_t &second);
point_t multip_point(const point_t &point, double factor);
point_t divide_by_int(const point_t &point, int divisor);
void rotate_point(point_t &point, const point_t &rotation_center, const model_rotate_t &angle);

#endif //POINT_H
