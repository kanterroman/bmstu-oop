//
// Created by Roman Kanterov on 20.05.2025.
//

#ifndef SELECTIONMANAGER_HPP
#define SELECTIONMANAGER_HPP
#include <SceneComposite.hpp>

namespace api {
namespace managers {

class SelectionManager {
public:
    void select();
private:
    std::shared_ptr<core::objects::SceneComposite> focused;
};

} // managers
} // api

#endif //SELECTIONMANAGER_HPP
