//
// Created by Roman Kanterov on 15.05.2025.
//

#ifndef TRANSFORMER_HPP
#define TRANSFORMER_HPP
#include "TransformData.hpp"
#include "ConstIterator.hpp"
#include "Iterator.hpp"
#include "Vector.hpp"
#include "ReverseIterator.h"
#include "ConstReverseIterator.h"
#include "ConstReverseIterator.hpp"
#include "ReverseIterator.hpp"

#include <Point.hpp>
#include <memory>

namespace core::objects
{
class BasePlainCameraImpl;
class BaseListMeshFigureImpl;
class BaseMatrixMeshFigureImpl;
}

namespace core {
namespace visitor {

class Transformer {
public:
    explicit Transformer(TransformData data) : data(data)
    {
    }
    void transform(std::shared_ptr<objects::BaseMatrixMeshFigureImpl>& fig);
    void transform(std::shared_ptr<objects::BaseListMeshFigureImpl>& fig);
    void transform(std::shared_ptr<objects::BasePlainCameraImpl> fig);
private:
    Point find_barycenter(std::vector<Point> &points);
    void move(std::vector<Point> &points);
    void rotate(std::vector<Point> &points);
    void rotate(Vector<double> &v);
    void scale(std::vector<Point> &points);
    void transformNodes(std::vector<Point> &points);

    TransformData data;
};

} // visitor
} // core

#endif //TRANSFORMER_HPP
