#ifndef BASELISTMESHFIGUREIMPL_HPP
#define BASELISTMESHFIGUREIMPL_HPP
#include <Point.hpp>
#include <list>

namespace core {
namespace objects {

class BaseListMeshFigureImpl {
public:
    using PointsStorageType = std::vector<Point>;
    using LinksStorageType = std::vector<std::list<PointsStorageType::size_type>>;

    virtual PointsStorageType getNodes() const = 0;
    virtual void setNodes(const PointsStorageType &nodes) = 0;
    virtual LinksStorageType getEdges() const = 0;
    virtual void setEdges(const LinksStorageType &edges) = 0;

    virtual ~BaseListMeshFigureImpl() = 0;
};

} // objects
} // core

#endif //BASELISTMESHFIGUREIMPL_HPP
