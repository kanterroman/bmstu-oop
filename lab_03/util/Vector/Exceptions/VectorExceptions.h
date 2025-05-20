#ifndef VECTOREXCEPTIONS_H
#define VECTOREXCEPTIONS_H

#include "BaseException.h"

class VectorBadAllocException : public BaseException
{
public:
    VectorBadAllocException(const char *filename, int line, const char *funcname,
                            const char *info = "Couldn't allocate memory for vector") noexcept :
        BaseException(filename, line, funcname, info)
    {
    }
};

class VectorOutOfBondsException : public BaseException
{
public:
    VectorOutOfBondsException(const char *filename, int line, const char *funcname,
                              const char *info = "Index of vector element out of bounds") noexcept :
        BaseException(filename, line, funcname, info)
    {
    }
};

class VectorInvalidSizeException : public BaseException
{
public:
    VectorInvalidSizeException(const char *filename, int line, const char *funcname,
                               const char *info = "Vector size must be non-negative") noexcept :
        BaseException(filename, line, funcname, info)
    {
    }
};

class VectorNotEqDimException : public BaseException
{
public:
    VectorNotEqDimException(const char *filename, int line, const char *funcname,
                            const char *info = "Vectors should be equal dimension") noexcept :
        BaseException(filename, line, funcname, info)
    {
    }
};

class WrongDimForCrossProductException : public BaseException
{
public:
    WrongDimForCrossProductException(const char *filename, int line, const char *funcname,
                                     const char *info = "Given vector doesn't support cross product") noexcept :
        BaseException(filename, line, funcname, info)
    {
    }
};

class NullArrayException : public BaseException
{
public:
    NullArrayException(const char *filename, int line, const char *funcname,
                                     const char *info = "Given array is nullptr") noexcept :
        BaseException(filename, line, funcname, info)
    {
    }
};

#endif //VECTOREXCEPTIONS_H