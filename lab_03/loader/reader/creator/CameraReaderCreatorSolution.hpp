//
// Created by Roman Kanterov on 20.05.2025.
//

#ifndef CAMERACREATORSOLUTION_HPP
#define CAMERACREATORSOLUTION_HPP
#include "CameraReaderCreator.hpp"
#include "PlainCameraReaderCreator.hpp"

#include <unordered_map>

namespace loader {
namespace reader {
namespace creator {

class CameraReaderCreatorSolution {
public:
    using Tag = enum { PlainCamera };

    std::shared_ptr<CameraReaderCreator> createCreator(Tag id);
    void register_(Tag id, std::shared_ptr<CameraReaderCreator> cr);
private:
    std::unordered_map<Tag, std::shared_ptr<CameraReaderCreator>> map = { {Tag::PlainCamera, std::make_shared<PlainCameraReaderCreator>()} };
};

} // creator
} // reader
} // loader

#endif //CAMERACREATORSOLUTION_HPP
