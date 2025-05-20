//
// Created by Roman Kanterov on 20.05.2025.
//

#include "CameraReaderCreatorSolution.hpp"

#include <utility>

namespace loader {
namespace reader {
namespace creator {
std::shared_ptr<CameraReaderCreator> CameraReaderCreatorSolution::createCreator(Tag id)
{
    return map[id];
}

void CameraReaderCreatorSolution::register_(Tag id, std::shared_ptr<CameraReaderCreator> cr)
{
    map[id] = std::move(cr);
}
} // creator
} // reader
} // loader