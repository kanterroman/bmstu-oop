#ifndef BASEITERATOR_H
#define BASEITERATOR_H
#include <memory>

class BaseIterator
{
public:
    virtual ~BaseIterator() = default;

protected:
    size_t index = 0;
    size_t size = 0;
};

#endif //BASEITERATOR_H
