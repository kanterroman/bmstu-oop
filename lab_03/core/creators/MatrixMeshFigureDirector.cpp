//
// Created by Roman Kanterov on 18.05.2025.
//

#include "MatrixMeshFigureDirector.hpp"

namespace core {
namespace creators {
std::shared_ptr<objects::SceneObject> MatrixMeshFigureDirector::create(std::any buffer)
{
    auto buf = std::any_cast<std::shared_ptr<buffers::MeshFigureBuffer>>(buffer);
    builder.setBuf(std::make_shared<buffers::MeshFigureBuffer>(*buf));
    builder.buildPoints();
    builder.buildLinks();
    return builder.build();
}
} // creators
} // core