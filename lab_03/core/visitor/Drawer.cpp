//
// Created by Roman Kanterov on 15.05.2025.
//

#include "Drawer.hpp"
#include "ConstIterator.hpp"
#include "Iterator.hpp"
#include "Vector.hpp"
#include "ReverseIterator.h"
#include "ConstReverseIterator.h"
#include "ConstReverseIterator.hpp"
#include "ReverseIterator.hpp"

namespace core {
namespace visitor {
void Drawer::draw(std::shared_ptr<objects::BaseMatrixMeshFigureImpl> fig, std::shared_ptr<graphics::GraphicFactory> graphic)
{
    auto nodes = fig->getNodes();
    for (auto &node : nodes)
    {
        node = projectOnCam(node);
    }
    auto edges = fig->getEdges();
    auto baseNodes = fig->getNodes();
    for (auto i = 0; i < edges.size(); i++)
    {
        for (auto j = 0; j < edges[0].size(); j++)
        {
            if (!checkVisibility(baseNodes[i]) || !checkVisibility(baseNodes[j]))
                continue;
            if (edges[i][j] == 1)
                p->drawLine(graphic->createGraphicPoint(nodes[i]), graphic->createGraphicPoint(nodes[j]));
        }
    }
}

void Drawer::draw(std::shared_ptr<objects::BaseListMeshFigureImpl> fig, std::shared_ptr<graphics::GraphicFactory> graphic)
{
    auto nodes = fig->getNodes();
    for (auto &node : nodes)
    {
        node = projectOnCam(node);
    }
    auto edges = fig->getEdges();

    auto baseNodes = fig->getNodes();
    for (auto i = 0; i < edges.size(); i++)
    {
        for (auto j : edges[i])
        {
            if (!checkVisibility(baseNodes[i]) || !checkVisibility(baseNodes[j]))
                continue;
            p->drawLine(graphic->createGraphicPoint(nodes[i]), graphic->createGraphicPoint(nodes[j]));
        }
    }
}

Point Drawer::projectOnCam(Point pt)
{
    // Vector<double> n = cam->getN();
    // Point visPoint = cam->getVisPoint();
    // const double t = -(n[0] * pt.x
    //         + n[1] * pt.y
    //         + n[2] * pt.z
    //         + visPoint.y + visPoint.y + visPoint.z) /
    //     (pow(n[0], 2) +
    //         pow(n[1], 2) +
    //         pow(n[2], 2));
    //
    // pt.x += n[0] * t - pt.y;
    // pt.y += n[1] * t - pt.y;
    // _point.setX(_point.getX() + camera._direction.getX() * t - camera._position.getX());
    // _point.setY(_point.getY() + camera._direction.getY() * t - camera._position.getY());
    // pt.z = 0;
    // return pt;
    Vector n = cam->getN().normalize();
    Point camPoint = cam->getVisPoint();
    //
    // 2. Вектор от точки плоскости к проектируемой точке
    // Point dp = pt + -camPoint;
    // Vector<double> dv({dp.x, dp.y, dp.z});
    //
    // 3. Вычисляем расстояние от точки до плоскости (со знаком)
    // double distance = dv.dotProduct(n);
    //
    //
    // // 4. Находим проекцию
    // Vector<double> ans = -distance*n;
    // return {pt.x + ans[0], pt.y + ans[1], pt.z + ans[2]};
    Vector<double> r = { pt.x, pt.y, pt.z };
    double d = -n[0]*camPoint.x - n[1]*camPoint.y - n[2]*camPoint.z;
    Vector rProj = r - ((r^n) + d)/(n^n) * n;
    return { rProj[0], rProj[1], rProj[2] };
}

bool Drawer::checkVisibility(Point pt)
{
    Vector n = cam->getN().normalize();
    Point camPoint = cam->getVisPoint();
    Vector<double> v{ {pt.x - camPoint.x, pt.y - camPoint.y, pt.z - camPoint.z} };
    if (n.dotProduct(v) < 0)
        return false;
    return true;
}
} // visitor
} // core
