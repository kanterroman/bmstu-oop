#ifndef MODEL_H
#define MODEL_H

#include <stddef.h>
#include "model_data.h"
#include "point.h"
#include "status_codes.h"

typedef struct node
{
    point_t point;
} node_t;

typedef struct edge
{
    size_t first;
    size_t second;
} edge_t;

typedef struct model
{
    node_t *nodes;
    size_t nodes_size;
    edge_t *edges;
    size_t edges_size;
} model_t;

node_t init_node(const point_t &point);
edge_t init_edge(int first, int second);

bool fields_exist(const model_t &model);
status_t init_model(model_t &model, size_t nodes_num, size_t edges_num);
status_t add_node(model_t &model, const node_t &node);
status_t add_edge(model_t &model, const edge_t &edge);
void destroy_model(const model_t &model);
status_t scale_model(model_t &model, const model_scale_t &data);
status_t move_model(model_t &model, const point_t &move_vector);
status_t rotate_model(model_t &model, const model_rotate_t &data);


#endif //MODEL_H
