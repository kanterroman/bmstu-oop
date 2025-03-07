#include "model.h"

#include <stdlib.h>
#include "float.h"

static status_t find_model_barycenter(point_t &barycenter, const point_t *points, const size_t size);

bool fields_exist(const model_t &model)
{
    return model.points && model.edges;
}

edge_t init_edge(const int first, const int second)
{
    edge_t edge;

    edge.first = first;
    edge.second = second;

    return edge;
}

status_t init_model(model_t &model, const size_t points_num, const size_t edges_num)
{
    status_t rc = OK;

    if (points_num < 1)
    {
        rc = FORMAT_ERROR;
    }
    else
    {
        model.points = (point_t *)malloc(points_num * sizeof(point_t));
        model.edges = (edge_t *)malloc(edges_num * sizeof(edge_t));
        if (fields_exist(model))
        {
            model.edges_size = 0;
            model.points_size = 0;
        }
        else
        {
            destroy_model(model);
            rc = MALLOC_ERROR;
        }
    }

    return rc;
}

status_t append_point(model_t &model, const point_t &point)
{
    if (!fields_exist(model))
        return NOT_INIT_ERROR;

    model.points[model.points_size] = point;
    model.points_size++;

    return OK;
}

status_t append_edge(model_t &model, const edge_t &edge)
{
    if (!model.edges)
        return NOT_INIT_ERROR;
    if (edge.first == edge.second)
        return FILE_FORMAT_ERROR;

    model.edges[model.edges_size] = edge;
    model.edges_size++;

    return OK;
}

void destroy_model(const model_t &model)
{
    free(model.points);
    free(model.edges);
}


status_t scale_model(model_t &model, const model_scale_t &data)
{
    if (!fields_exist(model))
        return NOT_INIT_ERROR;
    if (data.factor < DBL_EPSILON)
        return WRONG_SCALE_ERROR;

    point_t barycenter;
    status_t rc = find_model_barycenter(barycenter, model.points, model.points_size);

    for (size_t i = 0; rc == OK && i < model.points_size; i++)
    {
        scale_point(model.points[i], barycenter, data.factor);
    }

    return rc;
}


status_t move_model(model_t &model, const point_t &move_vector)
{
    if (!fields_exist(model))
        return NOT_INIT_ERROR;

    for (size_t i = 0; i < model.points_size; i++)
    {
       move_point(model.points[i], move_vector);
    }

    return OK;
}

status_t rotate_model(model_t &model, const model_rotate_t &data)
{
    if (!fields_exist(model))
        return NOT_INIT_ERROR;

    point_t barycenter;
    status_t rc = find_model_barycenter(barycenter, model.points, model.points_size);

    for (size_t i = 0; rc == OK && i < model.points_size; i++)
    {
        rotate_point(model.points[i], barycenter, data);
    }

    return rc;
}

status_t find_model_barycenter(point_t &barycenter, const point_t *points, const size_t size)
{
    if (size == 0)
        return ZERO_DIVISION_ERROR;

    point_t coord_sum = init_point(0, 0, 0);

    for (int i = 0; i < size; i++)
    {
        coord_sum = add_points(points[i], coord_sum);
    }

    barycenter = divide_by_int(coord_sum, (int)size);

    return OK;
}
