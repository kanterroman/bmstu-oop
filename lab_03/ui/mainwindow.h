//
// Created by Roman Kanterov on 21.05.2025.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "../api/facade/Facade.hpp"

#include <QMainWindow>
#include <QGraphicsScene>
#include <QStandardItemModel>


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
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

protected:
    void showEvent(QShowEvent* event) override;

private slots:

    void on_load_btn_clicked();
    void on_remove_btn_clicked();
    void on_move_btn_clicked();
    void on_scale_btn_clicked();
    void on_rotate_btn_clicked();

private:
    // void transform();
    // void sendRequest(Request& request);
    // void sendRequest(Request&& request);
    // void initDefaultCamera();
    //
    // void clearList();
    // void clearComboBox();
    //
    // void addListItem(size_t id, const QString& text);
    // void addComboItem(size_t id, const QString& text);

    // void handleError(std::exception_ptr eptr);

    static std::string inputFile();

    Ui::MainWindow* ui;
    std::shared_ptr<QGraphicsScene> scene;
    std::shared_ptr<api::facade::Facade> facade;
    QStandardItemModel model;
    QStandardItemModel comboModel;

    void updateCanvas();
    void initCam();
};
#endif //MAINWINDOW_H
