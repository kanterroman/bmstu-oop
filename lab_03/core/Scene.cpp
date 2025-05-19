//
// Created by Roman Kanterov on 14.05.2025.
//

#include "Scene.hpp"

namespace core {
std::shared_ptr<objects::SceneObject> Scene::getFocusedObjects()
{
    // return focusedObjects;
}

Scene::Iterator Scene::begin()
{
    return objects.begin();
}

Scene::Iterator Scene::end()
{
    return objects.end();
}

void Scene::remove(Iterator &iter)
{
    objects.erase(iter);
}

void Scene::add(objects::SceneObject &obj)
{
    objects.push_back(obj);
}
} // core