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
    auto n = fig->getN();
    Point nPt = { n[0], n[1], n[2] };
    std::vector<Point> pts{visPoint, nPt};
    rotate(pts);
    fig->setVisPoint(pts[0]);
    fig->set_n(Vector<double>({ pts[1].x, pts[1].y, pts[1].z }));
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
    if (data.ax == data.ay == data.az == 0)
        return;
    Point barycenter = find_barycenter(points);
    Point offs = data.offset;
    data.offset = -barycenter;
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