//
// Created by Roman Kanterov on 19.05.2025.
//

#include "PlainCameraReaderCreator.hpp"

#include "../PlainCameraReader.hpp"

namespace loader {
namespace reader {
namespace creator {
std::shared_ptr<CameraReader> PlainCameraReaderCreator::create(std::shared_ptr<std::istream> stream, std::shared_ptr<impl::CameraReaderImpl> impl)
{
    return std::make_shared<PlainCameraReader>(stream, impl);
}
} // creator
} // reader
} // loader