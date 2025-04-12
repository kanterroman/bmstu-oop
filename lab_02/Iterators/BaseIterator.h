#ifndef BASEITERATOR_H
#define BASEITERATOR_H

#include <cstddef>

class BaseIterator
{
public:
    virtual ~BaseIterator() = 0;

protected:
    size_t index = 0;
    size_t size = 0;
};

inline BaseIterator::~BaseIterator() = default;

#endif //BASEITERATOR_H