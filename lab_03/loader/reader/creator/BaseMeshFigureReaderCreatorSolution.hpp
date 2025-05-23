//
// Created by Roman Kanterov on 20.05.2025.
//

#ifndef BASEMESHFIGURECREATORSOLUTION_HPP
#define BASEMESHFIGURECREATORSOLUTION_HPP
#include "BaseMeshFigureReaderCreator.hpp"
#include "MeshFigureReaderCreator.hpp"
#include <unordered_map>

namespace loader {
namespace reader {
namespace creator {

class BaseMeshFigureCreatorSolution {
public:
    using Tag = enum { MeshFigure };

    std::shared_ptr<BaseMeshFigureReaderCreator> createCreator(Tag id);
    void register_(Tag id, std::shared_ptr<BaseMeshFigureReaderCreator> cr);
private:
    std::unordered_map<Tag, std::shared_ptr<BaseMeshFigureReaderCreator>> map = { {Tag::MeshFigure, std::make_shared<MeshFigureReaderCreator>()} };
};

} // creator
} // reader
} // loader

#endif //BASEMESHFIGURECREATORSOLUTION_HPP
