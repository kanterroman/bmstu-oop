#include "mainwindow.h"

#include "ui_mainwindow.h"
#include <QMessageBox>
#include "handler.h"

void MainWindow::show_error(status_t rc)
{
    switch (rc)
    {
    case ERROR:
        QMessageBox::about(ui->centralwidget, "", "NOT OK!");
    default:
        break;
    }
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    task.operation = QUIT;
    handle_task(task);
    delete ui;
}

void MainWindow::on_move_btn_clicked()
{
    int dx = ui->spinBox_x->value();
    int dy = ui->spinBox_x->value();

    task.operation = MOVE;
    task.move_data.dx = dx;
    task.move_data.dy = dy;

    status_t rc = handle_task(task);

    if (rc != OK)
        show_error(rc);
}

void MainWindow::on_scale_btn_clicked()
{
    double scale_factor = ui->lineEdit->text().toDouble();

    task.operation = SCALE;
    task.scale_data.scale_factor = scale_factor;

    status_t rc = handle_task(task);

    if (rc != OK)
        show_error(rc);
}

void MainWindow::on_rotate_btn_clicked()
{
    int x_dg = ui->spinBox_xdg->value();
    int y_dg = ui->spinBox_ydg->value();
    int z_dg = ui->spinBox_zdg->value();

    task.operation = ROTATE;
    task.rotate_data.x_dg = x_dg;
    task.rotate_data.y_dg = y_dg;
    task.rotate_data.z_dg = z_dg;

    status_t rc = handle_task(task);

    if (rc != OK)
        show_error(rc);
}

void MainWindow::on_load_btn_clicked()
{
    char *text = ui->filepath->text().toLocal8Bit().data();

    task.operation = LOAD;
    task.load_data.filepath = text;

    status_t rc = handle_task(task);

    if (rc != OK)
        show_error(rc);
}