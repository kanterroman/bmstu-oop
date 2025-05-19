//
// Created by Roman Kanterov on 15.05.2025.
//

#ifndef TRANSFORMER_HPP
#define TRANSFORMER_HPP
#include "ListMeshFigureImpl.hpp"
#include "MatrixMeshFigureImpl.hpp"
#include "PlainCameraImpl.hpp"

#include <Point.hpp>
#include <memory>

namespace core {
namespace visitor {

class Transformer {
private:
    double ax, ay, az;
    Point offset;
    double multip;
public:
    Transformer(double ax, double ay, double az, const Point &offset, double multip)
        : ax(ax),
          ay(ay),
          az(az),
          offset(offset),
          multip(multip)
    {
    }
    void transform(const std::shared_ptr<objects::BaseMatrixMeshFigureImpl>& fig);
    void transform(const std::shared_ptr<objects::BaseListMeshFigureImpl>& fig);
    void transform(std::shared_ptr<objects::BasePlainCameraImpl> fig);
private:
    Point find_barycenter(std::vector<Point> &points);
    void move(std::vector<Point> &points);
    void rotate(std::vector<Point> &points);
    void scale(std::vector<Point> &points);
    void transformNodes(std::vector<Point> &points);
};

} // visitor
} // core

#endif //TRANSFORMER_HPP
