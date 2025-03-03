#include "mainwindow.h"

#include "ui_mainwindow.h"
#include <QMessageBox>
#include "handler.h"

#define WIDTH 800
#define HEIGHT 600

#define MODEL_COLOR_R 0
#define MODEL_COLOR_G 0
#define MODEL_COLOR_B 0

#define CANVAS_COLOR_R 255
#define CANVAS_COLOR_G 255
#define CANVAS_COLOR_B 255

#define NODE_RADIUS 3

// OK,
// ERROR,
// NOT_INIT_ERROR,
// MALLOC_ERROR,
// FILE_ERROR,
// FORMAT_ERROR

void MainWindow::show_error(status_t rc)
{
    switch (rc)
    {
    case NOT_INIT_ERROR:
        QMessageBox::about(ui->centralwidget, "", "Загрузите модель");
        break;
    case MALLOC_ERROR:
        QMessageBox::about(ui->centralwidget, "", "Ошибка при выделении памяти");
        break;
    case FILE_ERROR:
        QMessageBox::about(ui->centralwidget, "", "Ошибка при открытии файла");
        break;
    case FORMAT_ERROR:
        QMessageBox::about(ui->centralwidget, "", "Ошибка при чтении файла");
        break;
    default:
        QMessageBox::about(ui->centralwidget, "", "Huh");
        break;
    }
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto *scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    image = QImage(WIDTH, HEIGHT, QImage::Format_RGB32);
}

MainWindow::~MainWindow()
{
    task.operation = QUIT;
    handle_task(task);
    delete ui->graphicsView->scene();
    delete ui;
}

void MainWindow::on_move_btn_clicked()
{
    int dx = ui->spinBox_x->value();
    int dy = ui->spinBox_y->value();

    task.operation = MOVE;
    task.move_data = init_move_task(dx, dy);

    status_t rc = handle_task(task);

    if (rc != OK)
        show_error(rc);
    else
        draw(task.draw_data);
}

void MainWindow::on_scale_btn_clicked()
{
    double scale_factor = ui->lineEdit->text().toDouble();

    task.operation = SCALE;
    task.scale_data = init_scale_task(scale_factor);

    status_t rc = handle_task(task);

    if (rc != OK)
        show_error(rc);
    else
        draw(task.draw_data);
}

void MainWindow::on_rotate_btn_clicked()
{
    int x_dg = ui->spinBox_xdg->value();
    int y_dg = ui->spinBox_ydg->value();
    int z_dg = ui->spinBox_zdg->value();

    task.operation = ROTATE;
    task.rotate_data = init_rotate_task(x_dg, y_dg, z_dg);

    status_t rc = handle_task(task);

    if (rc != OK)
        show_error(rc);
    else
        draw(task.draw_data);
}

void MainWindow::on_load_btn_clicked()
{
    const char *text = ui->filepath->text().toStdString().c_str();

    task.operation = LOAD;
    task.load_data = init_load_task(text);

    status_t rc = handle_task(task);

    if (rc != OK)
        show_error(rc);
    else
        draw(task.draw_data);
}

void MainWindow::draw(draw_data_t &data)
{
    image.fill(QColor(CANVAS_COLOR_R, CANVAS_COLOR_G, CANVAS_COLOR_B));

    QPainter p(&image);
    p.setPen(QColor(MODEL_COLOR_R, MODEL_COLOR_G, MODEL_COLOR_B));

    for (auto edge : data.edges)
    {
        QPointF first = edge.p1();
        QPointF second = edge.p2();
        p.drawEllipse(first, NODE_RADIUS, NODE_RADIUS);
        p.drawEllipse(second, NODE_RADIUS, NODE_RADIUS);
        p.drawLine(edge);
    }

    p.end();

    QPixmap pixmap = QPixmap::fromImage(image);
    ui->graphicsView->scene()->clear();
    ui->graphicsView->scene()->addPixmap(pixmap);
    data.edges.clear();
}
