#include "task_data.h"

#include <cstdlib>

task_data_t* form_task_data(operation_t operation, ...) {
  return (task_data_t*)malloc(sizeof(task_data_t));
}

void destroy_task_data(task_data_t *task_data) {
  free(task_data);
}
