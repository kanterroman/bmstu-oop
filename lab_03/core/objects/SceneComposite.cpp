//
// Created by Roman Kanterov on 14.05.2025.
//

#include "SceneComposite.hpp"

namespace core {
void objects::SceneComposite::add(std::shared_ptr<SceneObject> &obj)
{
    objs.push_back(obj);
}

void objects::SceneComposite::remove(Iterator &iter)
{
    objs.erase(iter);
}

objects::SceneObject::Iterator objects::SceneComposite::begin()
{
    return objs.begin();
}

objects::SceneObject::Iterator objects::SceneComposite::end()
{
    return objs.end();
}

bool objects::SceneComposite::isComposite() const
{
    return true;
}

void objects::SceneComposite::accept(std::shared_ptr<visitor::SceneObjectVisitor> vis)
{
    for (auto &object : objs)
        object->accept(vis);
}
} // core