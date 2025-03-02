#ifndef TASK_DATA_H
#define TASK_DATA_H

#include "operation_codes.h"

typedef struct move_data {
  int dx;
  int dy;
} move_data_t;

typedef struct rotate_data {
  int x_dg;
  int y_dg;
  int z_dg;
} rotate_data_t;

typedef struct scale_data {
  double scale_factor;
} scale_data_t;

typedef struct load_data {
  char *filepath;
} load_data_t;

typedef union task_data {
  move_data_t move_data;
  rotate_data_t rotate_data;
  scale_data_t scale_data;
  load_data_t load_data;
} task_data_t;

#endif //TASK_DATA_H
