#ifndef MODEL_H
#define MODEL_H

#include <stddef.h>
#include "model_data.h"
#include "point.h"
#include "status_codes.h"

typedef struct edge
{
    size_t first;
    size_t second;
} edge_t;

edge_t init_edge(const int first, const int second);

typedef struct model
{
    point_t *points;
    size_t points_size;
    edge_t *edges;
    size_t edges_size;
} model_t;

status_t init_model(model_t &model, const size_t points_num, const size_t edges_num);
void destroy_model(const model_t &model);

status_t append_point(model_t &model, const point_t &point);
status_t append_edge(model_t &model, const edge_t &edge);

status_t scale_model(model_t &model, const model_scale_t &data);
status_t move_model(model_t &model, const point_t &move_vector);
status_t rotate_model(model_t &model, const model_rotate_t &data);

bool fields_exist(const model_t &model);

#endif //MODEL_H
