//
// Created by Roman Kanterov on 20.05.2025.
//

#ifndef BASEEXCEPTION_HPP
#define BASEEXCEPTION_HPP
#include <cstdio>
#include <exception>

namespace util {

class BaseException : public std::exception
{
public:
    BaseException(const char *filename, int line, const char *funcname, const char *info = "Unknown error") noexcept
    {
        snprintf(errormsg, msglen, "Exception on %s:%d in %s : %s", filename, line, funcname, info);
    }

    const char *what() const noexcept override
    {
        return errormsg;
    }

protected:
    static constexpr size_t msglen = 512;
    char errormsg[msglen]{};
};
} // util

#endif //BASEEXCEPTION_HPP
