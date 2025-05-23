//
// Created by Roman Kanterov on 20.05.2025.
//

#include "MeshFigureReaderImplCreatorSolution.hpp"

#include <utility>

namespace loader {
namespace reader {
namespace impl {
namespace creator {
std::shared_ptr<MeshFigureReaderImplCreator> MeshFigureReaderImplCreatorSolution::createCreator(
    std::filesystem::path &filepath)
{
    return map[filepath.extension()];
}

void MeshFigureReaderImplCreatorSolution::register_(std::filesystem::path &extension,
    std::shared_ptr<MeshFigureReaderImplCreator> cr)
{
    map[extension] = std::move(cr);
}
} // creator
} // impl
} // reader
} // loader