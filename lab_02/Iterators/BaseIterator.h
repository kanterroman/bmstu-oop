#ifndef BASEITERATOR_H
#define BASEITERATOR_H
#include <memory>

class BaseIterator
{
public:
    virtual ~BaseIterator() = default;

protected:
    size_t index = 0;
    std::weak_ptr<size_t> size;
};

#endif //BASEITERATOR_H
