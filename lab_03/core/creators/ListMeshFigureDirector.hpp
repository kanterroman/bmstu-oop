//
// Created by Roman Kanterov on 18.05.2025.
//

#ifndef LISTMESHFIGURECREATOR_HPP
#define LISTMESHFIGURECREATOR_HPP
#include "MeshFigureCreator.hpp"
#include "builders/ListMeshFigureBuilder.hpp"

namespace core {
namespace creators {

class ListMeshFigureDirector : public MeshFigureCreator {
public:
    std::shared_ptr<objects::SceneObject> create(std::any buffer) override;
private:
    builders::ListMeshFigureBuilder builder{};
};

} // creators
} // core

#endif //LISTMESHFIGURECREATOR_HPP
