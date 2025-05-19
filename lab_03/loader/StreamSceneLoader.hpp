//
// Created by Roman Kanterov on 18.05.2025.
//

#ifndef STREAMSCENELOADER_HPP
#define STREAMSCENELOADER_HPP
#include "BaseSceneLoader.hpp"

#include <istream>
#include <fstream>

namespace loader {

class StreamSceneLoader : BaseSceneLoader {
private:
    std::shared_ptr<std::istream> stream;
    std::shared_ptr<reader::BaseMeshFigureReader> figReader;
    std::shared_ptr<reader::CameraReader> camReader;

public:
    explicit StreamSceneLoader(std::shared_ptr<std::istream> stream)
        : stream(std::move(stream))
    {}

    void load(std::shared_ptr<core::Scene> scene) override;
    void setFigReader(std::shared_ptr<reader::BaseMeshFigureReader> reader) override;
    void setCamReader(std::shared_ptr<reader::CameraReader> reader) override;
};

} // loader

#endif //STREAMSCENELOADER_HPP
