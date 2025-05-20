//
// Created by Roman Kanterov on 18.05.2025.
//

#include "MatrixMeshFigureBuilder.hpp"

namespace core {
namespace creators {
namespace builders {
void MatrixMeshFigureBuilder::setBuf(const std::shared_ptr<buffers::MeshFigureBuffer> &buf)
{
    this->buf = buf;
}

void MatrixMeshFigureBuilder::buildPoints()
{
    auto data = buf->readEdges();
    objects::MatrixMeshFigureImpl::PointsStorageType nodes;
    for (auto &edge : data)
    {
        if (std::ranges::find(nodes, edge.first) != nodes.end())
            nodes.push_back(edge.first);
        if (std::ranges::find(nodes, edge.second) != nodes.end())
            nodes.push_back(edge.second);
    }
    fig->setNodes(nodes);
}

void MatrixMeshFigureBuilder::buildLinks()
{
    auto data = buf->readEdges();
    objects::MatrixMeshFigureImpl::LinksStorageType edges{};
    auto nodes = fig->getNodes();
    for (auto &edge : data)
    {
        auto idx1 = std::find(nodes.begin(), nodes.end(), edge.first) - nodes.begin();
        auto idx2 = std::find(nodes.begin(), nodes.end(), edge.second) - nodes.begin();
        edges[idx1][idx2] = 1;
    }
    fig->setEdges(edges);
}

std::shared_ptr<objects::SceneObject> MatrixMeshFigureBuilder::build()
{
    return std::make_shared<objects::MatrixMeshFigure>(fig);
}
} // builders
} // creators
} // core