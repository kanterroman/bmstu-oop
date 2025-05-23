#ifndef BASEMESHFIGUREREADER_HPP
#define BASEMESHFIGUREREADER_HPP
#include "buffers/MeshFigureBuffer.hpp"

namespace loader {
namespace reader {

class BaseMeshFigureReader {
public:
    virtual std::shared_ptr<core::creators::buffers::MeshFigureBuffer> read() = 0;
    virtual ~BaseMeshFigureReader() = default;
};

} // reader
} // loader

#endif //BASEMESHFIGUREREADER_HPP