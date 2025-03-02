#ifndef TASK_H
#define TASK_H

#include "operation_codes.h"
#include "task_data.h"

typedef struct task
{
    operation_t operation;
    task_data_t data;
} task_t;

#endif //TASK_H
