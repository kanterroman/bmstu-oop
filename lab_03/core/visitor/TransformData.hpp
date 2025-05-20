//
// Created by Roman Kanterov on 20.05.2025.
//

#ifndef TRANSFORMDATA_HPP
#define TRANSFORMDATA_HPP
#include <Point.hpp>

struct TransformData
{
    double ax, ay, az;
    core::Point offset;
    double multip;
};

#endif //TRANSFORMDATA_HPP
