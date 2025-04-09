#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

#include <exception>
#include <string_view>

class BaseException : public std::exception
{
public:
    BaseException(const char *filename, int line, const char *funcname, const char *info = "Unknown error") noexcept : filename(filename),
    line(line), funcname(funcname), info(info) {}

    [[nodiscard]] const char *what() const noexcept override
    {
        snprintf(errormsg, msglen, "Exception on %s:%d in %s : %s", filename, line, funcname, info);
        return errormsg;
    }
protected:
    static constexpr size_t msglen = 512;
    mutable char errormsg[msglen];
    int size;
    const char *filename;
    int line;
    const char *funcname;
    const char *info;
};

#endif //BASEEXCEPTION_H
