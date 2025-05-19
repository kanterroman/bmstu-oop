//
// Created by Roman Kanterov on 18.05.2025.
//

#include "ListMeshFigureDirector.hpp"

namespace core {
namespace creators {
std::shared_ptr<objects::SceneObject> ListMeshFigureDirector::create(std::any buffer)
{
    auto buf = std::any_cast<buffers::MeshFigureBuffer>(buffer);
    builder.setBuf(std::make_shared<buffers::MeshFigureBuffer>(buf));
    builder.buildPoints();
    builder.buildLinks();
    return builder.build();
}
} // creators
} // core