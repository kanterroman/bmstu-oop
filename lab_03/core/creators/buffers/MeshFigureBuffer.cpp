//
// Created by Roman Kanterov on 18.05.2025.
//

#include "MeshFigureBuffer.hpp"

namespace core {
namespace creators {
namespace buffers {
void MeshFigureBuffer::addEdge(const Point &first, const Point &second)
{
    edges.emplace_back(first, second);
}

std::vector<Edge> MeshFigureBuffer::readEdges()
{
    return edges;
}
} // buffers
} // creators
} // core