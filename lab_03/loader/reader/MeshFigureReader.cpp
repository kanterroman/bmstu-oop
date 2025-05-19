//
// Created by Roman Kanterov on 19.05.2025.
//

#include "MeshFigureReader.hpp"

namespace loader {
namespace reader {
std::shared_ptr<core::creators::buffers::MeshFigureBuffer> MeshFigureReader::read()
{
    return impl->read(*stream);
}
} // reader
} // loader