//
// Created by Roman Kanterov on 20.05.2025.
//

#ifndef TRANSFORMCOMMAND_HPP
#define TRANSFORMCOMMAND_HPP
#include "BaseCommand.hpp"

namespace api {
namespace commands {

class TransformCommand : public BaseCommand {
private:
    double dx, dy, dz;
    double ax, ay, az;
    double multip;
public:
    TransformCommand(double dx, double dy, double dz, double ax, double ay, double az, double multip)
        : dx(dx),
          dy(dy),
          dz(dz),
          ax(ax),
          ay(ay),
          az(az),
          multip(multip)
    {
    }
    void execute() override;
};

} // commands
} // api

#endif //TRANSFORMCOMMAND_HPP
