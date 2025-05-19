//
// Created by Roman Kanterov on 19.05.2025.
//

#include "TxtPlainCameraReaderImpl.hpp"

namespace loader {
namespace reader {
namespace impl {
bool TxtPlainCameraReaderImpl::checkHeader(std::istream &stream)
{
    std::string header;
    stream >> header;
    if (header == "cam")
        return true;
    return false;
}

void TxtPlainCameraReaderImpl::parsePoint(std::istream &stream)
{
    core::Point pt{};
    stream >> pt.x;
    stream >> pt.y;
    stream >> pt.z;
    buf->addPoint(pt);
}

void TxtPlainCameraReaderImpl::parseNormal(std::istream &stream)
{
    Vector<double> v{3};
    stream >> v[0];
    stream >> v[1];
    stream >> v[2];
    buf->addNormal(v);
}

std::shared_ptr<core::creators::buffers::CameraBuffer> TxtPlainCameraReaderImpl::read(std::istream &stream)
{
    buf = std::make_shared<core::creators::buffers::CameraBuffer>();
    streampos = stream.tellg();
    if (!checkHeader(stream))
    {
        stream.seekg(streampos);
        return nullptr;
    }

    std::string lex;
    while (stream >> lex)
    {
        if (lex == "normal")
            parseNormal(stream);
        else if (lex == "vertex")
            parsePoint(stream);
        else
            throw std::bad_cast();
    }

    return buf;
}
} // impl
} // reader
} // loader