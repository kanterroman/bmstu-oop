//
// Created by Roman Kanterov on 20.05.2025.
//

#ifndef LOADINGMANAGER_HPP
#define LOADINGMANAGER_HPP
#include "SceneManager.hpp"
#include "../../loader/creator/SceneLoaderCreatorSolution.hpp"
#include "../../loader/reader/creator/BaseMeshFigureReaderCreatorSolution.hpp"
#include "../../loader/reader/creator/CameraReaderCreatorSolution.hpp"
#include "../../loader/reader/creator/MeshFigureReaderCreator.hpp"
#include "../../loader/reader/impl/creator/CameraReaderImplCreatorSolution.hpp"
#include "../../loader/reader/impl/creator/MeshFigureReaderImplCreatorSolution.hpp"

#include <__filesystem/filesystem_error.h>

namespace api {
namespace managers {

class LoadingManager {
public:
    void loadToScene(std::filesystem::path &filepath, std::shared_ptr<SceneManager> manager);
private:
    std::shared_ptr<std::ifstream> openFile(std::filesystem::path &filepath);
    loader::reader::impl::creator::CameraReaderImplCreatorSolution camImplSolution{};
    loader::reader::impl::creator::MeshFigureReaderImplCreatorSolution figImplSolution{};
    loader::reader::creator::CameraReaderCreatorSolution camSolution{};
    loader::reader::creator::BaseMeshFigureCreatorSolution figSolution{};
    loader::creator::SceneLoaderCreatorSolution loaderSolution{};
};

} // managers
} // api

#endif //LOADINGMANAGER_HPP
