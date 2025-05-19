#ifndef SCENECOMPOSITE_HPP
#define SCENECOMPOSITE_HPP
#include "SceneObject.hpp"
#include <initializer_list>

namespace core::objects {

class SceneComposite : public SceneObject {
public:
    using StorageType = std::vector<SceneObject>;
    StorageType objects;
public:
    SceneComposite() = default;
    SceneComposite(std::initializer_list<SceneObject> list);
    SceneComposite(const StorageType &objs);

    void add(SceneObject &obj) override;
    void remove(Iterator &iter) override;
    Iterator begin() override;
    Iterator end() override;
    bool isComposite() override;
    void accept(std::shared_ptr<visitor::SceneObjectVisitor>) override;
};

} // core

#endif //SCENECOMPOSITE_HPP
