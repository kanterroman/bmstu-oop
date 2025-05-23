//
// Created by Roman Kanterov on 19.05.2025.
//

#include "ObjMeshFigureReaderImpl.hpp"
#include "../../exceptions/BadFileException.hpp"
#include "../../exceptions/OutOfBondsException.hpp"

namespace loader {
namespace reader {
namespace impl {
bool ObjMeshFigureReaderImpl::checkHeader(std::istream &stream)
{
    std::string header;
    stream >> header;
    if (header == HEADER_NAME)
        return true;
    return false;
}

void ObjMeshFigureReaderImpl::parseVertex(std::istream &stream)
{
    core::Point pt{};
    stream >> pt.x;
    stream >> pt.y;
    stream >> pt.z;
    points.push_back(pt);
}

void ObjMeshFigureReaderImpl::parseEdge(std::istream &stream)
{
    int first, second;
    stream >> first;
    stream >> second;
    --first;
    --second;
    if (first >= points.size() || second >= points.size())
        throw exceptions::OutOfBondsException(__FILE__, __LINE__, __FUNCTION__);
    buf->addEdge(points[first], points[second]);
}

std::shared_ptr<core::creators::buffers::MeshFigureBuffer> ObjMeshFigureReaderImpl::read(std::istream &stream)
{
    buf = std::make_shared<core::creators::buffers::MeshFigureBuffer>();
    streampos = stream.tellg();
    if (!checkHeader(stream))
    {
        stream.seekg(streampos);
        return nullptr;
    }

    std::string lex;
    while (stream >> lex)
    {
        if (lex == NODE_NAME)
            parseVertex(stream);
        else if (lex == EDGE_NAME)
            parseEdge(stream);
        else
            throw exceptions::BadFileException(__FILE__, __LINE__, __FUNCTION__);
    }

    return buf;
}
} // impl
} // reader
} // loader