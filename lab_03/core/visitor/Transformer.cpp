//
// Created by Roman Kanterov on 15.05.2025.
//

#include "Transformer.hpp"

namespace core {
namespace visitor {
void Transformer::transform(const std::shared_ptr<objects::BaseMatrixMeshFigureImpl>& fig)
{
    auto nodes = fig->getNodes();
    transformNodes(nodes);
    fig->setNodes(nodes);
}

void Transformer::transform(const std::shared_ptr<objects::BaseListMeshFigureImpl>& fig)
{
    auto nodes = fig->getNodes();
    transformNodes(nodes);
    fig->setNodes(nodes);
}

void Transformer::transform(std::shared_ptr<objects::BasePlainCameraImpl> fig)
{
    auto visPoint = fig->getVisPoint();
    visPoint += data.offset;
    double ax = fig->get_ax();
    double ay = fig->get_ay();
    double az = fig->get_az();
    ax += this->data.ax;
    ax += this->data.ay;
    ax += this->data.az;
    fig->set_vis_point(visPoint);
    fig->set_ax(ax);
    fig->set_ax(ay);
    fig->set_ax(az);
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
    Point barycenter = find_barycenter(points);
    Point offs = data.offset;
    data.offset = barycenter;
    move(points);

    std::vector<std::vector<double>> m = {{std::cos(data.ay)*std::cos(data.az), std::cos(data.ay)*-std::sin(data.az), std::sin(data.ay)},
                                         {std::sin(data.ax)*std::sin(data.ay)*std::cos(data.az) + std::cos(data.ax)*std::sin(data.ay),
                                         -std::sin(data.ax)*std::sin(data.ay)*std::sin(data.az)+std::cos(data.ax)*std::cos(data.az),
                                         -std::sin(data.ax)*std::cos(data.ay)},
                                         {std::sin(data.ax) * std::sin(data.az) - std::cos(data.ax)*std::sin(data.ay)*std::cos(data.az),
                                         std::sin(data.ax)*std::cos(data.az) + std::cos(data.ax)*std::sin(data.ay)*std::sin(data.az),
                                         std::cos(data.ax)*std::cos(data.ay)}};
    for (auto& point : points)
    {
        std::vector<double> pt = { point.x, point.y, point.z };
        for (auto i = 0; i < 3; i++)
            pt[i] = pt[0] * m[i][0] + pt[1] * m[i][1] + pt[2] * m[i][2];
        point.x = pt[0];
        point.y = pt[1];
        point.z = pt[2];
    }

    data.offset = -data.offset;
    move(points);
    data.offset = offs;
}

void Transformer::scale(std::vector<Point> &points)
{
    Point barycenter = find_barycenter(points);
    Point offs = data.offset;
    data.offset = barycenter;
    move(points);

    for (auto &point : points)
    {
        point *= data.multip;
    }

    data.offset = -data.offset;
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