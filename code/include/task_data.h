#ifndef TASK_DATA_H
#define TASK_DATA_H

#include <QLineF>
#include <QList>
#include <QGraphicsView>

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

typedef const char *load_data_t;

typedef struct draw_data {
    QList<QLineF> edges;
    const QGraphicsView *view;
} draw_data_t;

#endif //TASK_DATA_H
