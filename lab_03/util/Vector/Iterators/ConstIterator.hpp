#ifndef CONSTITERATOR_HPP
#define CONSTITERATOR_HPP

#include "ConstIterator.h"
#include "IterExceptions.h"

template <typename T>
ConstIterator<T>::ConstIterator() noexcept : array()
{
    this->size = 0;
    this->index = 0;
}

template <typename T>
ConstIterator<T>::ConstIterator(const ConstIterator &iter) noexcept
{
    this->array = iter.array;
    this->index = iter.index;
    this->size = iter.size;
}

template <typename T>
ConstIterator<T>::operator bool() const noexcept
{
    return this->array.expired();
}

template <typename T>
ConstIterator<T> &ConstIterator<T>::operator=(const ConstIterator &iter) noexcept
{
    this->array = iter.array;
    this->index = iter.index;
    this->size = iter.size;

    return *this;
}

template <typename T>
std::strong_ordering ConstIterator<T>::operator<=>(const ConstIterator &iter) const noexcept
{
    return this->index <=> iter.index;
}

template <typename T>
bool ConstIterator<T>::operator==(const ConstIterator &iter) const noexcept
{
    return this->array.lock().get() == iter.array.lock().get() && this->index == iter.index;
}

template <typename T>
ConstIterator<T> &ConstIterator<T>::operator++() noexcept
{
    ++this->index;
    return *this;
}

template <typename T>
ConstIterator<T> ConstIterator<T>::operator++(int) noexcept
{
    ConstIterator copy(*this);
    ++*this;
    return copy;
}

template <typename T>
ConstIterator<T> &ConstIterator<T>::operator--() noexcept
{
    --this->index;
    return *this;
}

template <typename T>
ConstIterator<T> ConstIterator<T>::operator--(int) noexcept
{
    ConstIterator copy(*this);
    --*this;
    return copy;
}

template <typename T>
ConstIterator<T> ConstIterator<T>::operator+(ptrdiff_t inc) const noexcept
{
    ConstIterator newIter(*this);
    newIter.index += inc;
    return newIter;
}

template <typename T>
ConstIterator<T> ConstIterator<T>::operator-(ptrdiff_t dec) const noexcept
{
    ConstIterator<T> newIter(*this);
    newIter.index -= dec;
    return newIter;
}

template <typename T>
ConstIterator<T> &ConstIterator<T>::operator+=(difference_type offset) noexcept
{
    this->index += offset;
    return *this;
}

template <typename T>
ConstIterator<T> &ConstIterator<T>::operator-=(difference_type offset) noexcept
{
    this->index -= offset;
    return *this;
}

template <typename T>
typename ConstIterator<T>::difference_type ConstIterator<T>::operator-(const ConstIterator &iter) const noexcept
{
    return this->index - iter.index;
}

template <typename T>
typename ConstIterator<T>::reference ConstIterator<T>::operator*() const
{
    assertInBounds(this->index, __FILE__, __LINE__, __FUNCTION__);
    assertNotExpired(__FILE__, __LINE__, __FUNCTION__);

    return array.lock()[this->index];
}

template <typename T>
typename ConstIterator<T>::pointer ConstIterator<T>::operator->() const
{
    assertInBounds(this->index, __FILE__, __LINE__, __FUNCTION__);
    assertNotExpired(__FILE__, __LINE__, __FUNCTION__);

    return array.lock().get() + this->index;
}

template <typename T>
typename ConstIterator<T>::reference ConstIterator<T>::operator[](size_t index) const
{
    assertInBounds(index, __FILE__, __LINE__, __FUNCTION__);
    assertNotExpired(__FILE__, __LINE__, __FUNCTION__);

    return array.lock()[index];
}

template <typename T>
ConstIterator<T>::ConstIterator(const std::shared_ptr<value_type[]> &arr, size_t size,
                                size_t index) noexcept : array(arr)
{
    this->size = size;
    this->index = index;
}

template <typename T>
void ConstIterator<T>::assertInBounds(size_t index, const char *file, int line, const char *func) const
{
    if (index >= this->size)
        throw IterOutOfBondsException(file, line, func);
}

template <typename T>
void ConstIterator<T>::assertNotExpired(const char *file, int line, const char *func) const
{
    if (this->array.expired())
        throw IterExpiredException(file, line, func);
}

template <typename T>
ConstIterator<T> operator+(ptrdiff_t inc, const ConstIterator<T> &iter) noexcept
{
    return iter + inc;
}

template <typename T>
ConstIterator<T> operator-(ptrdiff_t dec, const ConstIterator<T> &iter) noexcept
{
    return iter - dec;
}

#endif //CONSTITERATOR_HPP