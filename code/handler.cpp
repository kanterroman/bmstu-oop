#include "handler.h"

#include <stdio.h>
#include "converters.h"

status_t handle_move(const move_data_t &data);
status_t handle_scale(const scale_data_t &data);
status_t handle_rotate(const rotate_data_t &data);
status_t handle_load(const load_data_t &data);
void handle_destroy();
// status_t draw_model();

status_t handle_task(task_t &task)
{
    status_t rc = OK;

    switch (task.operation)
    {
    case MOVE:
        rc = handle_move(task.move_data);
    case SCALE:
        rc = handle_scale(task.scale_data);
    case ROTATE:
        rc = handle_rotate(task.rotate_data);
    case LOAD:
        rc = handle_load(task.load_data);
    case QUIT:
        handle_destroy();
    }

    // if (rc == OK && task.operation != QUIT) Хз пока
    //     draw_model();

    return rc;
}

status_t handle_move(const move_data_t &data)
{
    if (!model_exists())
        return ERROR;

    model_move_t model_data = convert_move_data(data);
    move_model(model_data);

    return OK;
}

status_t handle_scale(const scale_data_t &data)
{
    if (!model_exists())
        return ERROR;

    model_scale_t model_data = convert_scale_data(data);
    scale_model(model_data);

    return OK;
}

status_t handle_rotate(const rotate_data_t &data)
{
    if (!model_exists())
        return ERROR;

    model_rotate_t model_data = convert_rotate_data(data);
    rotate_model(model_data);

    return OK;
}

status_t handle_load(const load_data_t &data)
{
    FILE *src = fopen(data.filepath, "r");
    status_t rc = init_model(src);

    return rc;
}

void handle_destroy()
{
    destroy_model();
}
