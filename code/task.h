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
} task_t;

#endif //TASK_H
