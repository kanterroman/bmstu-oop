#ifndef REVERSEITERATOR_HPP
#define REVERSEITERATOR_HPP

#include "ReverseIterator.h"

template <typename T>
ReverseIterator<T>::ReverseIterator() noexcept
{
    iter = Iterator<T>();
}

template <typename T>
ReverseIterator<T>::ReverseIterator(const ReverseIterator &iter) noexcept
{
    this->iter = Iterator<T>(iter.iter);
}

template <typename T>
ReverseIterator<T> & ReverseIterator<T>::operator=(const ReverseIterator &iter) noexcept
{
    this->iter = Iterator<T>(iter.iter);

    return *this;
}

template <typename T>
ReverseIterator<T>::operator bool() const noexcept
{
    return static_cast<bool>(iter);
}

template <typename T>
std::strong_ordering ReverseIterator<T>::operator<=>(const ReverseIterator &iter) const noexcept
{
    return this->iter <=> iter.iter;
}

template <typename T>
bool ReverseIterator<T>::operator==(const ReverseIterator &iter) const noexcept
{
    return this->iter == iter.iter;
}

template <typename T>
ReverseIterator<T> & ReverseIterator<T>::operator++() noexcept
{
    --this->iter;
    return *this;
}

template <typename T>
ReverseIterator<T> ReverseIterator<T>::operator++(int) noexcept
{
    ReverseIterator copy(*this);
    --this->iter;
    return copy;
}

template <typename T>
ReverseIterator<T> & ReverseIterator<T>::operator--() noexcept
{
    ++this->iter;
    return *this;
}

template <typename T>
ReverseIterator<T> ReverseIterator<T>::operator--(int) noexcept
{
    ReverseIterator copy(*this);
    ++this->iter;
    return copy;
}

template <typename T>
ReverseIterator<T> & ReverseIterator<T>::operator+=(difference_type offset) noexcept
{
    this->iter -= offset;
    return *this;
}

template <typename T>
ReverseIterator<T> & ReverseIterator<T>::operator-=(difference_type offset) noexcept
{
    this->iter += offset;
    return *this;
}

template <typename T>
typename ReverseIterator<T>::difference_type ReverseIterator<T>::operator-(const ReverseIterator &iter) const noexcept
{
    return iter.iter - this->iter;
}

template <typename T>
ReverseIterator<T> ReverseIterator<T>::operator+(ptrdiff_t inc) const noexcept
{
    ReverseIterator copy(*this);
    copy.iter - inc;
    return copy;
}

template <typename T>
ReverseIterator<T> ReverseIterator<T>::operator-(ptrdiff_t dec) const noexcept
{
    ReverseIterator copy(*this);
    copy.iter + dec;
    return copy;
}

template <typename T>
typename ReverseIterator<T>::reference ReverseIterator<T>::operator*()
{
    return *(this->iter - static_cast<ptrdiff_t>(1));
}

template <typename T>
typename ReverseIterator<T>::pointer ReverseIterator<T>::operator->()
{
    return (this->iter - static_cast<ptrdiff_t>(1)).operator->();
}

template <typename T>
typename ReverseIterator<T>::reference ReverseIterator<T>::operator[](size_t index)
{
    return this->iter[this->iter.size - index - static_cast<ptrdiff_t>(1)];
}

template <typename T>
const typename ReverseIterator<T>::reference ReverseIterator<T>::operator*() const
{
    return *(this->iter - static_cast<ptrdiff_t>(1));
}

template <typename T>
const typename ReverseIterator<T>::pointer ReverseIterator<T>::operator->() const
{
    return (this->iter - static_cast<ptrdiff_t>(1)).operator->();
}

template <typename T>
const typename ReverseIterator<T>::reference ReverseIterator<T>::operator[](size_t index) const
{
    return this->iter[this->iter.size - index - static_cast<ptrdiff_t>(1)];
}

template <typename T>
ReverseIterator<T>::ReverseIterator(const Iterator<T> &iterator)
{
    this->iter = iterator;
}

template <typename T>
ReverseIterator<T> operator+(ptrdiff_t inc, const ReverseIterator<T> &iter) noexcept
{
    return iter + inc;
}

template <typename T>
ReverseIterator<T> operator-(ptrdiff_t dec, const ReverseIterator<T> &iter) noexcept
{
    return iter - dec;
}


#endif //REVERSEITERATOR_HPP
