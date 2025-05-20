//
// Created by Roman Kanterov on 19.05.2025.
//

#ifndef CAMERAREADERCREATOR_HPP
#define CAMERAREADERCREATOR_HPP
#include "../CameraReader.hpp"
#include "../impl/CameraReaderImpl.hpp"

#include <memory>

namespace loader {
namespace reader {
namespace creator {

class CameraReaderCreator {
public:
    virtual std::shared_ptr<CameraReader> create(std::shared_ptr<std::istream> stream, std::shared_ptr<impl::CameraReaderImpl> impl) = 0;
    virtual ~CameraReaderCreator();
};

} // creator
} // reader
} // loader

#endif //CAMERAREADERCREATOR_HPP
