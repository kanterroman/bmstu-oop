#ifndef LISTMESHFIGURE_HPP
#define LISTMESHFIGURE_HPP
#include "Figure.hpp"


#include <Figure.hpp>


namespace core::visitor
{
class DrawVisitor;
class TransformVisitor;
}

namespace core::objects
{
class BaseListMeshFigureImpl;

class ListMeshFigure : public Figure {
    friend class visitor::TransformVisitor;
    friend class visitor::DrawVisitor;
public:
    explicit ListMeshFigure(const std::shared_ptr<BaseListMeshFigureImpl> &impl)
        : impl(impl)
    {
    }

    void accept(std::shared_ptr<visitor::SceneObjectVisitor> vis) override;
private:
    std::shared_ptr<BaseListMeshFigureImpl> impl;
};
}


#endif //LISTMESHFIGURE_HPP
