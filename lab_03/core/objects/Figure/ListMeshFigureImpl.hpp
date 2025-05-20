//
// Created by Roman Kanterov on 15.05.2025.
//

#ifndef LISTMESHFIGUREIMPL_HPP
#define LISTMESHFIGUREIMPL_HPP
#include "BaseListMeshFigureImpl.hpp"

#include <Point.hpp>
#include <list>
#include <vector>

namespace core {
namespace objects {

class ListMeshFigureImpl : public BaseListMeshFigureImpl {
public:
    ListMeshFigureImpl(PointsStorageType &nodes, LinksStorageType &edges)
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

} // objects
} // core

#endif //LISTMESHFIGUREIMPL_HPP
