//
// Created by Roman Kanterov on 20.05.2025.
//

#ifndef TXTCAMERAREADERIMPLCREATOR_HPP
#define TXTCAMERAREADERIMPLCREATOR_HPP
#include "CameraReaderImplCreator.hpp"

namespace loader {
namespace reader {
namespace impl {
namespace creator {

class TxtCameraReaderImplCreator : public CameraReaderImplCreator {
public:
    std::shared_ptr<CameraReaderImpl> create() override;
};

} // creator
} // impl
} // reader
} // loader

#endif //TXTCAMERAREADERIMPLCREATOR_HPP
