#ifndef REVERSEITERATOR_H
#define REVERSEITERATOR_H

#include "BaseIterator.h"
#include "Iterator.h"

template <typename T>
class ReverseIterator
{
public:
    friend class Vector<T>;

#pragma region definitions
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = ptrdiff_t;
    using pointer = T *;
    using reference = T &;
#pragma endregion

#pragma region constructors and assignments
    ReverseIterator() noexcept;
    ReverseIterator(const ReverseIterator &iter) noexcept;
    ReverseIterator &operator=(const ReverseIterator &iter) noexcept;
    ~ReverseIterator() = default;
#pragma endregion

#pragma region compares
    operator bool() const noexcept;
    std::strong_ordering operator<=>(const ReverseIterator &iter) const noexcept;
    bool operator==(const ReverseIterator &iter) const noexcept;
#pragma endregion

#pragma region math
    ReverseIterator &operator++() noexcept;
    ReverseIterator operator++(int) noexcept;
    ReverseIterator &operator--() noexcept;
    ReverseIterator operator--(int) noexcept;

    ReverseIterator &operator+=(difference_type offset) noexcept;
    ReverseIterator &operator-=(difference_type offset) noexcept;
    difference_type operator-(const ReverseIterator &iter) const noexcept;

    ReverseIterator operator+(ptrdiff_t inc) const noexcept;
    ReverseIterator operator-(ptrdiff_t dec) const noexcept;
#pragma endregion

#pragma region data access
    reference operator*();
    pointer operator->();
    reference operator[](size_t index);
    const reference operator*() const;
    const pointer operator->() const;
    const reference operator[](size_t index) const;
#pragma endregion

private:
    ReverseIterator(Iterator<T> &&iterator);
    Iterator<T> iter;
};

#pragma region math
template <typename T>
ReverseIterator<T> operator+(ptrdiff_t inc, const ReverseIterator<T> &iter) noexcept;
template <typename T>
ReverseIterator<T> operator-(ptrdiff_t dec, const ReverseIterator<T> &iter) noexcept;
#pragma endregion

static_assert(std::random_access_iterator<ReverseIterator<int>>);

#endif //REVERSEITERATOR_H
