//
// Created by Roman Kanterov on 20.05.2025.
//

#include "BaseMeshFigureReaderCreatorSolution.hpp"

#include <utility>

namespace loader {
namespace reader {
namespace creator {
std::shared_ptr<BaseMeshFigureReaderCreator> BaseMeshFigureCreatorSolution::createCreator(Tag id)
{
    return map[id];
}

void BaseMeshFigureCreatorSolution::register_(Tag id, std::shared_ptr<BaseMeshFigureReaderCreator> cr)
{
    map[id] = std::move(cr);
}
} // creator
} // reader
} // loader