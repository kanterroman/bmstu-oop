//
// Created by Roman Kanterov on 20.05.2025.
//

#ifndef CAMERAREADERIMPLCREATOR_HPP
#define CAMERAREADERIMPLCREATOR_HPP
#include "../CameraReaderImpl.hpp"

#include <memory>

namespace loader {
namespace reader {
namespace impl {
namespace creator {

class CameraReaderImplCreator {
public:
    virtual std::shared_ptr<CameraReaderImpl> create() = 0;
    virtual ~CameraReaderImplCreator() = default;
};

} // creator
} // impl
} // reader
} // loader

#endif //CAMERAREADERIMPLCREATOR_HPP
