#include "mainwindow.h"

#include <QMessageBox>
#include "ui_mainwindow.h"
#include "status_codes.h"
#include "operation_codes.h"
#include "task_data.h"

void MainWindow::show_error(status_t rc) {
  switch (rc) {
  case ERROR:
    QMessageBox::about(ui->centralwidget, "", "NOT OK!");
  default:
    break;
  }
}

status_t handle_task(operation_t operation, task_data_t &task_data) {
  switch (operation) {
  case MOVE:
    return OK;
  default:
    return ERROR;
  }
}

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_move_btn_clicked() {
  int dx = ui->spinBox_x->value();
  int dy = ui->spinBox_x->value();

  task_data_t *task_data = form_task_data(MOVE, dx, dy);

  status_t rc = handle_task(MOVE, *task_data);

  destroy_task_data(task_data);

  if (rc != OK)
    show_error(rc);
}

void MainWindow::on_scale_btn_clicked() {
  double scale_factor = ui->lineEdit->text().toDouble();

  task_data_t *task_data = form_task_data(SCALE, scale_factor);

  status_t rc = handle_task(SCALE, *task_data);

  destroy_task_data(task_data);

  if (rc != OK)
    show_error(rc);
}

void MainWindow::on_rotate_btn_clicked() {
  int x_dg = ui->spinBox_xdg->value();
  int y_dg = ui->spinBox_ydg->value();
  int z_dg = ui->spinBox_zdg->value();

  task_data_t *task_data = form_task_data(ROTATE, x_dg, y_dg, z_dg);

  status_t rc = handle_task(ROTATE, *task_data);

  destroy_task_data(task_data);

  if (rc != OK)
    show_error(rc);
}

void MainWindow::on_load_btn_clicked() {
  char *text = ui->filepath->text().toLocal8Bit().data();

  task_data_t *task_data = form_task_data(LOAD, text);

  status_t rc = handle_task(LOAD, *task_data);

  destroy_task_data(task_data);

  if (rc != OK)
    show_error(rc);
}