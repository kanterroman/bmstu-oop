//
// Created by Roman Kanterov on 19.05.2025.
//

#ifndef OBJPLAINCAMERAREADERIMPL_HPP
#define OBJPLAINCAMERAREADERIMPL_HPP
#include "CameraReaderImpl.hpp"
#include <istream>

namespace loader {
namespace reader {
namespace impl {

class ObjCameraReaderImpl : public CameraReaderImpl {
public:
    std::shared_ptr<core::creators::buffers::CameraBuffer> read(std::istream &stream) override;
private:
    std::shared_ptr<core::creators::buffers::CameraBuffer> buf{};
    bool checkHeader(std::istream &stream);
    void parsePoint(std::istream &stream);
    void parseNormal(std::istream &stream);
    std::istream::pos_type streampos;
    static constexpr std::string HEADER_NAME = "cam";
    static constexpr std::string NORMAL_NAME = "vn";
    static constexpr std::string VERTEX_NAME = "v";
};

} // impl
} // reader
} // loader

#endif //OBJPLAINCAMERAREADERIMPL_HPP
