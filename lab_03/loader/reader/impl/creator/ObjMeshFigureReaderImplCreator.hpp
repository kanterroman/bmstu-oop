//
// Created by Roman Kanterov on 20.05.2025.
//

#ifndef OBJMESHFIGUREREADERIMPLCREATOR_HPP
#define OBJMESHFIGUREREADERIMPLCREATOR_HPP
#include "MeshFigureReaderImplCreator.hpp"

namespace loader {
namespace reader {
namespace impl {
namespace creator {

class ObjMeshFigureReaderImplCreator : public MeshFigureReaderImplCreator{
public:
    std::shared_ptr<MeshFigureReaderImpl> create() override;
};

} // creator
} // impl
} // reader
} // loader

#endif //OBJMESHFIGUREREADERIMPLCREATOR_HPP
