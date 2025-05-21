//
// Created by Roman Kanterov on 14.05.2025.
//

#include "SceneObject.hpp"

#include "exceptions/NotImplementedException.hpp"

#include <exception>


namespace core
{
namespace objects {
int SceneObject::count = 0;

void objects::SceneObject::add(std::shared_ptr<SceneObject> &object)
{
    throw exceptions::NotImplementedException(__FILE__, __LINE__, __FUNCTION__);
}

void objects::SceneObject::remove(iterator &iter)
{
    throw exceptions::NotImplementedException(__FILE__, __LINE__, __FUNCTION__);
}

objects::SceneObject::iterator objects::SceneObject::begin()
{
    throw exceptions::NotImplementedException(__FILE__, __LINE__, __FUNCTION__);
}

objects::SceneObject::iterator objects::SceneObject::end()
{
    throw exceptions::NotImplementedException(__FILE__, __LINE__, __FUNCTION__);
}

bool objects::SceneObject::isComposite() const
{
    return false;
}

bool objects::SceneObject::isCamera() const
{
    return false;
}

objects::SceneObject::~SceneObject() = default;

SceneObject::idType objects::SceneObject::id() const
{
    return _id;
}
}
}// core