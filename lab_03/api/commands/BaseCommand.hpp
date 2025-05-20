//
// Created by Roman Kanterov on 19.05.2025.
//

#ifndef BASECOMMAND_HPP
#define BASECOMMAND_HPP

namespace api {
namespace commands {

class BaseCommand {
public:
    virtual void execute() = 0;
    virtual void setManagers() = 0;
    virtual ~BaseCommand();
};

} // commands
} // api

#endif //BASECOMMAND_HPP
