//
// Created by Roman Kanterov on 22.05.2025.
//

#ifndef OUTOFBONDSEXCEPTION_HPP
#define OUTOFBONDSEXCEPTION_HPP
#include "../../util/BaseException.hpp"

namespace loader {
namespace exceptions {

class OutOfBondsException : public util::BaseException {
public:
    OutOfBondsException(const char *filename, int line, const char *funcname,
    const char *info = "Edges are pointing to nodes that are not exist") noexcept :
    BaseException(filename, line, funcname, info)
    {
    }
};

} // exceptions
} // loader

#endif //OUTOFBONDSEXCEPTION_HPP
