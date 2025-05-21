//
// Created by Roman Kanterov on 19.05.2025.
//

#ifndef TXTMESHFIGUREREADERIMPL_HPP
#define TXTMESHFIGUREREADERIMPL_HPP
#include "MeshFigureReaderImpl.hpp"
#include <istream>

namespace loader {
namespace reader {
namespace impl {

class TxtMeshFigureReaderImpl : public MeshFigureReaderImpl {
public:
    std::shared_ptr<core::creators::buffers::MeshFigureBuffer> read(std::istream &stream) override;
private:
    std::vector<core::Point> points;
    std::shared_ptr<core::creators::buffers::MeshFigureBuffer> buf{};
    bool checkHeader(std::istream &stream);
    std::istream::pos_type streampos;
    void parseVertex(std::istream &stream);
    void parseEdge(std::istream &stream);
    static constexpr std::string HEADER_NAME = "fig";
    static constexpr std::string NODE_NAME = "point";
    static constexpr std::string EDGE_NAME = "edge";
};

} // impl
} // reader
} // loader

#endif //TXTMESHFIGUREREADERIMPL_HPP
