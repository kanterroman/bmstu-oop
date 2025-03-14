#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "drawer.h"
#include "handler.h"
#include <QMessageBox>

#define IMAGE_COLOR_R 255
#define IMAGE_COLOR_G 255
#define IMAGE_COLOR_B 255

#define WIDTH 1200
#define HEIGHT 800

#define MODEL_COLOR_R 0
#define MODEL_COLOR_G 0
#define MODEL_COLOR_B 0

struct canvas
{
    QGraphicsView *view;
    QImage *image;
    QPainter *painter;
};

bool validate_canvas(canvas_t canvas)
{
    return canvas && canvas->view;
}

status_t init_drawer_tools(canvas_t canvas)
{
    if (!validate_canvas(canvas))
        return NOT_INIT_ERROR;

    status_t rc = OK;

    canvas->image = new(std::nothrow) QImage(WIDTH, HEIGHT, QImage::Format_RGB32);
    canvas->image->fill(QColor(IMAGE_COLOR_R, IMAGE_COLOR_G, IMAGE_COLOR_B));
    canvas->painter = new(std::nothrow) QPainter(canvas->image);
    canvas->painter->setPen(QColor(MODEL_COLOR_R, MODEL_COLOR_G, MODEL_COLOR_B));

    if (!canvas->painter || !canvas->image)
        rc = MALLOC_ERROR;

    return rc;
}

canvas_t init_canvas()
{
    return (canvas_t)malloc(sizeof(canvas));
}

void init_canvas_(QGraphicsView *view, canvas_t canvas)
{
    if (canvas)
    {
        canvas->view = view;
        init_drawer_tools(canvas);
    }
}

void destroy_painter(QPainter *painter)
{
    if (painter)
        painter->end();
    delete painter;
}

void destroy_drawer_tools(canvas_t canvas)
{
    if (canvas)
    {
        destroy_painter(canvas->painter);
        delete canvas->image;
        canvas->painter = NULL;
        canvas->image = NULL;
    }
}

QPointF to_qpointf(point_t &point)
{
    QPointF pt = QPointF(point.x, point.y);
    return pt;
}

status_t draw_line(canvas_t canvas, point_t &beg, point_t &end)
{
    if (!validate_canvas(canvas) || !canvas->painter)
        return NOT_INIT_ERROR;
    QPointF first = to_qpointf(beg);
    QPointF second = to_qpointf(end);
    canvas->painter->drawLine(first, second);
    return OK;
}

status_t refresh_canvas(canvas_t canvas)
{
    if (!canvas->image)
        return NOT_INIT_ERROR;
    canvas->image->fill(QColor(IMAGE_COLOR_R, IMAGE_COLOR_G, IMAGE_COLOR_B));
    return OK;
}

status_t draw_ellipse(canvas_t canvas, point_t &center, double rad)
{
    if (!validate_canvas(canvas) || !canvas->painter)
        return NOT_INIT_ERROR;
    QPointF ctr = to_qpointf(center);
    canvas->painter->drawEllipse(ctr, rad, rad);
    return OK;
}

void refresh_scene(QGraphicsScene *scene, QPixmap &pixmap)
{
    if (scene)
    {
        scene->clear();
        scene->addPixmap(pixmap);
    }
}

void display_model(canvas_t canvas)
{
    QPixmap pixmap = QPixmap::fromImage(*canvas->image);
    refresh_scene(canvas->view->scene(), pixmap);
}

void destroy_canvas(canvas_t canvas)
{
    destroy_drawer_tools(canvas);
    free(canvas);
}

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

    task.canvas = init_canvas();
    init_canvas_(ui->graphicsView, task.canvas);
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
    else
        send_draw();
}

void MainWindow::on_scale_btn_clicked()
{
    double scale_factor = ui->lineEdit->text().toDouble();

    task.operation = SCALE;
    task.scale_data = init_scale_task(scale_factor);

    status_t rc = handle_task(task);

    if (rc != OK)
        show_error_desc(rc);
    else
        send_draw();
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
    else
        send_draw();
}

void MainWindow::on_load_btn_clicked()
{
    const char *text = ui->filepath->text().toStdString().c_str();

    task.operation = LOAD;
    task.load_data = init_load_task(text);

    status_t rc = handle_task(task);

    if (rc != OK)
        show_error_desc(rc);
    else
        send_draw();
}

void MainWindow::send_draw()
{
    task.operation = DRAW;
    status_t rc = handle_task(task);
    if (rc != OK)
        show_error_desc(rc);
}
