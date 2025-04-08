#ifndef CONSTITERATOR_HPP
#define CONSTITERATOR_HPP

#include "ConstIterator.h"
#include "../Exceptions/IterExceptions.h"

template <typename T>
ConstIterator<T>::ConstIterator() noexcept : array()
{
    this->size();
    this->index();
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
ConstIterator<T> & ConstIterator<T>::operator=(const ConstIterator &iter) noexcept
{
    this->array = iter.array;
    this->index = iter.index;
    this->size = iter.size;

    return *this;
}

template <typename T>
std::strong_ordering ConstIterator<T>::operator<=>(const ConstIterator &iter) const noexcept
{
    if (this->index < iter.index)
        return std::strong_ordering::less;
    if (this->index == iter.index)
        return std::strong_ordering::equal;
    return std::strong_ordering::greater;
}

template <typename T>
bool ConstIterator<T>::operator==(const ConstIterator &iter) const noexcept
{
    return this->index == iter.index;
}

template <typename T>
ConstIterator<T> & ConstIterator<T>::operator++() noexcept
{
    ++this->index;
    return *this;
}

template <typename T>
ConstIterator<T> ConstIterator<T>::operator++(int) noexcept
{
    ConstIterator copy(*this);
    ++this;
    return copy;
}

template <typename T>
ConstIterator<T> & ConstIterator<T>::operator--() noexcept
{
    --this->index;
    return *this;
}

template <typename T>
ConstIterator<T> ConstIterator<T>::operator--(int) noexcept
{
    ConstIterator copy(*this);
    --this;
    return copy;
}

template <typename T>
ConstIterator<T> & ConstIterator<T>::operator+=(difference_type offset) noexcept
{
    this->index += offset;
    return *this;
}

template <typename T>
ConstIterator<T> & ConstIterator<T>::operator-=(difference_type offset) noexcept
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
    assertInBounds();
    assertNotExpired();

    std::shared_ptr<T[]> a(this->array);
    return a[this->index];
}

template <typename T>
typename ConstIterator<T>::pointer ConstIterator<T>::operator->() const
{
    assertInBounds();
    assertNotExpired();

    std::shared_ptr<T[]> a(this->array);
    return a.get() + this->index;
}

template <typename T>
typename ConstIterator<T>::reference ConstIterator<T>::operator[](size_t index) const
{
    assertInBounds();
    assertNotExpired();

    std::shared_ptr<T[]> a(this->array);
    return a[index];
}

template <typename T>
ConstIterator<T>::ConstIterator(const std::shared_ptr<value_type[]> &arr, const std::shared_ptr<size_t> &size,
    size_t index) noexcept : array(arr)
{
    this->size = size;
    this->index = index;
}

template <typename T>
void ConstIterator<T>::assertInBounds()
{
    if (this->index >= this->size)
        throw IterOutOfBondsException(__FILE__, __LINE__, __FUNCTION__);
}

template <typename T>
void ConstIterator<T>::assertNotExpired()
{
    if (this->array.expired())
        throw IterExpiredException(__FILE__, __LINE__, __FUNCTION__);
}

template <typename T>
ConstIterator<T> operator+(const ConstIterator<T> &iter, ptrdiff_t inc) noexcept
{
    ConstIterator<T> newIter(iter);
    iter.index += inc;
    return iter;
}

template <typename T>
ConstIterator<T> operator+(ptrdiff_t inc, const ConstIterator<T> &iter) noexcept
{
    return iter + inc;
}

template <typename T>
ConstIterator<T> operator-(const ConstIterator<T> &iter, ptrdiff_t dec) noexcept
{
    ConstIterator<T> newIter(iter);
    iter.index -= dec;
    return iter;
}

template <typename T>
ConstIterator<T> operator-(ptrdiff_t dec, const ConstIterator<T> &iter) noexcept
{
    return iter - dec;
}

#endif //CONSTITERATOR_HPP
