#ifndef LISTMESHFIGURE_HPP
#define LISTMESHFIGURE_HPP
#include "Figure.hpp"
#include "TransformVisitor.hpp"
#include "DrawVisitor.hpp"

namespace core::objects
{
class ListMeshFigureImpl;

class ListMeshFigure : public Figure {
    friend class visitor::TransformVisitor;
    friend class visitor::DrawVisitor;
private:
    std::shared_ptr<BaseListMeshFigureImpl> impl;
public:
    explicit ListMeshFigure(const std::shared_ptr<BaseListMeshFigureImpl> &impl)
        : impl(impl)
    {
    }

    void accept(std::shared_ptr<visitor::SceneObjectVisitor> vis) override;
};
}


#endif //LISTMESHFIGURE_HPP
