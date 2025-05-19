#ifndef BASEMATRIXMESHFIGUREIMPL_HPP
#define BASEMATRIXMESHFIGUREIMPL_HPP
#include <Point.hpp>
#include <vector>


namespace core::objects
{
class BaseMatrixMeshFigureImpl {
public:
    using PointsStorageType = std::vector<Point>;
    using LinksStorageType = std::vector<std::vector<int>>;

    virtual PointsStorageType getNodes() const = 0;
    virtual void setNodes(const PointsStorageType &nodes) = 0;
    virtual LinksStorageType getEdges() const = 0;
    virtual void setEdges(const LinksStorageType &edges) = 0;
    virtual ~BaseMatrixMeshFigureImpl() = 0;
};
}


#endif //BASEMATRIXMESHFIGUREIMPL_HPP
