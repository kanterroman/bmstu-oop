//
// Created by Roman Kanterov on 19.05.2025.
//

#ifndef OBJMESHFIGUREREADERIMPL_HPP
#define OBJMESHFIGUREREADERIMPL_HPP
#include "MeshFigureReaderImpl.hpp"
#include <istream>

namespace loader {
namespace reader {
namespace impl {

class ObjMeshFigureReaderImpl : public MeshFigureReaderImpl {
public:
    std::shared_ptr<core::creators::buffers::MeshFigureBuffer> read(std::istream &stream) override;
private:
    std::vector<core::Point> points;
    std::shared_ptr<core::creators::buffers::MeshFigureBuffer> buf{};
    bool checkHeader(std::istream &stream);
    std::istream::pos_type streampos;
    void parseVertex(std::istream &stream);
    void parseEdge(std::istream &stream);
};

} // impl
} // reader
} // loader

#endif //OBJMESHFIGUREREADERIMPL_HPP
