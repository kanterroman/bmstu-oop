//
// Created by Roman Kanterov on 18.05.2025.
//

#ifndef MESHMATRIXFIGUREBUFFER_HPP
#define MESHMATRIXFIGUREBUFFER_HPP
#include "MatrixMeshFigure.hpp"

#include <Point.hpp>
#include <vector>

namespace core {
namespace creators {
namespace buffers {

using Edge = std::pair<Point, Point>;

class MeshFigureBuffer {
public:
    void addEdge(const Point &first, const Point &second);
    std::vector<Edge> readEdges();
private:
    std::vector<Edge> edges;
};

} // buffers
} // creators
} // core

#endif //MESHMATRIXFIGUREBUFFER_HPP
