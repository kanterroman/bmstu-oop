#include "model_vector.h"

model_vector_t init_model_vector(double x, double y, double z)
{
    model_vector_t vector;

    vector.x = x;
    vector.y = y;
    vector.z = z;

    return vector;
}
