#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include "handler.h"

void MainWindow::show_warning(const char *error_string)
{
    QMessageBox::warning(ui->centralwidget, "", error_string);
}

void MainWindow::show_error_desc(const status_t rc)
{
    switch (rc)
    {
    case OK:
        break;
    case NOT_INIT_ERROR:
        show_warning("Загрузите модель");
        break;
    case MALLOC_ERROR:
        show_warning("Ошибка при выделении памяти");
        break;
    case FILE_ERROR:
        show_warning("Ошибка при открытии файла");
        break;
    case FILE_FORMAT_ERROR:
        show_warning("Ошибка при чтении файла");
        break;
    case ZERO_DIVISION_ERROR:
        show_warning("При выполнении произошло деление на ноль");
        break;
    case WRONG_SCALE_ERROR:
        show_warning("Множитель масштабирования должен быть больше 0");
        break;
    case WRONG_ARGS_ERROR:
        show_warning("Некорректное поведение программы");
        break;
    case GRAPHICS_ERROR:
        show_warning("Графическое окно неинициализировано");
        break;
    case FORMAT_ERROR:
        show_warning("Модель должна иметь хотя бы одну точку");
        break;
    default:
        show_warning("Неизвестная ошибка");
        break;
    }
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto *scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);

    QRegularExpression regExp("[0-9]+\.[0-9]*");
    auto *validator = new QRegularExpressionValidator(regExp, ui->lineEdit);

    ui->lineEdit->setValidator(validator);

    task.draw_data = init_draw_task(ui->graphicsView);
}

MainWindow::~MainWindow()
{
    task.operation = QUIT;
    handle_task(task);
    delete ui->graphicsView->scene();
    delete ui->lineEdit->validator();
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
        show_error_desc(rc);
}

void MainWindow::on_scale_btn_clicked()
{
    double scale_factor = ui->lineEdit->text().toDouble();

    task.operation = SCALE;
    task.scale_data = init_scale_task(scale_factor);

    status_t rc = handle_task(task);

    if (rc != OK)
        show_error_desc(rc);
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
        show_error_desc(rc);
}

void MainWindow::on_load_btn_clicked()
{
    const char *text = ui->filepath->text().toStdString().c_str();

    task.operation = LOAD;
    task.load_data = init_load_task(text);

    status_t rc = handle_task(task);

    if (rc != OK)
        show_error_desc(rc);
}
