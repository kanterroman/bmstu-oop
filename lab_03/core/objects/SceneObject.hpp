//
// Created by Roman Kanterov on 14.05.2025.
//

#ifndef SCENEOBJECT_HPP
#define SCENEOBJECT_HPP

#include <vector>

namespace core::visitor
{
class SceneObjectVisitor;
}

namespace core::objects {

class SceneObject {
public:
    using idType = int;
protected:
    using Iterator = std::vector<std::shared_ptr<SceneObject>>::iterator;
public:
    static idType currentId() { return count; }
    virtual void add(std::shared_ptr<SceneObject> &object);
    virtual void remove(Iterator &iter);
    virtual Iterator begin();
    virtual Iterator end();
    virtual bool isComposite() const;
    virtual bool isCamera() const;
    virtual void accept(std::shared_ptr<visitor::SceneObjectVisitor> vis) = 0;
    virtual ~SceneObject();
    virtual idType id() const;
protected:
    idType _id{count++};
private:
    static idType count;
};

} // core

#endif //SCENEOBJECT_HPP
