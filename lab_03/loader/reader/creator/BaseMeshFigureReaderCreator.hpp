//
// Created by Roman Kanterov on 19.05.2025.
//

#ifndef BASEMESHFIGUREREADERCREATOR_HPP
#define BASEMESHFIGUREREADERCREATOR_HPP
#include "../BaseMeshFigureReader.hpp"
#include "../impl/MeshFigureReaderImpl.hpp"

#include <memory>

namespace loader {
namespace reader {
namespace creator {

class BaseMeshFigureReaderCreator {
public:
    virtual std::shared_ptr<BaseMeshFigureReader> create(std::shared_ptr<std::istream> stream, std::shared_ptr<impl::MeshFigureReaderImpl> impl) = 0;
    virtual ~BaseMeshFigureReaderCreator();
};

} // creator
} // reader
} // loader

#endif //BASEMESHFIGUREREADERCREATOR_HPP
