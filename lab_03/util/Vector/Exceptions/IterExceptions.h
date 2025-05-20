#ifndef ITEREXCEPTIONS_H
#define ITEREXCEPTIONS_H

#include "BaseException.h"

class IterOutOfBondsException : public BaseException
{
public:
    IterOutOfBondsException(const char *filename, int line, const char *funcname,
                            const char *info = "Iterator out of bounds") noexcept :
        BaseException(filename, line, funcname, info)
    {
    }
};

class IterExpiredException : public BaseException
{
public:
    IterExpiredException(const char *filename, int line, const char *funcname,
                         const char *info = "Container data expired") noexcept :
        BaseException(filename, line, funcname, info)
    {
    }
};

#endif //ITEREXCEPTIONS_H