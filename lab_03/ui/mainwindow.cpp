#include "mainwindow.h"

#include <iostream>
#include <QMessageBox>

// #include "BaseFigure.hpp"
// #include "InvalidFileStructure.hpp"
// #include "QtFactory.hpp"
#include "QCheckBox"
#include "QFileDialog"
#include "ui_mainwindow.h"
// #include "RemoveCamera.hpp"
// #include "requests/RemoveFigure.hpp"
// #include "RotateActiveCamera.hpp"
// #include "RotateSelected.hpp"
// #include "ScaleSelected.hpp"
// #include "TranslateActiveCamera.hpp"
// #include "TranslateSelected.hpp"
// #include "UnsupportedFIleType.hpp"
#include "../api/commands/ChangeCameraCommand.hpp"
#include "../api/commands/DrawCommand.hpp"
#include "../api/commands/LoadCommand.hpp"
#include "../api/commands/SelectCommand.hpp"
#include "../api/commands/TransformActiveCameraCommand.hpp"
#include "../api/commands/TransformCommand.hpp"
#include "../api/commands/UnselectCommand.hpp"
// #include "requests/ClearScene.hpp"
// #include "requests/DrawScene.hpp"
// #include "requests/LoadCamera.hpp"
// #include "requests/LoadFigure.hpp"
// #include "requests/LoadScene.hpp"
// #include "requests/SelectEntity.hpp"
// #include "requests/SetActiveCamera.hpp"
// #include "requests/UnselectEntity.hpp"


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = std::make_shared<QGraphicsScene>(this);
    scene->setBackgroundBrush(QBrush(QColor(0xFFFFFF)));

    ui->graphicsView->setScene(scene.get());
    facade = std::make_shared<api::facade::Facade>(scene);
    // initDefaultCamera();
}


void MainWindow::showEvent(QShowEvent* event)
{
    QMainWindow::showEvent(event);
    scene->setSceneRect(QRectF(QPointF(0, 0), ui->graphicsView->size()));
    updateCanvas();
}


void MainWindow::on_rotateFiguresButton_clicked()
{
    TransformData data = { ui->FigureXRot->value(), ui->FigureYRot->value(),
        ui->FigureZRot->value() };
    auto command = std::make_shared<api::commands::TransformCommand>(data);
    facade->execute(command);
    updateCanvas();
}


void MainWindow::on_TranslateFiguresButton_clicked()
{
    core::Point offset = { ui->FigureXTranslation->value(), ui->FigureYTranslation->value(),
        ui->FigureZTranslation->value() };
    TransformData data = { .offset = offset };
    auto command = std::make_shared<api::commands::TransformCommand>(data);
    facade->execute(command);
    updateCanvas();
}


void MainWindow::on_scaleFiguresButton_clicked()
{
    TransformData data = { .multip = ui->FigureXScale->value() };
    auto command = std::make_shared<api::commands::TransformCommand>(data);
    facade->execute(command);
    updateCanvas();
}


