//
// Created by Roman Kanterov on 19.05.2025.
//

#ifndef PLAINCAMERAREADERIMPL_HPP
#define PLAINCAMERAREADERIMPL_HPP
#include <memory>
#include "../core/creators/buffers/CameraBuffer.hpp"


namespace loader::reader::impl
{
class PlainCameraReaderImpl {

public:
    virtual std::shared_ptr<core::creators::buffers::CameraBuffer> read(std::istream &stream) = 0;
    virtual ~PlainCameraReaderImpl() = default;
};
}



#endif //PLAINCAMERAREADERIMPL_HPP
