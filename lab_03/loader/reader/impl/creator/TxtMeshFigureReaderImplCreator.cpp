//
// Created by Roman Kanterov on 20.05.2025.
//

#include "TxtMeshFigureReaderImplCreator.hpp"

#include "../TxtMeshFigureReaderImpl.hpp"

namespace loader {
namespace reader {
namespace impl {
namespace creator {
std::shared_ptr<MeshFigureReaderImpl> TxtMeshFigureReaderImplCreator::create()
{
    return std::make_shared<TxtMeshFigureReaderImpl>();
}
} // creator
} // impl
} // reader
} // loader