#ifndef MODEL_VECTOR_H
#define MODEL_VECTOR_H

typedef struct model_vector
{
    double x;
    double y;
    double z;
} model_vector_t;

model_vector_t init_model_vector(double x, double y, double z);

#endif //MODEL_VECTOR_H
