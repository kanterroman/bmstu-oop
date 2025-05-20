//
// Created by Roman Kanterov on 19.05.2025.
//

#ifndef MESHFIGUREREADERCREATOR_HPP
#define MESHFIGUREREADERCREATOR_HPP
#include "BaseMeshFigureReaderCreator.hpp"
#include "../impl/MeshFigureReaderImpl.hpp"

namespace loader {
namespace reader {
namespace creator {

class MeshFigureReaderCreator : public BaseMeshFigureReaderCreator {
public:
    std::shared_ptr<BaseMeshFigureReader> create(std::shared_ptr<std::istream> stream, std::shared_ptr<impl::MeshFigureReaderImpl> impl) override;
};

} // creator
} // reader
} // loader

#endif //MESHFIGUREREADERCREATOR_HPP
