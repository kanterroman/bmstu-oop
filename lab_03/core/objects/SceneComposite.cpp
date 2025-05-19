//
// Created by Roman Kanterov on 14.05.2025.
//

#include "SceneComposite.hpp"

namespace core {
SceneComposite::SceneComposite(std::initializer_list<SceneObject> list)
{
    for (auto &elem : list)
        objects.push_back(elem);
}

SceneComposite::SceneComposite(const StorageType &objs) : objects(objs) {}

void SceneComposite::add(SceneObject &obj)
{
    objects.push_back(obj);
}

void SceneComposite::remove(Iterator &iter)
{
    objects.erase(iter);
}

SceneObject::Iterator SceneComposite::begin()
{
    return objects.begin();
}

SceneObject::Iterator SceneComposite::end()
{
    return objects.end();
}

bool SceneComposite::isComposite()
{
    return true;
}

void SceneComposite::accept(std::shared_ptr<SceneObjectVisitor> vis)
{
    for (auto &object : objects)
        object.accept(vis);
}
} // core