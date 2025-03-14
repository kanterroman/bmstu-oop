#include "handler.h"

#include "converters.h"
#include "drawer.h"
#include "file_input.h"
#include "model.h"

static status_t handle_move(model_t &model, const move_data_t &data);
static status_t handle_scale(model_t &model, const scale_data_t &data);
static status_t handle_rotate(model_t &model, const rotate_data_t &data);
static status_t handle_load(model_t &model, const char *filepath);
static void handle_destroy(model_t &model, canvas_t canvas);
static status_t handle_draw(canvas_t canvas, const model_t &model);

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
    case DRAW:
        rc = handle_draw(task.canvas, model);
        break;
    case QUIT:
        handle_destroy(model, task.canvas);
        break;
    }

    return rc;
}

static status_t handle_move(model_t &model, const move_data_t &data)
{
    if (!fields_exist(model))
        return NOT_INIT_ERROR;

    point_t model_data = convert_move_data(data);
    move_model(model, model_data);

    return OK;
}

static status_t handle_scale(model_t &model, const scale_data_t &data)
{
    if (!fields_exist(model))
        return NOT_INIT_ERROR;

    model_scale_t model_data = convert_scale_data(data);
    status_t rc = scale_model(model, model_data);

    return rc;
}

static status_t handle_rotate(model_t &model, const rotate_data_t &data)
{
    if (!fields_exist(model))
        return NOT_INIT_ERROR;

    model_rotate_t model_data = convert_rotate_data(data);
    status_t rc = rotate_model(model, model_data);

    return rc;
}

static status_t handle_load(model_t &model, const load_data_t filepath)
{
    if (!filepath)
        return FORMAT_ERROR;

    status_t rc = read_model(model, filepath);

    return rc;
}

static void handle_destroy(model_t &model, canvas_t canvas)
{
    destroy_model(model);
    destroy_canvas(canvas);
}

static status_t handle_draw(canvas_t canvas, const model_t &model)
{
    if (!fields_exist(model) || !canvas)
        return NOT_INIT_ERROR;

    status_t rc = draw(model, canvas);

    return rc;
}
