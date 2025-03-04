#ifndef FILE_INPUT_H
#define FILE_INPUT_H

#include <stdio.h>
#include "status_codes.h"
#include "model.h"


status_t read_model(model_t &model, FILE *in);

#endif //FILE_INPUT_H
