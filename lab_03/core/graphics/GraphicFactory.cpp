//
// Created by Roman Kanterov on 15.05.2025.
//

#include "GraphicFactory.hpp"

namespace core {
namespace graphics {
std::shared_ptr<Graphics> GraphicFactory::getGraphics()
{
    if (!gr)
        gr = createGraphics();
    return gr;
}

GraphicFactory::~GraphicFactory() = default;
} // graphics
} // core