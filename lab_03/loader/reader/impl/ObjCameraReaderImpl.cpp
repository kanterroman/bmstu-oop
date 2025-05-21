//
// Created by Roman Kanterov on 19.05.2025.
//

#include "ObjCameraReaderImpl.hpp"

#include "../../exceptions/BadFileException.hpp"

namespace loader {
namespace reader {
namespace impl {
bool ObjCameraReaderImpl::checkHeader(std::istream &stream)
{
    std::string header;
    stream >> header;
    if (header == "cam")
        return true;
    return false;
}

void ObjCameraReaderImpl::parsePoint(std::istream &stream)
{
    core::Point pt{};
    stream >> pt.x;
    stream >> pt.y;
    stream >> pt.z;
    buf->addPoint(pt);
}

void ObjCameraReaderImpl::parseNormal(std::istream &stream)
{
    Vector<double> v{0, 0, 0};
    stream >> v[0];
    stream >> v[1];
    stream >> v[2];
    buf->addNormal(v);
}

std::shared_ptr<core::creators::buffers::CameraBuffer> ObjCameraReaderImpl::read(std::istream &stream)
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
        if (lex == "vn")
            parseNormal(stream);
        else if (lex == "v")
            parsePoint(stream);
        else
            throw exceptions::BadFileException(__FILE__, __LINE__, __FUNCTION__);
    }

    return buf;
}
} // impl
} // reader
} // loader