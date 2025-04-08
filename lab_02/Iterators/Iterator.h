#ifndef ITERATOR_H
#define ITERATOR_H

#include "BaseIterator.h"

template <typename T>
class Iterator : public BaseIterator
{
public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    Iterator() noexcept;
    Iterator(const Iterator& iter) noexcept;

    explicit operator bool() const noexcept;

    Iterator& operator =(const Iterator& iter) noexcept;

    std::strong_ordering operator<=>(const Iterator &iter) const noexcept;
    bool operator==(const Iterator &iter) const noexcept;

    Iterator& operator++() noexcept;
    Iterator operator++(int) noexcept;
    Iterator& operator--() noexcept;
    Iterator operator--(int) noexcept;

    Iterator& operator+=(difference_type offset) noexcept;
    Iterator& operator-=(difference_type offset) noexcept;
    difference_type operator-(const Iterator &iter) const noexcept;

    reference operator*() const;
    pointer operator->() const;
    reference operator[](size_t index) const;

private:
    Iterator(const std::shared_ptr<value_type[]>& arr, const std::shared_ptr<size_t> &size,
        size_t index = 0) noexcept;

    void assertInBounds();
    void assertNotExpired();

    std::weak_ptr<value_type[]> array;
};

template <typename T>
Iterator<T> operator+(const Iterator<T>& iter, ptrdiff_t inc) noexcept;
template <typename T>
Iterator<T> operator+(ptrdiff_t inc, const Iterator<T>& iter) noexcept;
template <typename T>
Iterator<T> operator-(const Iterator<T>& iter, ptrdiff_t dec) noexcept;
template <typename T>
Iterator<T> operator-(ptrdiff_t dec, const Iterator<T>& iter) noexcept;

static_assert(std::random_access_iterator<Iterator<int>>);

#endif //ITERATOR_H
