//
// Created by Roman Kanterov on 15.05.2025.
//

#include "Transformer.hpp"
#include "BaseMatrixMeshFigureImpl.hpp"
#include "BasePlainCameraImpl.hpp"
#include "BaseListMeshFigureImpl.hpp"

namespace core {
namespace visitor {
void Transformer::transform(std::shared_ptr<objects::BaseMatrixMeshFigureImpl>& fig)
{
    auto nodes = fig->getNodes();
    transformNodes(nodes);
    fig->setNodes(nodes);
}

void Transformer::transform(std::shared_ptr<objects::BaseListMeshFigureImpl>& fig)
{
    auto nodes = fig->getNodes();
    transformNodes(nodes);
    fig->setNodes(nodes);
}

void Transformer::transform(std::shared_ptr<objects::BasePlainCameraImpl> fig)
{
    auto visPoint = fig->getVisPoint();
    visPoint += data.offset;
    fig->setVisPoint(visPoint);

    auto n = fig->getN();
    rotate(n);
    fig->set_n(n);
}

Point Transformer::find_barycenter(std::vector<Point> &points)
{
    Point barycenter{0, 0, 0};
    for (auto &point : points)
    {
        barycenter += point;
    }
    barycenter /= points.size();

    return barycenter;
}

void Transformer::move(std::vector<Point> &points)
{
    for (auto &point : points)
    {
        point += data.offset;
    }
}

void Transformer::rotate(std::vector<Point> &points)
{
    if (data.ax == 0 && data.ay == 0 && data.az == 0) {
        return;
    }
    data.ax = data.ax * M_PI / 180;
    data.ay = data.ay * M_PI / 180;
    data.az = data.az * M_PI / 180;

    Point barycenter = find_barycenter(points);

    Point old_offset = data.offset;
    data.offset = -barycenter;
    move(points);

    // Создаем отдельные матрицы для каждого поворота
    double cx = cos(data.ax), sx = sin(data.ax);
    double cy = cos(data.ay), sy = sin(data.ay);
    double cz = cos(data.az), sz = sin(data.az);

    // Матрица поворота (Z-Y-X порядок)
    std::vector<std::vector<double>> m = {
        {cy*cz, -cy*sz, sy},
        {cx*sz + sx*sy*cz, cx*cz - sx*sy*sz, -sx*cy},
        {sx*sz - cx*sy*cz, sx*cz + cx*sy*sz, cx*cy}
    };

    // Применяем поворот
    for (auto& point : points) {
        double x = point.x;
        double y = point.y;
        double z = point.z;

        point.x = x * m[0][0] + y * m[0][1] + z * m[0][2];
        point.y = x * m[1][0] + y * m[1][1] + z * m[1][2];
        point.z = x * m[2][0] + y * m[2][1] + z * m[2][2];
    }

    // Возвращаем объект на место
    data.offset = barycenter;
    move(points);
    data.offset = old_offset;
}

void Transformer::rotate(Vector<double> &v)
{
    if (data.ax == 0 && data.ay == 0 && data.az == 0) {
        return;
    }

    data.ax = data.ax * M_PI / 180;
    data.ay = data.ay * M_PI / 180;
    data.az = data.az * M_PI / 180;

    // Матрица поворота вокруг X
    double mx[3][3] = {
        {1, 0,       0},
        {0, cos(data.ax), sin(data.ax)},
        {0, -sin(data.ax), cos(data.ax)}
    };

    // Матрица поворота вокруг Y
    double my[3][3] = {
        {cos(data.ay),  0, -sin(data.ay)},
        {0,        1, 0},
        {sin(data.ay), 0, cos(data.ay)}
    };

    // Матрица поворота вокруг Z
    double mz[3][3] = {
        {cos(data.az), sin(data.az), 0},
        {-sin(data.az), cos(data.az),  0},
        {0,       0,        1}
    };

    // Применяем повороты в порядке Z -> Y -> X
    Vector<double> result{v};

    double x = result[0];
    double y = result[1];
    double z = result[2];
    // Поворот вокруг Z
    result = Vector<double>({
        x * mz[0][0] + y * mz[0][1] + z * mz[0][2],
        x * mz[1][0] + y * mz[1][1] + z * mz[1][2],
        x * mz[2][0] + y * mz[2][1] + z * mz[2][2]
    });

    x = result[0];
    y = result[1];
    z = result[2];
    // Поворот вокруг Y
    result = Vector<double>({
        x * my[0][0] + y * my[0][1] + z * my[0][2],
        x * my[1][0] + y * my[1][1] + z * my[1][2],
        x * my[2][0] + y * my[2][1] + z * my[2][2]
    });

    x = result[0];
    y = result[1];
    z = result[2];
    // Поворот вокруг X
    result = Vector<double>({
        x * mx[0][0] + y * mx[0][1] + z * mx[0][2],
        x * mx[1][0] + y * mx[1][1] + z * mx[1][2],
        x * mx[2][0] + y * mx[2][1] + z * mx[2][2]
    });

    v = result;
}
void Transformer::scale(std::vector<Point> &points)
{
    if (data.multip == 0)
        return;
    Point barycenter = find_barycenter(points);
    Point offs = data.offset;
    data.offset = -barycenter;
    move(points);

    for (auto &point : points)
    {
        point *= data.multip;
    }

    data.offset = barycenter;
    move(points);
    data.offset = offs;
}

void Transformer::transformNodes(std::vector<Point> &points)
{
    move(points);
    scale(points);
    rotate(points);
}
} // visitor
} // core