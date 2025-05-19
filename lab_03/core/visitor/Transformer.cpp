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
    visPoint += offset;
    double ax = fig->get_ax();
    double ay = fig->get_ay();
    double az = fig->get_az();
    ax += this->ax;
    ax += this->ay;
    ax += this->az;
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
        point += offset;
    }
}

void Transformer::rotate(std::vector<Point> &points)
{
    Point barycenter = find_barycenter(points);
    Point offs = offset;
    offset = barycenter;
    move(points);

    std::vector<std::vector<double>> m = {{std::cos(ay)*std::cos(az), std::cos(ay)*-std::sin(az), std::sin(ay)},
                                         {std::sin(ax)*std::sin(ay)*std::cos(az) + std::cos(ax)*std::sin(ay),
                                         -std::sin(ax)*std::sin(ay)*std::sin(az)+std::cos(ax)*std::cos(az),
                                         -std::sin(ax)*std::cos(ay)},
                                         {std::sin(ax) * std::sin(az) - std::cos(ax)*std::sin(ay)*std::cos(az),
                                         std::sin(ax)*std::cos(az) + std::cos(ax)*std::sin(ay)*std::sin(az),
                                         std::cos(ax)*std::cos(ay)}};
    for (auto& point : points)
    {
        std::vector<double> pt = { point.x, point.y, point.z };
        for (auto i = 0; i < 3; i++)
            pt[i] = pt[0] * m[i][0] + pt[1] * m[i][1] + pt[2] * m[i][2];
        point.x = pt[0];
        point.y = pt[1];
        point.z = pt[2];
    }

    offset = -offset;
    move(points);
    offset = offs;
}

void Transformer::scale(std::vector<Point> &points)
{
    Point barycenter = find_barycenter(points);
    Point offs = offset;
    offset = barycenter;
    move(points);

    for (auto &point : points)
    {
        point *= multip;
    }

    offset = -offset;
    move(points);
    offset = offs;
}

void Transformer::transformNodes(std::vector<Point> &points)
{
    move(points);
    scale(points);
    rotate(points);
}
} // visitor
} // core