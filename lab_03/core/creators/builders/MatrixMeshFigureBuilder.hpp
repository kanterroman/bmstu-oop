//
// Created by Roman Kanterov on 18.05.2025.
//

#ifndef MATRIXMESHFIGUREBUILDER_HPP
#define MATRIXMESHFIGUREBUILDER_HPP
#include "MatrixMeshFigure.hpp"
#include "../buffers/MeshFigureBuffer.hpp"

namespace core {
namespace creators {
namespace builders {

class MatrixMeshFigureBuilder {
public:
    void setBuf(const std::shared_ptr<buffers::MeshFigureBuffer> &buf);
    void buildPoints();
    void buildLinks();
    std::shared_ptr<objects::SceneObject> build();
private:
    std::shared_ptr<buffers::MeshFigureBuffer> buf{};
    std::shared_ptr<objects::MatrixMeshFigureImpl> fig = std::make_shared<objects::MatrixMeshFigureImpl>();
};

} // builders
} // creators
} // core

#endif //MATRIXMESHFIGUREBUILDER_HPP
