//
// Created by Roman Kanterov on 20.05.2025.
//

#include "ObjMeshFigureReaderImplCreator.hpp"

#include "../ObjMeshFigureReaderImpl.hpp"

namespace loader {
namespace reader {
namespace impl {
namespace creator {
std::shared_ptr<MeshFigureReaderImpl> ObjMeshFigureReaderImplCreator::create()
{
    return std::make_shared<ObjMeshFigureReaderImpl>();
}
} // creator
} // impl
} // reader
} // loader