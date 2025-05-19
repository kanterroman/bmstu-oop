//
// Created by Roman Kanterov on 15.05.2025.
//

#include "ListMeshFigureImpl.hpp"

namespace core {
namespace objects {
ListMeshFigureImpl::PointsStorageType ListMeshFigureImpl::getNodes() const
{
    return nodes;
}

void ListMeshFigureImpl::setNodes(const PointsStorageType &nodes)
{
    this->nodes = nodes;
}

ListMeshFigureImpl::LinksStorageType ListMeshFigureImpl::getEdges() const
{
    return edges;
}

void ListMeshFigureImpl::setEdges(const LinksStorageType &edges)
{
    this->edges = edges;
}
} // objects
} // core