//
// Created by Roman Kanterov on 22.05.2025.
//

#ifndef NOTFOUNDEXCEPTION_HPP
#define NOTFOUNDEXCEPTION_HPP
#include "BaseException.h"

namespace api {
namespace exceptions {

class NotFoundException : BaseException {
public:
    NotFoundException(const char *filename, int line, const char *funcname,
    const char *info = "Element not found") noexcept :
    BaseException(filename, line, funcname, info)
    {
    }
};

} // exceptions
} // api

#endif //NOTFOUNDEXCEPTION_HPP
