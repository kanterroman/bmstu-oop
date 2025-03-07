#include "point.h"

#include "math.h"

static void rotate_x(point_t &point, const double angle);
static void rotate_y(point_t &point, const double angle);
static void rotate_z(point_t &point, const double angle);

point_t init_point(const double x, const double y, const double z)
{
    point_t point;
    point.x = x;
    point.y = y;
    point.z = z;
    return point;
}

point_t add_points(const point_t &first, const point_t &second)
{
    point_t res;

    res.x = first.x + second.x;
    res.y = first.y + second.y;
    res.z = first.z + second.z;

    return res;
}

point_t substr_points(const point_t &first, const point_t &second)
{
    point_t res;

    res.x = first.x - second.x;
    res.y = first.y - second.y;
    res.z = first.z - second.z;

    return res;
}

point_t multip_point(const point_t &point, double factor)
{
    return init_point(point.x * factor, point.y * factor, point.z * factor);
}

point_t divide_by_int(const point_t &point, const int divisor)
{
    return init_point(point.x / divisor, point.y / divisor, point.z / divisor);
}

void rotate_point(point_t &point, const point_t &rotation_center, const model_rotate_t &angle)
{
    point = substr_points(point, rotation_center);

    rotate_x(point, angle.x_rad);
    rotate_y(point, angle.y_rad);
    rotate_z(point, angle.z_rad);

    point = add_points(point, rotation_center);
}

void move_point(point_t &point, const point_t &move_vector)
{
    point = add_points(point, move_vector);
}

void scale_point(point_t &point, const point_t &scale_center, const double factor)
{
    point = substr_points(point, scale_center);

    point = multip_point(point, factor);

    point = add_points(point, scale_center);
}

void rotate_x(point_t &point, const double angle)
{
    double y = point.y;
    double z = point.z;
    point.y = cos(angle) * y - sin(angle) * z;
    point.z = sin(angle) * y + cos(angle) * z;
}

void rotate_y(point_t &point, const double angle)
{
    double x = point.x;
    double z = point.z;
    point.x = cos(angle) * x + sin(angle) * z;
    point.z = -sin(angle) * x + cos(angle) * z;
}

void rotate_z(point_t &point, const double angle)
{
    double x = point.x;
    double y = point.y;
    point.x = cos(angle) * x - sin(angle) * y;
    point.y = sin(angle) * x + cos(angle) * y;
}
