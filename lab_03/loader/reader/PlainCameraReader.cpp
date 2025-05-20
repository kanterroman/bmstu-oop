//
// Created by Roman Kanterov on 19.05.2025.
//

#include "PlainCameraReader.hpp"

namespace loader {
namespace reader {
std::shared_ptr<core::creators::buffers::CameraBuffer> PlainCameraReader::read()
{
    return impl->read(stream);
}
} // reader
} // loader