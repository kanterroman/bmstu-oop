#ifndef STREAMSCENEBUILDER_HPP
#define STREAMSCENEBUILDER_HPP
#include "BaseSceneBuilder.hpp"
#include "reader/BaseMeshFigureReader.hpp"
#include "reader/CameraReader.hpp"

namespace loader {
class StreamSceneBuilder : public BaseSceneBuilder {
private:
    std::shared_ptr<std::istream> stream{};
    std::shared_ptr<reader::CameraReader> camreader{};
    std::shared_ptr<reader::BaseMeshFigureReader> figreader{};
public:
    void loadCameras(std::shared_ptr<core::Scene> scene) override;
    void loadFigures(std::shared_ptr<core::Scene> scene) override;
    void setStream(std::shared_ptr<std::istream> stream) override;
    void setCamReader(std::shared_ptr<reader::CameraReader> reader) override;
    void setFigReader(std::shared_ptr<reader::BaseMeshFigureReader> reader) override;
};

} // loader

#endif //STREAMSCENEBUILDER_HPP
