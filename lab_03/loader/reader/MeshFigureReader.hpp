//
// Created by Roman Kanterov on 19.05.2025.
//

#ifndef MESHFIGUREREADER_HPP
#define MESHFIGUREREADER_HPP

#include "BaseMeshFigureReader.hpp"
#include "impl/MeshFigureReaderImpl.hpp"

namespace loader {
namespace reader {

class MeshFigureReader : public BaseMeshFigureReader {
public:
    MeshFigureReader(const std::shared_ptr<std::istream> &stream,
        const std::shared_ptr<impl::MeshFigureReaderImpl> &impl)
        : stream(stream),
          impl(impl)
    {
    }

    std::shared_ptr<core::creators::buffers::MeshFigureBuffer> read() override;
private:
    std::shared_ptr<std::istream> stream;
    std::shared_ptr<impl::MeshFigureReaderImpl> impl;
};

} // reader
} // loader

#endif //MESHFIGUREREADER_HPP
