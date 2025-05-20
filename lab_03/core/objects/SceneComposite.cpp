//
// Created by Roman Kanterov on 14.05.2025.
//

#include "SceneComposite.hpp"

namespace core {
objects::SceneComposite::SceneComposite(std::initializer_list<SceneObject> list)
{
    for (auto &elem : list)
        objs.push_back(elem);
}

objects::SceneComposite::SceneComposite(const StorageType &objs) : objs(objs) {}

void objects::SceneComposite::add(SceneObject &obj)
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

bool objects::SceneComposite::isComposite()
{
    return true;
}

void objects::SceneComposite::accept(std::shared_ptr<visitor::SceneObjectVisitor> vis)
{
    for (auto &object : objs)
        object.accept(vis);
}
} // core