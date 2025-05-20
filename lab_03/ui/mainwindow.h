#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../api/facade/Facade.hpp"

#include <QMainWindow>
#include <QGraphicsScene>


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
    void on_rotateFiguresButton_clicked();

    void on_TranslateFiguresButton_clicked();

    void on_scaleFiguresButton_clicked();

    void on_rotateCameraButton_clicked();

    void on_translateCameraButton_clicked();

    void on_loadFigureButton_clicked();

    void on_loadCameraButton_clicked();

    void on_loadSceneButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_clearSceneButton_clicked();

    void on_removeCameraButton_clicked();

private:
    // void sendRequest(Request& request);
    // void sendRequest(Request&& request);
    void initDefaultCamera();

    void clearList();
    void clearComboBox();

    void addListItem(size_t id, const QString& text);
    void addComboItem(size_t id, const QString& text);

    // void handleError(std::exception_ptr eptr);

    static std::string inputFile();

    Ui::MainWindow* ui;
    std::shared_ptr<QGraphicsScene> scene;
    std::shared_ptr<api::facade::Facade> facade;

    void updateCanvas();
};


#endif // MAINWINDOW_H
