//
// Created by Roman Kanterov on 19.05.2025.
//

#ifndef PLAINCAMERAREADER_HPP
#define PLAINCAMERAREADER_HPP
#include "CameraReader.hpp"
#include "impl/CameraReaderImpl.hpp"

namespace loader {
namespace reader {

class PlainCameraReader : public CameraReader {
public:
    PlainCameraReader(const std::shared_ptr<std::istream> &stream,
        const std::shared_ptr<impl::CameraReaderImpl> &impl)
        : stream(stream),
          impl(impl)
    {
    }

    std::shared_ptr<core::creators::buffers::CameraBuffer> read() override;
private:
    std::shared_ptr<std::istream> stream;
    std::shared_ptr<impl::CameraReaderImpl> impl;
};

} // reader
} // loader

#endif //PLAINCAMERAREADER_HPP
