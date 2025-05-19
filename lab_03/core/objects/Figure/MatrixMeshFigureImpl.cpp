//
// Created by Roman Kanterov on 15.05.2025.
//

#include "MatrixMeshFigureImpl.hpp"

core::objects::MatrixMeshFigureImpl::PointsStorageType core::objects::MatrixMeshFigureImpl::getNodes() const
{
    return nodes;
}

void core::objects::MatrixMeshFigureImpl::setNodes(const PointsStorageType &nodes)
{
    this->nodes = nodes;
}

core::objects::MatrixMeshFigureImpl::LinksStorageType core::objects::MatrixMeshFigureImpl::getEdges() const
{
    return edges;
}

void core::objects::MatrixMeshFigureImpl::setEdges(const LinksStorageType &edges)
{
    this->edges = edges;
}