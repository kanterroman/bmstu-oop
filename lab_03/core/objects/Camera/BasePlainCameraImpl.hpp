//
// Created by Roman Kanterov on 16.05.2025.
//

#ifndef BASEPLAINCAMERAIMPL_HPP
#define BASEPLAINCAMERAIMPL_HPP
#include <Point.hpp>

namespace core::objects
{
class BasePlainCameraImpl {
public:
    virtual Point getVisPoint() const = 0;
    virtual void set_vis_point(const Point &vis_point) = 0;
    virtual double get_ax() const = 0;
    virtual void set_ax(double ax) = 0;
    virtual double get_ay() const = 0;
    virtual void set_ay(double ay) = 0;
    virtual double get_az() const = 0;
    virtual void set_az(double az) = 0;
    virtual ~BasePlainCameraImpl() = 0;
};
}



#endif //BASEPLAINCAMERAIMPL_HPP
