#include "drawer.h"

#define POINT_RADIUS 2

void display_model(canvas_t canvas);
status_t draw_figure(const model_t &model, canvas_t canvas);
status_t init_drawer_tools(canvas_t canvas);
void destroy_drawer_tools(canvas_t canvas);
bool validate_canvas(canvas_t canvas);
status_t draw_ellipse(canvas_t canvas, point_t &center, double rad);
status_t draw_line(canvas_t canvas, point_t &beg, point_t &end);
status_t refresh_canvas(canvas_t canvas);

status_t draw(const model_t &model, canvas_t canvas)
{
    if (!validate_canvas(canvas) || !fields_exist(model))
        return NOT_INIT_ERROR;
    status_t rc = OK;

    if (rc == OK)
        rc = draw_figure(model, canvas);
    if (rc == OK)
        display_model(canvas);

    return OK;
}

status_t draw_figure(const model_t &model, canvas_t canvas)
{
    if (!validate_canvas(canvas))
        return NOT_INIT_ERROR;
    status_t rc = OK;

    rc = refresh_canvas(canvas);
    for (int i = 0; i < model.edges_size && rc == OK; i++)
    {
        point_t first = model.points[model.edges[i].first - 1];
        point_t second = model.points[model.edges[i].second - 1];
        rc = draw_line(canvas, first, second);
        if (rc == OK)
            rc = draw_ellipse(canvas, first, POINT_RADIUS);
        if (rc == OK)
            rc = draw_ellipse(canvas, second, POINT_RADIUS);
    }

    return rc;
}
