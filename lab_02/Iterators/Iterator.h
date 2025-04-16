#ifndef ITERATOR_H
#define ITERATOR_H

#include "BaseIterator.h"
#include "VectorConcepts.h"
#include <memory>

template <Storable T>
class Vector;

template <typename T>
class ReverseIterator;

template <typename T>
class Iterator : public BaseIterator
{
public:
    friend class ReverseIterator<T>;
    friend class Vector<T>;

#pragma region definitions
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = ptrdiff_t;
    using pointer = T *;
    using reference = T &;
#pragma endregion

#pragma region constructors and assignments
    Iterator() noexcept;
    Iterator(const Iterator &iter) noexcept;
    Iterator &operator=(const Iterator &iter) noexcept;
    ~Iterator() override = default;
#pragma endregion

#pragma region compares
    operator bool() const noexcept;
    std::strong_ordering operator<=>(const Iterator &iter) const noexcept;
    bool operator==(const Iterator &iter) const noexcept;
#pragma endregion

#pragma region math
    Iterator &operator++() noexcept;
    Iterator operator++(int) noexcept;
    Iterator &operator--() noexcept;
    Iterator operator--(int) noexcept;

    Iterator &operator+=(difference_type offset) noexcept;
    Iterator &operator-=(difference_type offset) noexcept;
    difference_type operator-(const Iterator &iter) const noexcept;

    Iterator operator+(ptrdiff_t inc) const noexcept;
    Iterator operator-(ptrdiff_t dec) const noexcept;
#pragma endregion

#pragma region data access
    const reference operator*() const;
    const pointer operator->() const;
    const reference operator[](size_t index) const;
    reference operator*();
    pointer operator->();
    reference operator[](size_t index);
#pragma endregion

private:
    Iterator(const std::shared_ptr<value_type[]> &arr, size_t size,
             size_t index = 0) noexcept;

#pragma region assertions
    void assertInBounds(size_t index, const char *file, int line, const char *func) const;
    void assertNotExpired(const char *file, int line, const char *func) const;
#pragma endregion

    std::weak_ptr<value_type[]> array;
};

#pragma region math
template <typename T>
Iterator<T> operator+(ptrdiff_t inc, const Iterator<T> &iter) noexcept;
template <typename T>
Iterator<T> operator-(ptrdiff_t dec, const Iterator<T> &iter) noexcept;
#pragma endregion

static_assert(std::random_access_iterator<Iterator<int>>);

#endif //ITERATOR_H