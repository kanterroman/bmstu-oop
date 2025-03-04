#include "file_input.h"

static status_t read_nodes(model_t &model, FILE *in, size_t nodes_num);
static status_t read_edges(model_t &model, FILE *in, size_t edges_num);

status_t read_model(model_t &model, FILE *in)
{
    if (!in)
        return FILE_ERROR;

    status_t rc = OK;

    size_t nodes_num, edges_num;
    if (fscanf(in, "%zu %zu", &nodes_num, &edges_num) != 2)
        rc = FILE_FORMAT_ERROR;

    if (rc != OK) {}
    else
    {
        model_t buf;
        rc = init_model(buf, nodes_num, edges_num);
        if (rc == OK)
            rc = read_nodes(buf, in, nodes_num);
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

    return rc;
}

status_t read_nodes(model_t &model, FILE *in, const size_t nodes_num)
{
    if (!in)
        return FILE_ERROR;

    status_t rc = OK;

    for (size_t i = 0; i < nodes_num && rc == OK; i++)
    {
        double x, y, z;

        if (fscanf(in, "%lf %lf %lf", &x, &y, &z) != 3)
            rc = FILE_FORMAT_ERROR;

        if (rc == OK)
            rc = add_node(model, init_node(init_point(x, y, z)));
    }

    return rc;
}

status_t read_edges(model_t &model, FILE *in, const size_t edges_num)
{
    if (!in)
        return FILE_ERROR;

    status_t rc = OK;

    for (size_t i = 0; i < edges_num && rc == OK; i++)
    {
        int first = (int)model.nodes_size + 1, second = (int)model.nodes_size + 1;
        if (fscanf(in, "%d %d", &first, &second) != 2)
            rc = FILE_FORMAT_ERROR;

        if (first > model.nodes_size || second > model.nodes_size)
            rc = FILE_FORMAT_ERROR;

        if (rc == OK)
            rc = add_edge(model, init_edge(first, second));
    }

    return rc;
}
