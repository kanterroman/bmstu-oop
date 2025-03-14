#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "status_codes.h"
#include "task.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

  private slots:
    void on_move_btn_clicked();
    void on_scale_btn_clicked();
    void on_rotate_btn_clicked();
    void on_load_btn_clicked();

  private:
    void send_draw();
    void show_error_desc(status_t rc);
    void show_warning(const char *error_string);
    Ui::MainWindow *ui;
    task_t task;
};

#endif // MAINWINDOW_H
