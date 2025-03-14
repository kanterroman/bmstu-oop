#ifndef CANVAS_H
#define CANVAS_H

#include "model.h"
#include "status_codes.h"

typedef struct canvas *canvas_t;
canvas_t init_canvas();
status_t draw(const model_t &model, canvas_t canvas);
void destroy_canvas(canvas_t canvas);

#endif //CANVAS_H
