#include "drawer.h"

#include "drawer_impl.h"

status_t draw(draw_data_t &data)
{
    if (!data.view)
        return GRAPHICS_ERROR;

    canvas_tools_t tools;
    init_canvas_tools(tools);
    draw_figure(tools, data);
    draw_on_screen(data, tools);
    destroy_canvas_tools(tools);

    return OK;
}
