//
// Created by Roman Kanterov on 20.05.2025.
//

#include "TxtCameraReaderImplCreator.hpp"

#include "../TxtCameraReaderImpl.hpp"

namespace loader {
namespace reader {
namespace impl {
namespace creator {
std::shared_ptr<CameraReaderImpl> TxtCameraReaderImplCreator::create()
{
    return std::make_shared<TxtCameraReaderImpl>();
}
} // creator
} // impl
} // reader
} // loader