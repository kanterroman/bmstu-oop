#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "Iterator.h"
#include "../Exceptions/IterExceptions.h"

template <typename T>
Iterator<T>::Iterator() noexcept : array()
{
    this->size();
    this->index();
}

template <typename T>
Iterator<T>::Iterator(const Iterator &iter) noexcept
{
    this->array = iter.array;
    this->index = iter.index;
    this->size = iter.size;
}

template <typename T>
Iterator<T>::operator bool() const noexcept
{
    return this->array.expired();
}

template <typename T>
Iterator<T> & Iterator<T>::operator=(const Iterator &iter) noexcept
{
    this->array = iter.array;
    this->index = iter.index;
    this->size = iter.size;

    return *this;
}

template <typename T>
std::strong_ordering Iterator<T>::operator<=>(const Iterator &iter) const noexcept
{
    return this->index <=> iter.index;
}

template <typename T>
bool Iterator<T>::operator==(const Iterator &iter) const noexcept
{
    return this->index == iter.index;
}

template <typename T>
Iterator<T> & Iterator<T>::operator++() noexcept
{
    ++this->index;
    return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator++(int) noexcept
{
    Iterator copy(*this);
    ++*this;
    return copy;
}

template <typename T>
Iterator<T> & Iterator<T>::operator--() noexcept
{
    --this->index;
    return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator--(int) noexcept
{
    Iterator copy(*this);
    --*this;
    return copy;
}

template <typename T>
Iterator<T> & Iterator<T>::operator+=(difference_type offset) noexcept
{
    this->index += offset;
    return *this;
}

template <typename T>
Iterator<T> & Iterator<T>::operator-=(difference_type offset) noexcept
{
    this->index -= offset;
    return *this;
}

template <typename T>
typename Iterator<T>::difference_type Iterator<T>::operator-(const Iterator &iter) const noexcept
{
    return this->index - iter.index;
}

template <typename T>
Iterator<T> Iterator<T>::operator+(ptrdiff_t inc) const noexcept
{
    Iterator newIter(*this);
    newIter.index += inc;
    return newIter;
}

template <typename T>
Iterator<T> Iterator<T>::operator-(ptrdiff_t dec) const noexcept
{
    Iterator newIter(*this);
    newIter.index -= dec;
    return newIter;
}

template <typename T>
typename Iterator<T>::reference Iterator<T>::operator*() const
{
    assertInBounds(this->index, __FILE__, __LINE__, __FUNCTION__);
    assertNotExpired(__FILE__, __LINE__, __FUNCTION__);

    std::shared_ptr<T[]> a(this->array);
    return a[this->index];
}

template <typename T>
typename Iterator<T>::pointer Iterator<T>::operator->() const
{
    assertInBounds(this->index, __FILE__, __LINE__, __FUNCTION__);
    assertNotExpired(__FILE__, __LINE__, __FUNCTION__);

    std::shared_ptr<T[]> a(this->array);
    return a.get() + this->index;
}

template <typename T>
typename Iterator<T>::reference Iterator<T>::operator[](size_t index) const
{
    assertInBounds(index, __FILE__, __LINE__, __FUNCTION__);
    assertNotExpired(__FILE__, __LINE__, __FUNCTION__);

    std::shared_ptr<T[]> a(this->array);
    return a[index];
}

template <typename T>
Iterator<T>::Iterator(const std::shared_ptr<value_type[]> &arr, size_t size,
    size_t index) noexcept : array(arr)
{
    this->size = size;
    this->index = index;
}

template <typename T>
void Iterator<T>::assertInBounds(size_t index, const char *file, int line, const char *func) const
{
    if (index >= this->size)
        throw IterOutOfBondsException(file, line, func);
}

template <typename T>
void Iterator<T>::assertNotExpired(const char *file, int line, const char *func) const
{
    if (this->array.expired())
        throw IterExpiredException(file, line, func);
}

template <typename T>
Iterator<T> operator+(ptrdiff_t inc, const Iterator<T> &iter) noexcept
{
    return iter + inc;
}

template <typename T>
Iterator<T> operator-(ptrdiff_t dec, const Iterator<T> &iter) noexcept
{
    return iter - dec;
}

#endif //ITERATOR_HPP
