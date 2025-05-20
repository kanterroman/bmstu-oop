//
// Created by Roman Kanterov on 20.05.2025.
//

#ifndef CAMERAREADERIMPLCREATORSOLUTION_HPP
#define CAMERAREADERIMPLCREATORSOLUTION_HPP
#include "CameraReaderImplCreator.hpp"
#include "ObjCameraReaderImplCreator.hpp"
#include "TxtCameraReaderImplCreator.hpp"

#include <memory>
#include <__filesystem/filesystem_error.h>

namespace loader {
namespace reader {
namespace impl {
namespace creator {

class CameraReaderImplCreatorSolution {
private:
    std::unordered_map<std::filesystem::path, std::shared_ptr<CameraReaderImplCreator>> map = { {".txt", std::make_shared<TxtCameraReaderImplCreator>() },
                                                                                                {".obj", std::make_shared<ObjCameraReaderImplCreator>()}};
public:
    std::shared_ptr<CameraReaderImplCreator> createCreator(std::filesystem::path &filepath);
    void register_(std::filesystem::path &extension, std::shared_ptr<CameraReaderImplCreator> cr);
};

} // creator
} // impl
} // reader
} // loader

#endif //CAMERAREADERIMPLCREATORSOLUTION_HPP
