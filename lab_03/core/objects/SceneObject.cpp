//
// Created by Roman Kanterov on 14.05.2025.
//

#include "SceneObject.hpp"
#include <exception>

namespace core {

class not_implemented_exception;

void SceneObject::add(SceneObject &object)
{
    throw not_implemented_exception();
}

void SceneObject::remove(Iterator &iter)
{
    throw not_implemented_exception();
}

SceneObject::Iterator SceneObject::begin()
{
    throw not_implemented_exception();
}

SceneObject::Iterator SceneObject::end()
{
    throw not_implemented_exception();
}

bool SceneObject::isComposite()
{
    return false;
}

bool SceneObject::isCamera()
{
    return false;
}

SceneObject::~SceneObject() = default;

} // core