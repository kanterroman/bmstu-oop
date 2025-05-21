//
// Created by Roman Kanterov on 21.05.2025.
//

#ifndef CANTOPENFILEEXCEPTION_HPP
#define CANTOPENFILEEXCEPTION_HPP
#include "BaseException.h"

namespace loader {
namespace exceptions {

class CantOpenFileException : BaseException {
public:
    CantOpenFileException(const char *filename, int line, const char *funcname,
    const char *info = "Couldn't open given file") noexcept :
    BaseException(filename, line, funcname, info)
    {
    }
};

} // exceptions
} // loader

#endif //CANTOPENFILEEXCEPTION_HPP
