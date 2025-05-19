//
// Created by Roman Kanterov on 19.05.2025.
//

#ifndef OBJPLAINCAMERAREADERIMPL_HPP
#define OBJPLAINCAMERAREADERIMPL_HPP
#include "PlainCameraReaderImpl.hpp"

namespace loader {
namespace reader {
namespace impl {

class ObjPlainCameraReaderImpl : PlainCameraReaderImpl {
private:
    std::shared_ptr<core::creators::buffers::CameraBuffer> buf{};
    bool checkHeader(std::istream &stream);
    void parsePoint(std::istream &stream);
    void parseNormal(std::istream &stream);
    std::istream::pos_type streampos;
public:
    std::shared_ptr<core::creators::buffers::CameraBuffer> read(std::istream &stream) override;
};

} // impl
} // reader
} // loader

#endif //OBJPLAINCAMERAREADERIMPL_HPP
