#ifndef CONVERTERS_H
#define CONVERTERS_H

#include "model_vector.h"
#include "task_data.h"
#include "model_data.h"

typedef model_vector_t model_move_t;

model_move_t convert_move_data(const move_data_t &data);
model_rotate_t convert_rotate_data(const rotate_data_t &data);
model_scale_t convert_scale_data(const scale_data_t &data);


#endif //CONVERTERS_H
