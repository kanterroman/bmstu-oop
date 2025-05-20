//
// Created by Roman Kanterov on 20.05.2025.
//

#ifndef MESHFIGUREREADERIMPLCREATOR_HPP
#define MESHFIGUREREADERIMPLCREATOR_HPP
#include "../MeshFigureReaderImpl.hpp"

#include <memory>

namespace loader {
namespace reader {
namespace impl {
namespace creator {

class MeshFigureReaderImplCreator {
public:
    virtual std::shared_ptr<MeshFigureReaderImpl> create() = 0;
    virtual ~MeshFigureReaderImplCreator();
};

} // creator
} // impl
} // reader
} // loader

#endif //MESHFIGUREREADERIMPLCREATOR_HPP
