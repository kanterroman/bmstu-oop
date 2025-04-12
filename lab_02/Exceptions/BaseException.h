#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

#include <cstdio>
#include <exception>

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

#endif //BASEEXCEPTION_H