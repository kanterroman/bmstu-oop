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
    Vector planeNormal = cam->getN().normalize();

    Vector<double> planeU{3}, planeV{3};
    if (planeNormal[0] != 0) {
        planeU = Vector<double>({0, 1, 0});
    } else if (planeNormal[1] != 0) {
        planeU = Vector<double>({1, 0, 0});
    } else {
        planeU = Vector<double>({1, 0, 0});
    }
    planeV = planeNormal.crossProduct(planeU).normalized();
    planeU = planeV.crossProduct(planeNormal).normalized();

    auto vp = cam->getVisPoint();
    Vector<double> v = { pt.x - vp.x, pt.y - vp.y, pt.z - vp.z };

    double u = v.dotProduct(planeU);
    double vCoord = v.dotProduct(planeV);

    return Point(u, vCoord);
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

Point Drawer::tr(Point pr)
{
    Vector planeNormal = cam->getN().normalize(); // Пример: плоскость YZ (игнорируем X)

    // Находим базисные векторы плоскости
    Vector<double> planeU{3}, planeV{3};
    if (planeNormal[0] != 0) {
        planeU = Vector<double>({0, 1, 0}); // Второй вектор
    } else if (planeNormal[1] != 0) {
        planeU = Vector<double>({1, 0, 0});
    } else {
        planeU = Vector<double>({1, 0, 0});
    }
    planeV = planeNormal.crossProduct(planeU).normalized();
    planeU = planeV.crossProduct(planeNormal).normalized();

    auto vp = cam->getVisPoint();
    Vector<double> v = { pr.x - vp.x, pr.y - vp.y, pr.z - vp.z };

    // Проекция на базисные векторы плоскости
    double u = v.dotProduct(planeU);
    double vCoord = v.dotProduct(planeV);

    return Point(u, vCoord);
}
} // visitor
} // core
