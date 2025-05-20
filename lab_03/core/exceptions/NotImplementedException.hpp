//
// Created by Roman Kanterov on 20.05.2025.
//

#ifndef NOTIMPLEMENTEDEXCEPTION_HPP
#define NOTIMPLEMENTEDEXCEPTION_HPP
#include "../../util/BaseException.hpp"

namespace core {
namespace exceptions {

class NotImplementedException : public util::BaseException {
public:
    NotImplementedException(const char *filename, int line, const char *funcname,
                            const char *info = "Method not implemented") noexcept :
        BaseException(filename, line, funcname, info)
    {
    }
};

} // exceptions
} // core

#endif //NOTIMPLEMENTEDEXCEPTION_HPP
