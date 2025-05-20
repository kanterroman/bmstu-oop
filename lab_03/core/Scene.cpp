//
// Created by Roman Kanterov on 14.05.2025.
//

#include "Scene.hpp"

namespace core {
Scene::Iterator Scene::begin()
{
    return objs.begin();
}

Scene::Iterator Scene::end()
{
    return objs.end();
}

void Scene::remove(Iterator &iter)
{
    objs.erase(iter);
}

void Scene::add(std::shared_ptr<objects::SceneObject> obj)
{
    objs.push_back(obj);
}
} // core