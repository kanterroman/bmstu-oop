#ifndef VECTOREXCEPTIONS_H
#define VECTOREXCEPTIONS_H

#include "BaseException.h"

class VectorBadAllocException : public BaseException
{
public:
    VectorBadAllocException(const char *filename, int line, const char *funcname, const char *info = "Couldn't allocate memory for vector") noexcept :
    BaseException(filename, line, funcname, info) {}
};

class VectorOutOfBondsException : public BaseException
{
public:
    VectorOutOfBondsException(const char *filename, int line, const char *funcname, const char *info = "Index of vector element out of bounds") noexcept :
    BaseException(filename, line, funcname, info) {}
};

class VectorInvalidSizeException : public BaseException
{
public:
    VectorInvalidSizeException(const char *filename, int line, const char *funcname, const char *info = "Vector size must be non-negative") noexcept :
    BaseException(filename, line, funcname, info) {}
};

class VectorNotEqDimException : public BaseException
{
public:
    VectorNotEqDimException(const char *filename, int line, const char *funcname, const char *info = "Vectors should be equal dimension") noexcept :
    BaseException(filename, line, funcname, info) {}
};

class VectorEmptyException : public BaseException
{
public:
    VectorEmptyException(const char *filename, int line, const char *funcname, const char *info = "Vector is empty") noexcept :
    BaseException(filename, line, funcname, info) {}
};

class ZeroElemVectorException : public BaseException
{
public:
    ZeroElemVectorException(const char *filename, int line, const char *funcname, const char *info = "Vector should not contain zero values") noexcept :
    BaseException(filename, line, funcname, info) {}
};

class ZeroValException : public BaseException
{
public:
    ZeroValException(const char *filename, int line, const char *funcname, const char *info = "Division by zero") noexcept :
    BaseException(filename, line, funcname, info) {}
};

class ZeroVectorException : public BaseException
{
public:
    ZeroVectorException(const char *filename, int line, const char *funcname, const char *info = "Vector can't be zero length") noexcept :
    BaseException(filename, line, funcname, info) {}
};

class WrongDimForCrossProductException : public BaseException
{
public:
    WrongDimForCrossProductException(const char *filename, int line, const char *funcname, const char *info = "Given vector doesn't support cross product") noexcept :
    BaseException(filename, line, funcname, info) {}
};

#endif //VECTOREXCEPTIONS_H
