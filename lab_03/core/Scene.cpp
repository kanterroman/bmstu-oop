//
// Created by Roman Kanterov on 14.05.2025.
//

#include "Scene.hpp"

namespace core {
Scene::iterator Scene::begin()
{
    return objs.begin();
}

Scene::iterator Scene::end()
{
    return objs.end();
}

void Scene::remove(iterator &iter)
{
    objs.erase(iter);
}

void Scene::add(value_type obj)
{
    objs.push_back(obj);
}
} // core