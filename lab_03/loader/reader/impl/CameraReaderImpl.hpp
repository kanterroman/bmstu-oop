//
// Created by Roman Kanterov on 19.05.2025.
//

#ifndef PLAINCAMERAREADERIMPL_HPP
#define PLAINCAMERAREADERIMPL_HPP
#include <memory>
#include "../core/creators/buffers/CameraBuffer.hpp"


namespace loader::reader::impl
{
class CameraReaderImpl {

public:
    virtual std::shared_ptr<core::creators::buffers::CameraBuffer> read(std::istream &stream) = 0;
    virtual ~CameraReaderImpl() = default;
};
}



#endif //PLAINCAMERAREADERIMPL_HPP
