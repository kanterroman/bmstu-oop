cmake_minimum_required(VERSION 3.28)
project(lab_01 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_COMPILER clang++)

set(APP_NAME "app.exe")

find_package(GTest REQUIRED)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED
)

add_executable(${APP_NAME}
    core/Scene.cpp
        core/objects/Figure/Figure.cpp
        core/objects/SceneComposite.cpp
        core/objects/SceneObject.cpp
        core/visitor/SceneObjectVisitor.cpp
        core/objects/Camera/Camera.cpp
        core/objects/Figure/ListMeshFigure.cpp
        core/objects/Figure/ListMeshFigure.hpp
        core/objects/Figure/MatrixMeshFigure.hpp
        core/objects/Figure/MatrixMeshFigure.cpp
        core/objects/Figure/ListMeshFigureImpl.cpp
        core/objects/Figure/ListMeshFigureImpl.hpp
        core/objects/Figure/MatrixMeshFigureImpl.cpp
        core/objects/Figure/MatrixMeshFigureImpl.hpp
        core/objects/Camera/PlainCamera.cpp
        core/objects/Camera/PlainCamera.hpp
        core/objects/Camera/PlainCameraImpl.cpp
        core/objects/Camera/PlainCameraImpl.hpp
        core/visitor/Transformer.cpp
        core/visitor/Transformer.hpp
        core/graphics/GraphicFactory.cpp
        core/graphics/GraphicFactory.hpp
        core/graphics/QtGraphicFactory.cpp
        core/graphics/QtGraphicFactory.hpp
        core/graphics/Painter.cpp
        core/graphics/Painter.hpp
        core/graphics/Canvas.cpp
        core/graphics/Canvas.hpp
        core/graphics/GraphicPoint.cpp
        core/graphics/GraphicPoint.hpp
        core/graphics/QtCanvas.cpp
        core/graphics/QtCanvas.hpp
        core/graphics/QtGraphicPoint.cpp
        core/graphics/QtGraphicPoint.hpp
        core/graphics/QtPainter.cpp
        core/graphics/QtPainter.hpp
        core/graphics/Graphics.cpp
        core/graphics/Graphics.hpp
        core/graphics/QtGraphics.cpp
        core/graphics/QtGraphics.hpp
        core/visitor/TransformVisitor.cpp
        core/visitor/TransformVisitor.hpp
        core/visitor/DrawVisitor.cpp
        core/visitor/DrawVisitor.hpp
        core/visitor/Drawer.cpp
        core/visitor/Drawer.hpp
        core/creators/SceneObjectCreator.cpp
        core/creators/SceneObjectCreator.hpp
        core/objects/Camera/BasePlainCameraImpl.cpp
        core/objects/Camera/BasePlainCameraImpl.hpp
        core/objects/Figure/BaseMatrixMeshFigureImpl.cpp
        core/objects/Figure/BaseMatrixMeshFigureImpl.hpp
        core/objects/Figure/BaseListMeshFigureImpl.cpp
        core/objects/Figure/BaseListMeshFigureImpl.hpp
        util/Vector/Vector/Vector.h
        util/Vector/Vector/Vector.hpp
        util/Vector/Vector/BaseVector.cpp
        util/Vector/Iterators/BaseIterator.cpp
        core/creators/buffers/CameraBuffer.cpp
        core/creators/buffers/CameraBuffer.hpp
        core/creators/buffers/MeshFigureBuffer.cpp
        core/creators/buffers/MeshFigureBuffer.hpp
        core/creators/CameraCreator.cpp
        core/creators/CameraCreator.hpp
        core/creators/PlainCameraDirector.cpp
        core/creators/PlainCameraDirector.hpp
        core/creators/builders/PlainCameraBuilder.cpp
        core/creators/builders/PlainCameraBuilder.hpp
        core/creators/builders/MatrixMeshFigureBuilder.cpp
        core/creators/builders/MatrixMeshFigureBuilder.hpp
        core/creators/builders/ListMeshFigureBuilder.cpp
        core/creators/builders/ListMeshFigureBuilder.hpp
        core/creators/MeshFigureCreator.cpp
        core/creators/MeshFigureCreator.hpp
        core/creators/MatrixMeshFigureDirector.cpp
        core/creators/MatrixMeshFigureDirector.hpp
        core/creators/ListMeshFigureDirector.cpp
        core/creators/ListMeshFigureDirector.hpp
        core/creators/SceneObjectCreatorSolution.hpp
        util/concepts.hpp
        loader/BaseSceneLoader.hpp
        api/Facade.cpp
        api/Facade.hpp
        api/commands/BaseCommand.cpp
        api/commands/BaseCommand.hpp
        api/managers/SceneManager.cpp
        api/managers/SceneManager.hpp
        loader/StreamSceneLoader.hpp
        loader/StreamSceneBuilder.cpp
        loader/StreamSceneBuilder.hpp
        loader/BaseSceneBuilder.cpp
        loader/BaseSceneBuilder.hpp
        loader/reader/CameraReader.cpp
        loader/reader/CameraReader.hpp
        loader/reader/PlainCameraReader.cpp
        loader/reader/PlainCameraReader.hpp
        loader/reader/impl/CameraReaderImpl.cpp
        loader/reader/impl/CameraReaderImpl.hpp
        loader/reader/MeshFigureReader.cpp
        loader/reader/MeshFigureReader.hpp
        loader/reader/BaseMeshFigureReader.hpp
        loader/reader/impl/MeshFigureReaderImpl.cpp
        loader/reader/impl/MeshFigureReaderImpl.hpp
        loader/reader/impl/ObjMeshFigureReaderImpl.cpp
        loader/reader/impl/ObjMeshFigureReaderImpl.hpp
        loader/reader/impl/TxtMeshFigureReaderImpl.cpp
        loader/reader/impl/TxtMeshFigureReaderImpl.hpp
        loader/reader/impl/ObjCameraReaderImpl.cpp
        loader/reader/impl/ObjCameraReaderImpl.hpp
        loader/reader/impl/TxtCameraReaderImpl.cpp
        loader/reader/impl/TxtCameraReaderImpl.hpp
        loader/StreamSceneLoader.cpp
        loader/reader/creator/CameraReaderCreator.cpp
        loader/reader/creator/CameraReaderCreator.hpp
        loader/reader/creator/PlainCameraReaderCreator.cpp
        loader/reader/creator/PlainCameraReaderCreator.hpp
        loader/reader/creator/BaseMeshFigureReaderCreator.cpp
        loader/reader/creator/BaseMeshFigureReaderCreator.hpp
        loader/reader/creator/MeshFigureReaderCreator.cpp
        loader/reader/creator/MeshFigureReaderCreator.hpp
        loader/reader/impl/creator/CameraReaderImplCreator.cpp
        loader/reader/impl/creator/CameraReaderImplCreator.hpp
        loader/reader/impl/creator/ObjCameraReaderImplCreator.cpp
        loader/reader/impl/creator/ObjCameraReaderImplCreator.hpp
        loader/reader/impl/creator/TxtCameraReaderImplCreator.cpp
        loader/reader/impl/creator/TxtCameraReaderImplCreator.hpp
        loader/reader/impl/creator/MeshFigureReaderImplCreator.cpp
        loader/reader/impl/creator/MeshFigureReaderImplCreator.hpp
        loader/reader/impl/creator/ObjMeshFigureReaderImplCreator.cpp
        loader/reader/impl/creator/ObjMeshFigureReaderImplCreator.hpp
        loader/reader/impl/creator/TxtMeshFigureReaderImplCreator.cpp
        loader/reader/impl/creator/TxtMeshFigureReaderImplCreator.hpp
        loader/reader/impl/creator/CameraReaderImplCreatorSolution.cpp
        loader/reader/impl/creator/CameraReaderImplCreatorSolution.hpp
        loader/reader/impl/creator/MeshFigureReaderImplCreatorSolution.cpp
        loader/reader/impl/creator/MeshFigureReaderImplCreatorSolution.hpp
        loader/reader/creator/BaseMeshFigureReaderCreatorSolution.cpp
        loader/reader/creator/BaseMeshFigureReaderCreatorSolution.hpp
        loader/reader/creator/CameraReaderCreatorSolution.cpp
        loader/reader/creator/CameraReaderCreatorSolution.hpp
        api/commands/TransformCommand.cpp
        api/commands/TransformCommand.hpp
        api/commands/TransformCommand.hpp
        api/managers/TransformManager.cpp
        api/managers/TransformManager.hpp
        core/visitor/TransformData.hpp
        api/managers/SelectionManager.cpp
        api/managers/SelectionManager.hpp
)

include_directories(
        core
        core/creators
        core/objects
        core/objects/Camera
        core/objects/Figure
        core/visitor
        core/graphics
)

target_link_libraries(${APP_NAME}
        Qt::Core
        Qt::Gui
        Qt::Widgets
        GTest::GTest
)

target_include_directories(${APP_NAME} PUBLIC ${GTEST_INCLUDE_DIR})
target_compile_options(${APP_NAME} PUBLIC -fprofile-instr-generate -fcoverage-mapping)
target_link_options(${APP_NAME} PUBLIC -fprofile-instr-generate -fcoverage-mapping)
