#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

#include <cstdio>
#include <exception>

class BaseException : public std::exception
{
public:
    BaseException(const char *filename, int line, const char *funcname, const char *info = "Unknown error") noexcept :
        filename(filename),
        line(line), funcname(funcname), info(info)
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
    const char *filename;
    int line;
    const char *funcname;
    const char *info;
};

#endif //BASEEXCEPTION_H