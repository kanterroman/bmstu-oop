#include "model.h"
#include <stdlib.h>

point_t find_model_barycenter(node_t *nodes, size_t size);

bool validate_fields(const model_t &model)
{
    return model.nodes && model.edges;
}

node_t init_node(int num, point_t point)
{
    node_t node;

    node.num = num;
    node.point = point;

    return node;
}

edge_t init_edge(int first, int second)
{
    edge_t edge;

    edge.first = first;
    edge.second = second;

    return edge;
}

status_t init_model(model_t &model, size_t nodes_num, size_t edges_num)
{
    status_t rc = OK;

    if (nodes_num < 2 || edges_num < 1)
    {
    }
    else
    {
        model.nodes = (node_t *)malloc(nodes_num * sizeof(node_t));
        model.edges = (edge_t *)malloc(edges_num * sizeof(edge_t));
        if (validate_fields(model))
        {
            model.edges_size = 0;
            model.nodes_size = 0;
        }
        else
        {
            destroy_model(model);
            rc = MALLOC_ERROR;
        }
    }

    return rc;
}

status_t add_node(model_t &model, const node_t &node)
{
    if (!validate_fields(model))
        return NOT_INIT_ERROR;

    model.nodes[model.nodes_size] = node;
    model.nodes_size++;

    return OK;
}

status_t add_edge(model_t &model, const edge_t &edge)
{
    if (!model.edges)
        return NOT_INIT_ERROR;
    if (edge.first == edge.second)
        return FORMAT_ERROR;

    model.edges[model.edges_size] = edge;
    model.edges_size++;

    return OK;
}

void destroy_model(const model_t &model)
{
    free(model.nodes);
    free(model.edges);
}

void scale_node(node_t &node, double factor)
{
    node.point = multip_point(node.point, factor);
}

status_t scale_model(model_t &model, const model_scale_t &data)
{
    if (!validate_fields(model))
        return NOT_INIT_ERROR;


    for (size_t i = 0; i < model.nodes_size; i++)
    {
        scale_node(model.nodes[i], data.factor);
    }

    return OK;
}

void move_node(node_t &node, point_t &move_vector)
{
    node.point = add_points(node.point, move_vector);
}

status_t move_model(model_t &model, const model_vector_t &move_vector)
{
    if (!validate_fields(model))
        return NOT_INIT_ERROR;

    for (size_t i = 0; i < model.nodes_size; i++)
    {
       move_node(model.nodes[i], (point_t &)move_vector);
    }

    return OK;
}

void rotate_node(node_t &node, const model_rotate_t &data, const point_t &rot_center)
{
    rotate_point(node.point, rot_center, data);
}

status_t rotate_model(model_t &model, const model_rotate_t &data)
{
    if (!validate_fields(model))
        return NOT_INIT_ERROR;

    point_t barycenter = find_model_barycenter(model.nodes, model.nodes_size);

    for (size_t i = 0; i < model.nodes_size; i++)
    {
        rotate_node(model.nodes[i], data, barycenter);
    }

    return OK;
}

point_t find_model_barycenter(node_t *nodes, size_t size)
{
    point_t coord_sum = init_point(0, 0, 0);

    for (int i = 0; i < size; i++)
    {
        coord_sum = add_points(nodes[i].point, coord_sum);
    }

    return divide_by_int(coord_sum, (int)size);
}
