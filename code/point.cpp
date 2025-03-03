#include "point.h"
#include "math.h"

point_t init_point(double x, double y, double z)
{
    point_t point;
    point.x = x;
    point.y = y;
    point.z = z;
    return point;
}

point_t from_point(point_t &point)
{
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

point_t divide_by_int(const point_t &point, int divisor)
{
    return init_point(point.x / divisor, point.y / divisor, point.z / divisor);
}

void rotate_x(point_t &point, double angle)
{
    double y = point.y;
    double z = point.z;
    point.y = cos(angle) * y - sin(angle) * z;
    point.z = sin(angle) * y + cos(angle) * z;
}

void rotate_y(point_t &point, double angle)
{
    double x = point.x;
    double z = point.z;
    point.x = cos(angle) * x + sin(angle) * z;
    point.z = -sin(angle) * x + cos(angle) * z;
}

void rotate_z(point_t &point, double angle)
{
    double x = point.x;
    double y = point.y;
    point.x = cos(angle) * x - sin(angle) * y;
    point.y = sin(angle) * x + cos(angle) * y;
}

void rotate_point(point_t &point, const point_t &rotation_center, const model_rotate_t &angle)
{
    point = substr_points(point, rotation_center);

    rotate_x(point, angle.x_rad);
    rotate_y(point, angle.y_rad);
    rotate_z(point, angle.z_rad);

    point = add_points(point, rotation_center);
}
