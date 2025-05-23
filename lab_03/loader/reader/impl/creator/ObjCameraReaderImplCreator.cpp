//
// Created by Roman Kanterov on 20.05.2025.
//

#include "ObjCameraReaderImplCreator.hpp"

#include "../ObjCameraReaderImpl.hpp"

namespace loader {
namespace reader {
namespace impl {
namespace creator {
std::shared_ptr<CameraReaderImpl> ObjCameraReaderImplCreator::create()
{
    return std::make_shared<ObjCameraReaderImpl>();
}
} // creator
} // impl
} // reader
} // loader