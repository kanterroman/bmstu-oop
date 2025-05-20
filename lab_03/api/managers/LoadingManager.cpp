//
// Created by Roman Kanterov on 20.05.2025.
//

#include "LoadingManager.hpp"
#include <fstream>

namespace api {
namespace managers {
void LoadingManager::loadToScene(std::filesystem::path &filepath, std::shared_ptr<SceneManager> manager)
{
    auto camImpl = camImplSolution.createCreator(filepath)->create();
    auto figImpl = figImplSolution.createCreator(filepath)->create();
    auto stream = openFile(filepath);
    auto camReader = camSolution.createCreator(loader::reader::creator::CameraReaderCreatorSolution::PlainCamera)->create(stream, camImpl);
    auto figReader = figSolution.createCreator(loader::reader::creator::BaseMeshFigureCreatorSolution::MeshFigure)->create(stream, figImpl);
    auto loader = loaderSolution.createCreator(loader::creator::SceneLoaderCreatorSolution::STREAM)->create(stream);
    loader->setCamReader(camReader);
    loader->setFigReader(figReader);
    loader->load(manager->get_scene());
}

std::shared_ptr<std::ifstream> LoadingManager::openFile(std::filesystem::path &filepath)
{
    auto is = std::make_shared<std::ifstream>(filepath);
    return is;
}
} // managers
} // api