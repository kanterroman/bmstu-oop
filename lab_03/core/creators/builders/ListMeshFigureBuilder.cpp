//
// Created by Roman Kanterov on 18.05.2025.
//

#include "ListMeshFigureBuilder.hpp"

namespace core {
namespace creators {
namespace builders {
void ListMeshFigureBuilder::setBuf(const std::shared_ptr<buffers::MeshFigureBuffer> &buf)
{
    this->buf = buf;
}

void ListMeshFigureBuilder::buildPoints()
{
    auto data = buf->readEdges();
    objects::ListMeshFigureImpl::PointsStorageType nodes;
    for (auto &edge : data)
    {
        if (std::find(nodes.begin(), nodes.end(), edge.first) != nodes.end())
            nodes.push_back(edge.first);
        if (std::find(nodes.begin(), nodes.end(), edge.second) != nodes.end())
            nodes.push_back(edge.second);
    }
    fig->setNodes(nodes);
}

void ListMeshFigureBuilder::buildLinks()
{
    auto data = buf->readEdges();
    objects::ListMeshFigureImpl::LinksStorageType edges{};
    auto nodes = fig->getNodes();
    for (auto &edge : data)
    {
        auto idx1 = std::find(nodes.begin(), nodes.end(), edge.first) - nodes.begin();
        auto idx2 = std::find(nodes.begin(), nodes.end(), edge.second) - nodes.begin();
        edges[idx1].push_back(idx2);
    }
    fig->setEdges(edges);
}

std::shared_ptr<objects::SceneObject> ListMeshFigureBuilder::build()
{
    return std::make_shared<objects::ListMeshFigure>(fig);
}
} // builders
} // creators
} // core