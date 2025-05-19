//
// Created by Roman Kanterov on 19.05.2025.
//

#include "StreamSceneBuilder.hpp"

#include "MatrixMeshFigureDirector.hpp"
#include "PlainCameraDirector.hpp"
#include "SceneObjectCreatorSolution.hpp"

namespace loader {
void StreamSceneBuilder::loadCameras(std::shared_ptr<core::Scene> scene)
{
    auto buf = camreader->read();
    if (!buf)
        return;
    auto solution = std::make_shared<core::creators::SceneObjectCreatorSolution>();
    auto creator = solution->createCreator<core::creators::PlainCameraDirector>();
    auto obj = creator->create(buf);
    scene->add(*obj);
}

void StreamSceneBuilder::loadFigures(std::shared_ptr<core::Scene> scene)
{
    auto buf = figreader->read();
    if (!buf)
        return;
    auto solution = std::make_shared<core::creators::SceneObjectCreatorSolution>();
    auto creator = solution->createCreator<core::creators::MatrixMeshFigureDirector>();
    auto obj = creator->create(buf);
    scene->add(*obj);
}

void StreamSceneBuilder::setStream(std::shared_ptr<std::istream> stream)
{
    this->stream = stream;
}

void StreamSceneBuilder::setCamReader(std::shared_ptr<reader::CameraReader> reader)
{
    camreader = reader;
}

void StreamSceneBuilder::setFigReader(std::shared_ptr<reader::BaseMeshFigureReader> reader)
{
    figreader = reader;
}
} // loader