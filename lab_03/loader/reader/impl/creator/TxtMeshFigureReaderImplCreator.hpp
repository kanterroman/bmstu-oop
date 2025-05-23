//
// Created by Roman Kanterov on 20.05.2025.
//

#ifndef TXTMESHFIGUREREADERIMPLCREATOR_HPP
#define TXTMESHFIGUREREADERIMPLCREATOR_HPP
#include "MeshFigureReaderImplCreator.hpp"

namespace loader {
namespace reader {
namespace impl {
namespace creator {

class TxtMeshFigureReaderImplCreator : public MeshFigureReaderImplCreator {
public:
    std::shared_ptr<MeshFigureReaderImpl> create() override;
};

} // creator
} // impl
} // reader
} // loader

#endif //TXTMESHFIGUREREADERIMPLCREATOR_HPP
