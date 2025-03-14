#include "file_input.h"

static status_t open_file(FILE **in, const char *filepath);
static status_t read_point(point_t &point, FILE *in);
static status_t read_points(model_t &model, FILE *in, const size_t nodes_num);
static status_t read_edge(edge_t &edge, FILE *in);
static status_t read_edges(model_t &model, FILE *in, const size_t edges_num);

status_t read_model(model_t &model, const char *filepath)
{
    status_t rc = OK;

    FILE *in = NULL;
    rc = open_file(&in, filepath);

    size_t nodes_num, edges_num;
    if (rc == OK)
    {
        if (fscanf(in, "%zu %zu", &nodes_num, &edges_num) != 2)
            rc = FILE_FORMAT_ERROR;
    }

    if (rc != OK) {}
    else
    {
        model_t buf;
        rc = init_model(buf, nodes_num, edges_num);
        if (rc == OK)
            rc = read_points(buf, in, nodes_num);
        if (rc == OK)
            rc = read_edges(buf, in, edges_num);
        if (rc != OK)
            destroy_model(buf);
        else
        {
            destroy_model(model);
            model = buf;
        }
    }

    if (rc != FILE_ERROR)
        fclose(in);

    return rc;
}

static status_t open_file(FILE **in, const char *filepath)
{
    if (!in || !filepath)
        return WRONG_ARGS_ERROR;

    status_t rc = OK;

    *in = fopen(filepath, "r");
    if (!*in)
        rc = FILE_ERROR;

    return rc;
}

static status_t read_point(point_t &point, FILE *in)
{
    status_t rc = OK;

    double x, y, z;
    if (fscanf(in, "%lf %lf %lf", &x, &y, &z) != 3)
        rc = FILE_FORMAT_ERROR;
    if (rc == OK)
        point = init_point(x, y, z);

    return rc;
}

static status_t read_points(model_t &model, FILE *in, const size_t nodes_num)
{
    if (!in)
        return FILE_ERROR;

    status_t rc = OK;

    point_t point;
    for (size_t i = 0; i < nodes_num && rc == OK; i++)
    {
        rc = read_point(point, in);

        if (rc == OK)
            rc = append_point(model, point);
    }

    return rc;
}

static status_t read_edge(edge_t &edge, FILE *in)
{
    status_t rc = OK;

    int first, second;
    if (fscanf(in, "%d %d", &first, &second) != 2)
        rc = FILE_FORMAT_ERROR;
    if (rc == OK)
        edge = init_edge(first, second);

    return rc;
}

static status_t read_edges(model_t &model, FILE *in, const size_t edges_num)
{
    if (!in)
        return WRONG_ARGS_ERROR;

    status_t rc = OK;

    edge_t edge;
    for (size_t i = 0; i < edges_num && rc == OK; i++)
    {
        rc = read_edge(edge, in);

        if (rc == OK && edge.first > model.points_size || edge.second > model.points_size)
            rc = FILE_FORMAT_ERROR;

        if (rc == OK)
            rc = append_edge(model, edge);
    }

    return rc;
}
