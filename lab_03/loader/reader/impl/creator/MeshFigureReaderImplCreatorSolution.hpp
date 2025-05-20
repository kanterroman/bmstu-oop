//
// Created by Roman Kanterov on 20.05.2025.
//

#ifndef MESHFIGUREREADERIMPLCREATORSOLUTION_HPP
#define MESHFIGUREREADERIMPLCREATORSOLUTION_HPP
#include "CameraReaderImplCreator.hpp"
#include "MeshFigureReaderImplCreator.hpp"
#include "ObjMeshFigureReaderImplCreator.hpp"
#include "TxtMeshFigureReaderImplCreator.hpp"

#include <unordered_map>
#include <__filesystem/path.h>

namespace loader {
namespace reader {
namespace impl {
namespace creator {

class MeshFigureReaderImplCreatorSolution {
private:
    std::unordered_map<std::filesystem::path, std::shared_ptr<MeshFigureReaderImplCreator>> map = { {".txt", std::make_shared<TxtMeshFigureReaderImplCreator>() },
                                                                                                {".obj", std::make_shared<ObjMeshFigureReaderImplCreator>()}};
public:
    std::shared_ptr<MeshFigureReaderImplCreator> createCreator(std::filesystem::path &filepath);
    void register_(std::filesystem::path &extension, std::shared_ptr<MeshFigureReaderImplCreator> cr);
};

} // creator
} // impl
} // reader
} // loader

#endif //MESHFIGUREREADERIMPLCREATORSOLUTION_HPP
