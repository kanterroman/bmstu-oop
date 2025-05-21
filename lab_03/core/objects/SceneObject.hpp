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

    using value_type = std::shared_ptr<SceneObject>;
    using reference = std::shared_ptr<SceneObject>&;
    using const_reference = const std::shared_ptr<SceneObject>&;
    using iterator = std::vector<value_type>::iterator;
    using const_iterator = std::vector<value_type>::const_iterator;


    static idType currentId() { return count; }
    virtual void add(std::shared_ptr<SceneObject> &object);
    virtual void remove(iterator &iter);
    virtual iterator begin();
    virtual iterator end();
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
