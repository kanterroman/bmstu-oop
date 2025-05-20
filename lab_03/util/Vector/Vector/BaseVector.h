#ifndef BASEVECTOR_H
#define BASEVECTOR_H

#include <cstddef>

class BaseVector
{
public:
    using size_type = size_t;
    virtual ~BaseVector() = 0;

    virtual size_type size() const noexcept
    {
        return size_;
    }

protected:
    size_type size_ = 0;
};

#endif //BASEVECTOR_H