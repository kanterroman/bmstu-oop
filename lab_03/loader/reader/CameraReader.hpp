//
// Created by Roman Kanterov on 19.05.2025.
//

#ifndef CAMERAREADER_HPP
#define CAMERAREADER_HPP
#include "buffers/CameraBuffer.hpp"

#include <memory>

namespace loader {
namespace reader {

class CameraReader {
public:
    virtual std::shared_ptr<core::creators::buffers::CameraBuffer> read() = 0;
    virtual ~CameraReader();
};

} // reader
} // loader

#endif //CAMERAREADER_HPP
