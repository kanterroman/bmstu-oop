//
// Created by Roman Kanterov on 19.05.2025.
//

#ifndef PLAINCAMERAREADERCREATOR_HPP
#define PLAINCAMERAREADERCREATOR_HPP
#include "CameraReaderCreator.hpp"
#include "../impl/CameraReaderImpl.hpp"

namespace loader {
namespace reader {
namespace creator {

class PlainCameraReaderCreator : public CameraReaderCreator {
public:
    std::shared_ptr<CameraReader> create(std::shared_ptr<std::istream> stream, std::shared_ptr<impl::CameraReaderImpl> impl) override;
};

} // creator
} // reader
} // loader

#endif //PLAINCAMERAREADERCREATOR_HPP
