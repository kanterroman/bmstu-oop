#include "mainwindow.h"

#include "../api/commands/ChangeCameraCommand.hpp"
#include "../cmake-build-debug/app1.exe_autogen/include/ui_mainwindow.h"
#include "../api/commands/DrawCommand.hpp"
#include "../api/commands/LoadCommand.hpp"
#include "../api/commands/RemoveObjectCommand.hpp"
#include "../api/commands/SelectCommand.hpp"
#include "../api/commands/TransformCommand.hpp"
#include "../api/commands/UnselectCommand.hpp"
#include "../api/exceptions/NotACameraException.hpp"

#include <QFileDialog>
#include <QStandardItemModel>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->listView->setModel(&model);
    ui->comboBox->setModel(&comboModel);
    QItemSelectionModel *selectionModel = ui->listView->selectionModel();
    QObject::connect(selectionModel, &QItemSelectionModel::selectionChanged,
                         [&](const QItemSelection &selected, const QItemSelection &deselected) {
            for (const QModelIndex &index : selected.indexes()) {
                QString text = index.data(Qt::DisplayRole).toString();
                int id = index.data(Qt::UserRole).toInt();
                auto command = std::make_shared<api::commands::SelectCommand>(id);
                facade->execute(command);
            }

            for (const QModelIndex &index : deselected.indexes()) {
                QString text = index.data(Qt::DisplayRole).toString();
                int id = index.data(Qt::UserRole).toInt();
                auto command = std::make_shared<api::commands::UnselectCommand>(id);
                facade->execute(command);
            }
    });

    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
        [this](int index) {

    if (index >= 0) {
        int id = ui->comboBox->itemData(index).toInt();

        auto command = std::make_shared<api::commands::ChangeCameraCommand>(id);
        try
        {
            facade->execute(command);
            updateCanvas();
        } catch (api::exceptions::NotACameraException &e)
        {
            ui->comboBox->blockSignals(true);

            ui->comboBox->removeItem(index);

            if (ui->comboBox->count() > 0) {
                ui->comboBox->setCurrentIndex(qMax(0, index-1));
            }

            ui->comboBox->blockSignals(false);
        }
    }
});


    scene = std::make_shared<QGraphicsScene>(this);
    scene->setBackgroundBrush(QBrush(QColor(0xFFFFFF)));

    ui->graphicsView->setScene(scene.get());
    facade = std::make_shared<api::facade::Facade>(scene);
    initCam();
}


void MainWindow::showEvent(QShowEvent* event)
{
    QMainWindow::showEvent(event);
    scene->setSceneRect(QRectF(QPointF(0, 0), ui->graphicsView->size()));
    updateCanvas();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_load_btn_clicked()
{
    std::string filepath = inputFile();

    auto command = std::make_shared<api::commands::LoadCommand>(filepath);
    facade->execute(command);


    auto id = core::objects::SceneObject::currentId() - 1;
    auto item = new QStandardItem();

    std::filesystem::path p(filepath);
    auto str = QString("%1 %2").arg(p.filename().string()).arg(id);
    item->setData(str, Qt::DisplayRole);
    item->setData(id, Qt::UserRole);
    model.appendRow(item);

    auto itemc = new QStandardItem();

    itemc->setData(str, Qt::DisplayRole);
    itemc->setData(id, Qt::UserRole);
    comboModel.appendRow(itemc);
    updateCanvas();
}

void MainWindow::on_remove_btn_clicked()
{
    QItemSelectionModel *selectionModel = ui->listView->selectionModel();

    QModelIndexList selectedIndexes = selectionModel->selectedIndexes();

    for (const QModelIndex &index : selectedIndexes) {
        int id = index.data(Qt::UserRole).toInt();
        auto command = std::make_shared<api::commands::RemoveObjectCommand>(id);
        facade->execute(command);
        model.removeRow(index.row());
    }
    comboModel.removeRows(0, selectedIndexes.count());
    updateCanvas();
}

void MainWindow::on_move_btn_clicked()
{
    TransformData data = {};
    core::Point offset = { ui->x_box->value(), ui->y_box->value(), ui->z_box->value() };
    data.offset = offset;
    auto command = std::make_shared<api::commands::TransformCommand>(data);
    facade->execute(command);
    updateCanvas();
}

void MainWindow::on_scale_btn_clicked()
{
    TransformData data = {};
    data.multip = ui->x_box->value();
    auto command = std::make_shared<api::commands::TransformCommand>(data);
    facade->execute(command);
    updateCanvas();
}

void MainWindow::on_rotate_btn_clicked()
{
    TransformData data = { ui->x_box->value(), ui->y_box->value(), ui->z_box->value() };
    auto command = std::make_shared<api::commands::TransformCommand>(data);
    facade->execute(command);
    updateCanvas();
}


std::string MainWindow::inputFile()
{
    QByteArray filepath = QFileDialog::getOpenFileName(
        nullptr,
        "Выберите файл",
        "/Users/romankanterov/bmstu-oop/lab_03/data",
        "(*.txt *.obj)"
    ).toLatin1();

    return filepath.toStdString();
}

void MainWindow::updateCanvas()
{
    ui->graphicsView->scene()->clear();
    auto command = std::make_shared<api::commands::DrawCommand>();
    facade->execute(command);
}

void MainWindow::initCam()
{
    std::string filepath = "/Users/romankanterov/bmstu-oop/lab_03/data/default_camera.obj";

    auto command = std::make_shared<api::commands::LoadCommand>(filepath);
    facade->execute(command);

    auto id = core::objects::SceneObject::currentId() - 1;
    auto item = new QStandardItem();

    std::filesystem::path p(filepath);
    auto str = QString("%1 %2").arg(p.filename().string()).arg(id);
    item->setData(str, Qt::DisplayRole);  // Отображаемый текст
    item->setData(id, Qt::UserRole);  // Хранимое значение (size_t)
    model.appendRow(item);
    auto camCommand = std::make_shared<api::commands::ChangeCameraCommand>(id);
    facade->execute(camCommand);

    auto itemc = new QStandardItem();

    itemc->setData(str, Qt::DisplayRole);  // Отображаемый текст
    itemc->setData(id, Qt::UserRole);  // Хранимое значение (size_t)
    comboModel.appendRow(itemc);
    auto c1command = std::make_shared<api::commands::ChangeCameraCommand>(id);
    facade->execute(c1command);
    updateCanvas();
}

