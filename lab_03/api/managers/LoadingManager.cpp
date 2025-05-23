//
// Created by Roman Kanterov on 20.05.2025.
//

#include "LoadingManager.hpp"

#include "../../loader/exceptions/CantOpenFileException.hpp"

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
    auto loader = loaderSolution.createCreator(loader::creator::SceneLoaderCreatorSolution::STREAM)->create();
    loader->setCamReader(camReader);
    loader->setFigReader(figReader);
    loader->load(manager->getScene());
}

std::shared_ptr<std::ifstream> LoadingManager::openFile(std::filesystem::path &filepath)
{
    auto is = std::make_shared<std::ifstream>(filepath);
    if (!is->is_open())
        throw loader::exceptions::CantOpenFileException(__FILE__, __LINE__, __FUNCTION__);
    return is;
}
} // managers
} // api