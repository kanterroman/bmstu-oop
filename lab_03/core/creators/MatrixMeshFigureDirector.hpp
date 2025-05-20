//
// Created by Roman Kanterov on 18.05.2025.
//

#ifndef MATRIXMESHFIGURECREATOR_HPP
#define MATRIXMESHFIGURECREATOR_HPP
#include "MeshFigureCreator.hpp"
#include "buffers/MeshFigureBuffer.hpp"
#include "builders/MatrixMeshFigureBuilder.hpp"

namespace core {
namespace creators {

class MatrixMeshFigureDirector : public MeshFigureCreator {
public:
    std::shared_ptr<objects::SceneObject> create(std::any buffer) override;
private:
    builders::MatrixMeshFigureBuilder builder{};
};

} // creators
} // core

#endif //MATRIXMESHFIGURECREATOR_HPP
