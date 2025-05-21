//
// Created by Roman Kanterov on 21.05.2025.
//

#ifndef NOTACAMERAEXCEPTION_HPP
#define NOTACAMERAEXCEPTION_HPP
#include "../../util/BaseException.hpp"

namespace api {
namespace exceptions {

class NotACameraException : public util::BaseException {
public:
    NotACameraException(const char *filename, int line, const char *funcname,
    const char *info = "Given object is not camera") noexcept :
    BaseException(filename, line, funcname, info)
    {
    }
};

} // exceptions
} // api

#endif //NOTACAMERAEXCEPTION_HPP
