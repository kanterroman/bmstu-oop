#ifndef CONSTREVERSEITERATOR_HPP
#define CONSTREVERSEITERATOR_HPP
#include "ConstReverseIterator.h"

template <typename T>
ConstReverseIterator<T>::ConstReverseIterator() noexcept
{
    iter = ConstIterator<T>();
}

template <typename T>
ConstReverseIterator<T>::ConstReverseIterator(const ConstReverseIterator &iter) noexcept
{
    this->iter = ConstIterator<T>(iter.iter);
}

template <typename T>
ConstReverseIterator<T> & ConstReverseIterator<T>::operator=(const ConstReverseIterator &iter) noexcept
{
    this->iter = ConstIterator<T>(iter.iter);

    return *this;
}

template <typename T>
ConstReverseIterator<T>::operator bool() const noexcept
{
    return static_cast<bool>(iter);
}

template <typename T>
std::strong_ordering ConstReverseIterator<T>::operator<=>(const ConstReverseIterator &iter) const noexcept
{
    return this->iter <=> iter.iter;
}

template <typename T>
bool ConstReverseIterator<T>::operator==(const ConstReverseIterator &iter) const noexcept
{
    return this->iter == iter.iter;
}

template <typename T>
ConstReverseIterator<T> & ConstReverseIterator<T>::operator++() noexcept
{
    --this->iter;
    return *this;
}

template <typename T>
ConstReverseIterator<T> ConstReverseIterator<T>::operator++(int) noexcept
{
    ConstReverseIterator copy(*this);
    --this->iter;
    return copy;
}

template <typename T>
ConstReverseIterator<T> & ConstReverseIterator<T>::operator--() noexcept
{
    ++this->iter;
    return *this;
}

template <typename T>
ConstReverseIterator<T> ConstReverseIterator<T>::operator--(int) noexcept
{
    ConstReverseIterator copy(*this);
    ++this->iter;
    return copy;
}

template <typename T>
ConstReverseIterator<T> & ConstReverseIterator<T>::operator+=(difference_type offset) noexcept
{
    this->iter -= offset;
    return *this;
}

template <typename T>
ConstReverseIterator<T> & ConstReverseIterator<T>::operator-=(difference_type offset) noexcept
{
    this->iter += offset;
    return *this;
}

template <typename T>
typename ConstReverseIterator<T>::difference_type ConstReverseIterator<T>::operator-(const ConstReverseIterator &iter) const noexcept
{
    return iter.iter - this->iter;
}

template <typename T>
ConstReverseIterator<T> ConstReverseIterator<T>::operator+(ptrdiff_t inc) const noexcept
{
    ConstReverseIterator copy(*this);
    copy.iter - inc;
    return copy;
}

template <typename T>
ConstReverseIterator<T> ConstReverseIterator<T>::operator-(ptrdiff_t dec) const noexcept
{
    ConstReverseIterator copy(*this);
    copy.iter + dec;
    return copy;
}

template <typename T>
typename ConstReverseIterator<T>::reference ConstReverseIterator<T>::operator*() const
{
    return *(this->iter - static_cast<ptrdiff_t>(1));
}

template <typename T>
typename ConstReverseIterator<T>::pointer ConstReverseIterator<T>::operator->() const
{
    return (this->iter - static_cast<ptrdiff_t>(1)).operator->();
}

template <typename T>
typename ConstReverseIterator<T>::reference ConstReverseIterator<T>::operator[](size_t index) const
{
    return this->iter[this->iter.size - index - static_cast<ptrdiff_t>(1)];
}

template <typename T>
ConstReverseIterator<T>::ConstReverseIterator(const ConstIterator<T> &iterator) noexcept
{
    this->iter = iterator;
}

template <typename T>
ConstReverseIterator<T> operator+(ptrdiff_t inc, const ConstReverseIterator<T> &iter) noexcept
{
    return iter + inc;
}

template <typename T>
ConstReverseIterator<T> operator-(ptrdiff_t dec, const ConstReverseIterator<T> &iter) noexcept
{
    return iter - dec;
}

#endif //CONSTREVERSEITERATOR_HPP
