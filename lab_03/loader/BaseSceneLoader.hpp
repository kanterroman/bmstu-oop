//
// Created by Roman Kanterov on 17.05.2025.
//

#ifndef BASESCENELOADER_HPP
#define BASESCENELOADER_HPP
#include "reader/BaseMeshFigureReader.hpp"
#include "reader/CameraReader.hpp"

#include <Scene.hpp>
#include <vector>
#include <string>

namespace loader {

class BaseSceneLoader {
public:
    virtual void load(std::shared_ptr<core::Scene>) = 0;
    virtual void setFigReader(std::shared_ptr<reader::BaseMeshFigureReader>) = 0;
    virtual void setCamReader(std::shared_ptr<reader::CameraReader>) = 0;
    virtual ~BaseSceneLoader() = 0;
};

} // loader

#endif //BASESCENELOADER_HPP
