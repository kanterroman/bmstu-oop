//
// Created by Roman Kanterov on 19.05.2025.
//

#include "MeshFigureReaderCreator.hpp"

#include "../MeshFigureReader.hpp"

namespace loader {
namespace reader {
namespace creator {
std::shared_ptr<BaseMeshFigureReader> MeshFigureReaderCreator::create(std::shared_ptr<std::istream> stream, std::shared_ptr<impl::MeshFigureReaderImpl> impl)
{
    return std::make_shared<MeshFigureReader>(stream, impl);
}
} // creator
} // reader
} // loader