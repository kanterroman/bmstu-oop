#ifndef CONSTITERATOR_H
#define CONSTITERATOR_H

#include "BaseIterator.h"
#include "VectorConcepts.h"
#include <memory>

template <Storable T>
class Vector;

template <typename T>
class ConstReverseIterator;

template <typename T>
class ConstIterator : public BaseIterator
{
public:
    friend class Vector<T>;
    friend class ConstReverseIterator<T>;

#pragma region definitions
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = ptrdiff_t;
    using pointer = const T *const;
    using reference = const T &;
#pragma endregion

#pragma region constructors and assignments
    ConstIterator() noexcept;
    ConstIterator(const ConstIterator &iter) noexcept;
    ConstIterator &operator=(const ConstIterator &iter) noexcept;
    ~ConstIterator() override = default;
#pragma endregion

#pragma region compares
    operator bool() const noexcept;
    std::strong_ordering operator<=>(const ConstIterator &iter) const noexcept;
    bool operator==(const ConstIterator &iter) const noexcept;
#pragma endregion compares

#pragma region math
    ConstIterator &operator++() noexcept;
    ConstIterator operator++(int) noexcept;
    ConstIterator &operator--() noexcept;
    ConstIterator operator--(int) noexcept;

    ConstIterator operator+(ptrdiff_t inc) const noexcept;
    ConstIterator operator-(ptrdiff_t dec) const noexcept;

    ConstIterator &operator+=(difference_type offset) noexcept;
    ConstIterator &operator-=(difference_type offset) noexcept;
    difference_type operator-(const ConstIterator &iter) const noexcept;
#pragma endregion math

#pragma region data access
    reference operator*() const;
    pointer operator->() const;
    reference operator[](size_t index) const;
#pragma endregion

private:
#pragma region constructors and assignments
    ConstIterator(const std::shared_ptr<value_type[]> &arr, size_t size,
                  size_t index = 0) noexcept;
#pragma endregion

#pragma region assertions
    void assertInBounds(size_t index, const char *file, int line, const char *func) const;
    void assertNotExpired(const char *file, int line, const char *func) const;
#pragma endregion

    std::weak_ptr<value_type[]> array;
};

#pragma region math
template <typename T>
ConstIterator<T> operator+(ptrdiff_t inc, const ConstIterator<T> &iter) noexcept;
template <typename T>
ConstIterator<T> operator-(ptrdiff_t dec, const ConstIterator<T> &iter) noexcept;
#pragma endregion

static_assert(std::random_access_iterator<ConstIterator<int>>);

#endif //CONSTITERATOR_H