//
// Created by Roman Kanterov on 19.05.2025.
//

#ifndef MESHFIGUREREADERIMPL_HPP
#define MESHFIGUREREADERIMPL_HPP
#include "buffers/MeshFigureBuffer.hpp"

#include <memory>

namespace loader {
namespace reader {
namespace impl {

class MeshFigureReaderImpl {
public:
    virtual std::shared_ptr<core::creators::buffers::MeshFigureBuffer> read(std::istream &stream) = 0;
    virtual ~MeshFigureReaderImpl() = default;
};

} // impl
} // reader
} // loader

#endif //MESHFIGUREREADERIMPL_HPP
