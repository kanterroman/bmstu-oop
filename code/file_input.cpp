#include "file_input.h"

status_t read_model(model_t &model, FILE *in)
{
    if (!in)
        return FILE_ERROR;

    status_t rc = OK;

    size_t nodes_num, edges_num;
    if (fscanf(in, "%zu %zu", &nodes_num, &edges_num) != 2)
        rc = FORMAT_ERROR;

    if (rc != OK) {}
    else
    {
        model_t buf;
        rc = init_model(buf, nodes_num, edges_num);
        for (size_t i = 0; i < nodes_num && rc == OK; i++)
        {
            double x, y, z;
            if (fscanf(in, "%lf %lf %lf", &x, &y, &z) != 3)
                rc = FORMAT_ERROR;
            if (rc == OK)
                rc = add_node(buf, init_node((int)i + 1, init_point(x, y, z)));
        }
        for (size_t i = 0; i < edges_num && rc == OK; i++)
        {
            int first = (int)nodes_num + 1, second = (int)nodes_num + 1;
            if (fscanf(in, "%d %d", &first, &second) != 2)
                rc = FORMAT_ERROR;

            if (first > nodes_num || second > nodes_num)
                rc = FORMAT_ERROR;

            if (rc == OK)
                rc = add_edge(buf, init_edge(first, second));
        }
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