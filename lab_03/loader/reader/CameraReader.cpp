//
// Created by Roman Kanterov on 19.05.2025.
//

#include "CameraReader.hpp"

namespace loader {
namespace reader {
void CameraReader::add(std::shared_ptr<CameraReader> reader)
{
    readers.push_back(reader);
}
} // reader
} // loader