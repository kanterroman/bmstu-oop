#ifndef CONSTREVERSEITERATOR_H
#define CONSTREVERSEITERATOR_H

#include "ConstIterator.h"

template <typename T>
class ConstReverseIterator
{
public:
    friend class Vector<T>;

#pragma region definitions
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = ptrdiff_t;
    using pointer = const T *const;
    using reference = const T &;
#pragma endregion

#pragma region constructors and assignments
    ConstReverseIterator() noexcept;
    ConstReverseIterator(const ConstReverseIterator &iter) noexcept;
    ConstReverseIterator &operator=(const ConstReverseIterator &iter) noexcept;
    ~ConstReverseIterator() = default;
#pragma endregion

#pragma region compares
    operator bool() const noexcept;
    std::strong_ordering operator<=>(const ConstReverseIterator &iter) const noexcept;
    bool operator==(const ConstReverseIterator &iter) const noexcept;
#pragma endregion

#pragma region math
    ConstReverseIterator &operator++() noexcept;
    ConstReverseIterator operator++(int) noexcept;
    ConstReverseIterator &operator--() noexcept;
    ConstReverseIterator operator--(int) noexcept;

    ConstReverseIterator &operator+=(difference_type offset) noexcept;
    ConstReverseIterator &operator-=(difference_type offset) noexcept;
    difference_type operator-(const ConstReverseIterator &iter) const noexcept;

    ConstReverseIterator operator+(ptrdiff_t inc) const noexcept;
    ConstReverseIterator operator-(ptrdiff_t dec) const noexcept;
#pragma endregion

#pragma region data access
    reference operator*() const;
    pointer operator->() const;
    reference operator[](size_t index) const;
#pragma endregion

private:
    ConstReverseIterator(ConstIterator<T> &&iterator) noexcept;
    ConstIterator<T> iter;
};

#pragma region math
template <typename T>
ConstReverseIterator<T> operator+(ptrdiff_t inc, const ConstReverseIterator<T> &iter) noexcept;
template <typename T>
ConstReverseIterator<T> operator-(ptrdiff_t dec, const ConstReverseIterator<T> &iter) noexcept;
#pragma endregion

static_assert(std::random_access_iterator<ConstReverseIterator<int>>);


#endif //CONSTREVERSEITERATOR_H
