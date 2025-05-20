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
    for (auto i = 0; i < edges.size(); i++)
    {
        for (auto j = 0; j < edges[0].size(); j++)
        {
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

    for (auto i = 0; i < edges.size(); i++)
    {
        for (auto j : edges[i])
        {
            p->drawLine(graphic->createGraphicPoint(nodes[i]), graphic->createGraphicPoint(nodes[j]));
        }
    }
}

Point Drawer::projectOnCam(Point pt)
{
    Vector n = cam->getN();
    Point camPoint = cam->getVisPoint();
    Vector<double> r = { pt.x, pt.y, pt.z };
    double d = -n[0]*camPoint.x - n[1]*camPoint.y - n[2]*camPoint.z;
    Vector rProj = r - ((r^n) + d)/(n^n) * n;
    return { rProj[0], rProj[1], rProj[2] };
}
} // visitor
} // core