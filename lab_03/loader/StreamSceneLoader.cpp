//
// Created by Roman Kanterov on 18.05.2025.
//

#include "StreamSceneLoader.hpp"

#include "BaseSceneBuilder.hpp"
#include "StreamSceneBuilder.hpp"
#include "reader/MeshFigureReader.hpp"

namespace loader {
void StreamSceneLoader::load(std::shared_ptr<core::Scene> scene)
{
    auto builder = std::make_shared<StreamSceneBuilder>();
    builder->setStream(stream);
    builder->setFigReader(figReader);
    builder->setCamReader(camReader);
    builder->loadCameras(scene);
    builder->loadFigures(scene);
}

void StreamSceneLoader::setFigReader(std::shared_ptr<reader::BaseMeshFigureReader> reader)
{
    figReader = reader;
}

void StreamSceneLoader::setCamReader(std::shared_ptr<reader::CameraReader> reader)
{
    camReader = reader;
}
} // loader