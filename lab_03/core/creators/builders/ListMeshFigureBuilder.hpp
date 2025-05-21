//
// Created by Roman Kanterov on 18.05.2025.
//

#ifndef LISTMESHFIGUREBUILDER_HPP
#define LISTMESHFIGUREBUILDER_HPP
#include "ListMeshFigure.hpp"
#include "ListMeshFigureImpl.hpp"
#include "buffers/MeshFigureBuffer.hpp"

#include <memory>

namespace core {
namespace creators {
namespace builders {

class ListMeshFigureBuilder {
public:
    void setBuf(const std::shared_ptr<buffers::MeshFigureBuffer> &buf);
    void buildPoints();
    void buildLinks();
    std::shared_ptr<objects::SceneObject> build();
private:
    std::shared_ptr<buffers::MeshFigureBuffer> buf{};
    std::shared_ptr<objects::BaseListMeshFigureImpl> fig = std::make_shared<objects::ListMeshFigureImpl>();
};

} // builders
} // creators
} // core

#endif //LISTMESHFIGUREBUILDER_HPP
