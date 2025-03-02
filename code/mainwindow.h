#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "status_codes.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
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
  void show_error(status_t rc);
  Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
