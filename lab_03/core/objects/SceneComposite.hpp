#ifndef SCENECOMPOSITE_HPP
#define SCENECOMPOSITE_HPP
#include "SceneObject.hpp"
#include <initializer_list>

namespace core::objects {

class SceneComposite : public SceneObject {
public:
    using StorageType = std::vector<std::shared_ptr<SceneObject>>;

    SceneComposite() = default;
    void add(std::shared_ptr<SceneObject> &obj) override;
    void remove(iterator &iter) override;
    iterator begin() override;
    iterator end() override;
    bool isComposite() const override;
    void accept(std::shared_ptr<visitor::SceneObjectVisitor>) override;
private:
    StorageType objs;
};

} // core

#endif //SCENECOMPOSITE_HPP