void MainWindow::updateCanvas()
{
    ui->graphicsView->scene()->clear();
    auto command = std::make_shared<api::commands::DrawCommand>();
    facade->execute(command);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_rotateCameraButton_clicked()
{
    TransformData data = { ui->CameraXRot->value(),
        ui->CameraYRot->value(),
        ui->CameraZRot->value() };
    auto command = std::make_shared<api::commands::TransformActiveCameraCommand>(data);
    facade->execute(command);
    updateCanvas();
}


void MainWindow::on_translateCameraButton_clicked()
{
    core::Point offset = { ui->CameraXTranslation->value(),
        ui->CameraYTranslation->value(),
        ui->CameraZTranslation->value() };
    TransformData data = { .offset = offset };
    auto command = std::make_shared<api::commands::TransformActiveCameraCommand>(data);
    facade->execute(command);
    updateCanvas();
}


void MainWindow::on_loadFigureButton_clicked()
{
    std::string filepath = inputFile();
    if (filepath.empty())
        return;

    auto command = std::make_shared<api::commands::LoadCommand>(filepath);

    facade->execute(command);
    auto id = core::objects::SceneObject::count - 1;
    auto name = std::format("Figure {} ({})", std::to_string(id),
                                std::filesystem::path(filepath).filename().c_str());
    addComboItem(id, name.c_str());
    addListItem(id, name.c_str());
    updateCanvas();
}


void MainWindow::on_loadCameraButton_clicked()
{
    std::string filepath = inputFile();
    if (filepath.empty())
        return;

    auto command = std::make_shared<api::commands::LoadCommand>(filepath);

    facade->execute(command);
    auto id = core::objects::SceneObject::count - 1;
    auto name = std::format("Figure {} ({})", std::to_string(id),
                                std::filesystem::path(filepath).filename().c_str());
    addComboItem(id, name.c_str());
    addListItem(id, name.c_str());
    updateCanvas();

    if (ui->removeCameraButton->isEnabled() == false)
        ui->removeCameraButton->setEnabled(true);
}


void MainWindow::on_loadSceneButton_clicked()
{
    std::string filepath = inputFile();
    if (filepath.empty())
        return;

    auto command = std::make_shared<api::commands::LoadCommand>(filepath);


    facade->execute(command);
    auto id = core::objects::SceneObject::count - 1;
    auto name = std::format("Figure {} ({})", std::to_string(id),
                                std::filesystem::path(filepath).filename().c_str());
    addComboItem(id, name.c_str());
    addListItem(id, name.c_str());
    updateCanvas();
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if (index >= 0)
    {
        size_t selectedId = ui->comboBox->currentData().toInt();
        auto command = std::make_shared<api::commands::ChangeCameraCommand>(selectedId);
        facade->execute(command);
        updateCanvas();
    }
}


void MainWindow::on_clearSceneButton_clicked()
{
    // sendRequest(ClearScene());
    // updateCanvas();
    // clearList();
    // clearComboBox();
}


void MainWindow::on_removeCameraButton_clicked()
{
    // size_t removeId = ui->comboBox->currentData().toULongLong();
    // ui->comboBox->removeItem(ui->comboBox->currentIndex());
    // sendRequest(RemoveCamera(removeId));
    //
    // if (ui->comboBox->count() == 1)
    //     ui->removeCameraButton->setDisabled(true);
    //
    // updateCanvas();
}


// void MainWindow::sendRequest(Request& request)
// {
//     std::exception_ptr eptr;
//     try
//     {
//         _api.handle(request);
//     }
//     catch (...)
//     {
//         eptr = std::current_exception();
//     }
//     handleError(eptr);
// }


// void MainWindow::sendRequest(Request&& request)
// {
//     sendRequest(request);
// }


void MainWindow::initDefaultCamera()
{
    constexpr char DEFAULT_CAMERA_FILE[] = "../data/default_camera.obj";

    // auto command = std::make_shared<api::commands::LoadCommand>(DEFAULT_CAMERA_FILE);
    // facade->execute(command);
    // auto command1 = std::make_shared<api::commands::ChangeCameraCommand>(0);
    // facade->execute(command1);

    ui->comboBox->setCurrentIndex(0);
}


void MainWindow::clearList()
{
    ui->listWidget->clear();
}


void MainWindow::clearComboBox()
{
    ui->comboBox->clear();
}


void MainWindow::addListItem(const size_t id, const QString& text)
{
    QWidget* itemWidget = new QWidget();
    itemWidget->setProperty("id", QVariant::fromValue(id));

    QHBoxLayout* layout = new QHBoxLayout(itemWidget);

    QCheckBox* checkBox = new QCheckBox(itemWidget);
    QLabel* label = new QLabel(text, itemWidget);
    QPushButton* button = new QPushButton("✖", itemWidget);
    button->setFixedSize(24, 24);

    layout->addWidget(checkBox);
    layout->addWidget(label);
    layout->addWidget(button);

    QListWidgetItem* item = new QListWidgetItem();
    item->setSizeHint(itemWidget->sizeHint());
    ui->listWidget->addItem(item);
    ui->listWidget->setItemWidget(item, itemWidget);

    // connect(button, &QPushButton::clicked, [this, id]()
    // {
    //     sendRequest(RemoveFigure(id));
    //     for (int i = 0; i < ui->listWidget->count(); ++i)
    //     {
    //         QWidget* widget = ui->listWidget->itemWidget(ui->listWidget->item(i));
    //         if (widget && widget->property("id").toULongLong() == id)
    //         {
    //             delete ui->listWidget->takeItem(i);
    //             break;
    //         }
    //     }
    //     updateCanvas();
    // });

    connect(checkBox, &QCheckBox::stateChanged, [this, id](int state) {
        if (state == Qt::Checked)
        {
            auto command = std::make_shared<api::commands::SelectCommand>(id);
            facade->execute(command);
        }
        else
        {
            auto command = std::make_shared<api::commands::UnselectCommand>(id);
            facade->execute(command);
        }
    });
    // });
}


void MainWindow::addComboItem(size_t id, const QString& text)
{
    ui->comboBox->addItem(text, QVariant::fromValue(id)); // Сохраняем ID в userData
}


// void MainWindow::handleError(std::exception_ptr eptr)
// {
//     try
//     {
//         if (eptr)
//             std::rethrow_exception(eptr);
//     }
//     catch (const io::exceptions::InvalidFileStructure&)
//     {
//         QMessageBox::warning(this, "Ошибка чтения", "Неверная структура файла");
//     }
//     catch (const io::exceptions::UnsupportedFileType&)
//     {
//         QMessageBox::warning(this, "Ошибка чтения", "Не поддерживаемый формат файла");
//     }
//     catch (const io::exceptions::IOException& e)
//     {
//         QMessageBox::warning(this, "Ошибка чтения", "Не удалось прочесть файл");
//         std::cerr << e.what() << std::endl;
//     }
//     catch (std::exception& e)
//     {
//         QMessageBox::critical(this, "Системная ошибка", "Неизвестная ошибка системы");
//         std::cerr << e.what() << std::endl;
//     }
// }


std::string MainWindow::inputFile()
{
    QByteArray filepath = QFileDialog::getOpenFileName(
        nullptr,
        "Выберите файл",
        "/Users/mkholkin/BMSTU/2k/2s/OOP/lab_03/",
        "(*.txt *.obj)"
    ).toLatin1();

    return filepath.toStdString();
}
