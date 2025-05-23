//
// Created by Roman Kanterov on 21.05.2025.
//

#ifndef BADFILEEXCEPTION_HPP
#define BADFILEEXCEPTION_HPP
#include "BaseException.h"

namespace loader {
namespace exceptions {

class BadFileException : BaseException {
public:
    BadFileException(const char *filename, int line, const char *funcname,
    const char *info = "Given file is of wrong format") noexcept :
    BaseException(filename, line, funcname, info)
    {
    }
};

} // exceptions
} // loader

#endif //BADFILEEXCEPTION_HPP
