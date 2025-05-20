//
// Created by Roman Kanterov on 15.05.2025.
//

#ifndef MATRIXMESHFIGUREIMPL_HPP
#define MATRIXMESHFIGUREIMPL_HPP
#include "BaseMatrixMeshFigureImpl.hpp"

#include <Point.hpp>
#include <vector>


namespace core::objects
{
class MatrixMeshFigureImpl : public BaseMatrixMeshFigureImpl {
public:
    MatrixMeshFigureImpl(PointsStorageType &nodes, LinksStorageType &edges)
        : nodes(nodes),
          edges(edges)
    {
    }

    PointsStorageType getNodes() const override;
    void setNodes(const PointsStorageType &nodes) override;
    LinksStorageType getEdges() const override;
    void setEdges(const LinksStorageType &edges) override;
private:
    PointsStorageType nodes;
    LinksStorageType edges;
};
}



#endif //MATRIXMESHFIGUREIMPL_HPP
