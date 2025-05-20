//
// Created by Roman Kanterov on 20.05.2025.
//

#ifndef OBJCAMERAREADERIMPLCREATOR_HPP
#define OBJCAMERAREADERIMPLCREATOR_HPP
#include "CameraReaderImplCreator.hpp"

namespace loader {
namespace reader {
namespace impl {
namespace creator {

class ObjCameraReaderImplCreator : public CameraReaderImplCreator {
public:
    std::shared_ptr<CameraReaderImpl> create() override;
};

} // creator
} // impl
} // reader
} // loader

#endif //OBJCAMERAREADERIMPLCREATOR_HPP
