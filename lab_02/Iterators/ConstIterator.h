#ifndef CONSTITERATOR_H
#define CONSTITERATOR_H

#include "BaseIterator.h"

template <typename T>
class ConstIterator : public BaseIterator
{
public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = ptrdiff_t;
    using pointer = const T*;
    using reference = const T&;

    ConstIterator() noexcept;
    ConstIterator(const ConstIterator& iter) noexcept;

    explicit operator bool() const noexcept;

    ConstIterator& operator =(const ConstIterator& iter) noexcept;

    std::strong_ordering operator<=>(const ConstIterator &iter) const noexcept;
    bool operator==(const ConstIterator &iter) const noexcept;

    ConstIterator& operator++() noexcept;
    ConstIterator operator++(int) noexcept;
    ConstIterator& operator--() noexcept;
    ConstIterator operator--(int) noexcept;

    ConstIterator& operator+=(difference_type offset) noexcept;
    ConstIterator& operator-=(difference_type offset) noexcept;
    difference_type operator-(const ConstIterator &iter) const noexcept;

    reference operator*() const;
    pointer operator->() const;
    reference operator[](size_t index) const;

private:
    ConstIterator(const std::shared_ptr<value_type[]>& arr, const std::shared_ptr<size_t> &size,
        size_t index = 0) noexcept;

    void assertInBounds();
    void assertNotExpired();

    std::weak_ptr<value_type[]> array;
};

template <typename T>
ConstIterator<T> operator+(const ConstIterator<T>& iter, ptrdiff_t inc) noexcept;
template <typename T>
ConstIterator<T> operator+(ptrdiff_t inc, const ConstIterator<T>& iter) noexcept;
template <typename T>
ConstIterator<T> operator-(const ConstIterator<T>& iter, ptrdiff_t dec) noexcept;
template <typename T>
ConstIterator<T> operator-(ptrdiff_t dec, const ConstIterator<T>& iter) noexcept;

static_assert(std::random_access_iterator<ConstIterator<int>>);

#endif //CONSTITERATOR_H
