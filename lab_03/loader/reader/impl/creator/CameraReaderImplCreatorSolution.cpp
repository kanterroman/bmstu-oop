//
// Created by Roman Kanterov on 20.05.2025.
//

#include "CameraReaderImplCreatorSolution.hpp"

#include <utility>

namespace loader {
namespace reader {
namespace impl {
namespace creator {
std::shared_ptr<CameraReaderImplCreator> CameraReaderImplCreatorSolution::createCreator(std::filesystem::path &filepath)
{
    auto ext = filepath.extension();
    return map[ext];
}

void CameraReaderImplCreatorSolution::register_(std::filesystem::path &extension,
    std::shared_ptr<CameraReaderImplCreator> cr)
{
    map[extension] = std::move(cr);
}
} // creator
} // impl
} // reader
} // loader