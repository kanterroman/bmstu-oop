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
private:
    builders::ListMeshFigureBuilder builder{};
public:
    std::shared_ptr<objects::SceneObject> create(std::any buffer) override;
};

} // creators
} // core

#endif //LISTMESHFIGURECREATOR_HPP
