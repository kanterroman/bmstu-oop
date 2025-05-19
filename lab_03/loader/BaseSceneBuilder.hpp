//
// Created by Roman Kanterov on 19.05.2025.
//

#ifndef BASESCENEBUILDER_HPP
#define BASESCENEBUILDER_HPP
#include "reader/BaseMeshFigureReader.hpp"
#include "reader/CameraReader.hpp"

#include <Scene.hpp>
#include <memory>
namespace loader {

class BaseSceneBuilder {
public:
    virtual void loadCameras(std::shared_ptr<core::Scene> scene) = 0;
    virtual void loadFigures(std::shared_ptr<core::Scene> scene) = 0;
    virtual void setStream(std::shared_ptr<std::istream>) = 0;
    virtual void setCamReader(std::shared_ptr<reader::CameraReader>) = 0;
    virtual void setFigReader(std::shared_ptr<reader::BaseMeshFigureReader>) = 0;
    virtual ~BaseSceneBuilder() = 0;
};

} // loader

#endif //BASESCENEBUILDER_HPP
