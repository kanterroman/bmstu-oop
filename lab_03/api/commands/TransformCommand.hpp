//
// Created by Roman Kanterov on 20.05.2025.
//

#ifndef TRANSFORMCOMMAND_HPP
#define TRANSFORMCOMMAND_HPP
#include "BaseCommand.hpp"

namespace api {
namespace commands {

class TransformCommand : public BaseCommand {
public:
    explicit TransformCommand(const TransformData &data)
        : data(data)
    {}
    void execute() override;
private:
    TransformData data{};
};

} // commands
} // api

#endif //TRANSFORMCOMMAND_HPP
