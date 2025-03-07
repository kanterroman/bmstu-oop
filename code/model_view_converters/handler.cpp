#include "handler.h"

#include "converters.h"
#include "file_input.h"
#include "model.h"
#include "drawer.h"

static status_t handle_move(model_t &model, const move_data_t &data);
static status_t handle_scale(model_t &model, const scale_data_t &data);
static status_t handle_rotate(model_t &model, const rotate_data_t &data);
static status_t handle_load(model_t &model, const char *filepath);
static void handle_destroy(model_t &model);
static status_t handle_draw(draw_data_t &data, const model_t &model);

status_t handle_task(task_t &task)
{
    status_t rc = OK;

    static model_t model;

    switch (task.operation)
    {
    case LOAD:
        rc = handle_load(model, task.load_data);
        break;
    case MOVE:
        rc = handle_move(model, task.move_data);
        break;
    case SCALE:
        rc = handle_scale(model, task.scale_data);
        break;
    case ROTATE:
        rc = handle_rotate(model, task.rotate_data);
        break;
    case QUIT:
        handle_destroy(model);
        break;
    }

    if (rc == OK && task.operation != QUIT)
        rc = handle_draw(task.draw_data, model);

    return rc;
}

status_t handle_move(model_t &model, const move_data_t &data)
{
    if (!fields_exist(model))
        return NOT_INIT_ERROR;

    point_t model_data = convert_move_data(data);
    move_model(model, model_data);

    return OK;
}

status_t handle_scale(model_t &model, const scale_data_t &data)
{
    if (!fields_exist(model))
        return NOT_INIT_ERROR;

    model_scale_t model_data = convert_scale_data(data);
    status_t rc = scale_model(model, model_data);

    return rc;
}

status_t handle_rotate(model_t &model, const rotate_data_t &data)
{
    if (!fields_exist(model))
        return NOT_INIT_ERROR;

    model_rotate_t model_data = convert_rotate_data(data);
    status_t rc = rotate_model(model, model_data);

    return rc;
}

status_t handle_load(model_t &model, const load_data_t filepath)
{
    if (!filepath)
        return FORMAT_ERROR;

    status_t rc = read_model(model, filepath);

    return rc;
}

void handle_destroy(model_t &model)
{
    destroy_model(model);
}

status_t handle_draw(draw_data_t &data, const model_t &model)
{
    if (!fields_exist(model))
        return NOT_INIT_ERROR;

    convert_draw_data(data, model);
    status_t rc = draw(data);
    clear_draw_data(data);

    return rc;
}
