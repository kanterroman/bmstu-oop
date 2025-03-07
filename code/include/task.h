#ifndef TASK_H
#define TASK_H

#include "operation_codes.h"
#include "task_data.h"

typedef struct task
{
    operation_t operation;
    move_data_t move_data;
    rotate_data_t rotate_data;
    scale_data_t scale_data;
    load_data_t load_data;
    draw_data_t draw_data;
} task_t;

move_data_t init_move_task(const int dx, const int dy);
rotate_data_t init_rotate_task(const int dx, const int dy, const int dz);
scale_data_t init_scale_task(const double factor);
load_data_t init_load_task(const char *filepath);
draw_data_t init_draw_task(const QGraphicsView *view);
void clear_draw_data(draw_data_t &data);

#endif //TASK_H
