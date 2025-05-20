//
// Created by Roman Kanterov on 20.05.2025.
//

#ifndef DRAWCOMMAND_HPP
#define DRAWCOMMAND_HPP
#include "BaseCommand.hpp"


namespace api::commands
{
class DrawCommand : public BaseCommand {
public:
    void execute() override;
};
}



#endif //DRAWCOMMAND_HPP
