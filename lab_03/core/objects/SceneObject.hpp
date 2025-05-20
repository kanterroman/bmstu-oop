//
// Created by Roman Kanterov on 14.05.2025.
//

#ifndef SCENEOBJECT_HPP
#define SCENEOBJECT_HPP

#include "SceneObjectVisitor.hpp"
#include <vector>

namespace core::objects {

class SceneObject {
protected:
    using Iterator = std::vector<SceneObject>::iterator;
public:
    virtual void add(SceneObject &object);
    virtual void remove(Iterator &iter);
    virtual Iterator begin();
    virtual Iterator end();
    virtual bool isComposite();
    virtual bool isCamera();
    virtual void accept(std::shared_ptr<visitor::SceneObjectVisitor> vis) = 0;
    virtual ~SceneObject() = 0;
};

} // core

#endif //SCENEOBJECT_HPP
