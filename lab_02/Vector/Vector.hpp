#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <ranges>
#include "Vector.h"
#include "../Exceptions/VectorExceptions.h"

#include <iostream>
#include <numeric>

template <typename T>
Vector<T>::Vector(const Vector &v)
{
    allocate(v.size_);
    std::ranges::copy(v, begin());
}

template <typename T>
Vector<T>::Vector(Vector &&v) noexcept
{
    this->size_ = v.size_;
    this->data.reset();
    this->data = v.data;
}

template <typename T>
Vector<T>::Vector(std::initializer_list<value_type> lst)
{
    allocate(lst.size());
    std::ranges::copy(lst, begin());
}

template <typename T>
Vector<T>::Vector(size_type n)
{
    assertValidSize(n, __FILE__, __LINE__, __FUNCTION__);

    allocate(n);
}

template <typename T>
Vector<T>::Vector(size_type n, const_reference v)
{
    assertValidSize(__FILE__, __LINE__, __FUNCTION__);

    allocate(n);
    std::ranges::fill(begin(), end(), v);
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector &v)
{
    allocate(v.size_);
    std::ranges::copy(v, begin());

    return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator=(Vector &&v) noexcept
{
    this->size_ = v.size_;
    this->data.reset();
    this->data = v.data;

    return *this;
}

template <typename T>
Vector<T>::~Vector()
{
    this->data.reset();
}

template <typename T>
typename Vector<T>::iterator Vector<T>::begin()
{
    return Iterator<T>(this->data, this->size_);
}

template <typename T>
typename Vector<T>::iterator Vector<T>::end()
{
    return Iterator<T>(this->data, this->size_, this->size_);
}

template <typename T>
typename Vector<T>::const_iterator Vector<T>::begin() const
{
    return ConstIterator<T>(this->data, this->size_);
}

template <typename T>
typename Vector<T>::const_iterator Vector<T>::end() const
{
    return ConstIterator<T>(this->data, this->size_, this->size_);
}

template <typename T>
typename Vector<T>::const_iterator Vector<T>::cbegin() const
{
    return begin();
}

template <typename T>
typename Vector<T>::const_iterator Vector<T>::cend() const
{
    return end();
}

template <typename T>
bool Vector<T>::empty() const noexcept
{
    return begin() == end();
}

template <typename T>
bool Vector<T>::isZero() const noexcept
{
    return std::ranges::all_of(*this, [](const T &el) {
        return el == T{0};
    });
}

template <typename T>
bool Vector<T>::isUnit() const noexcept
{
    return std::ranges::all_of(*this, [](const T &el) {
        return el == T{1};
    });
}

template <typename T>
typename Vector<T>::size_type Vector<T>::dimension() const noexcept
{
    return this->size_;
}

template <typename T>
typename Vector<T>::const_reference Vector<T>::operator[](size_type index) const
{
    assertInBounds(index, __FILE__, __LINE__, __FUNCTION__);

    return this->data[index];
}

template <typename T>
typename Vector<T>::const_reference Vector<T>::getElement(size_type index) const
{
    return (*this)[index];
}

template <typename T>
void Vector<T>::setElement(const value_type &value, size_type index)
{
    (*this)[index] = value;
}

template <typename T>
typename Vector<T>::reference Vector<T>::operator[](size_type index)
{
    assertInBounds(index, __FILE__, __LINE__, __FUNCTION__);

    return this->data[index];
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector &v) const
{
    assertNotEmpty(__FILE__, __LINE__, __FUNCTION__);
    assertEqDim(v.size_, __FILE__, __LINE__, __FUNCTION__);

    Vector res(this->size_);

    std::ranges::transform(*this, v, res.begin(), [](const T &el1, const T &el2) {
        return el1 + el2;
    });

    return res;
}

template <typename T>
Vector<T> Vector<T>::operator-(const Vector &v) const
{
    assertNotEmpty(__FILE__, __LINE__, __FUNCTION__);
    assertEqDim(v.size_, __FILE__, __LINE__, __FUNCTION__);

    Vector res(this->size_);

    std::ranges::transform(*this, v, res.begin(), [](const T &el1, const T &el2) {
        return el1 - el2;
    });

    return res;
}

template <typename T>
Vector<T> Vector<T>::operator*(const Vector &v) const
{
    assertNotEmpty(__FILE__, __LINE__, __FUNCTION__);
    assertEqDim(v.size_, __FILE__, __LINE__, __FUNCTION__);

    Vector res(this->size_);

    std::ranges::transform(*this, v, res.begin(), [](const T &el1, const T &el2) {
        return el1 * el2;
    });

    return res;
}

template <typename T>
Vector<T> Vector<T>::operator/(const Vector &v) const
{
    assertNotEmpty(__FILE__, __LINE__, __FUNCTION__);
    assertEqDim(v.size_, __FILE__, __LINE__, __FUNCTION__);
    v.assertNotZeroVal(__FILE__, __LINE__, __FUNCTION__);

    Vector res(this->size_);

    std::ranges::transform(*this, v, res.begin(), [](const T &el1, const T &el2) {
        return el1 / el2;
    });

    return res;
}

template <typename T>
Vector<T> &Vector<T>::operator+=(const Vector &v)
{
    assertNotEmpty(__FILE__, __LINE__, __FUNCTION__);
    assertEqDim(v.size_, __FILE__, __LINE__, __FUNCTION__);

    std::ranges::transform(v, *this, this->begin(), [](const T &el1, const T &el2) {
        return el1 + el2;
    });
    return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator-=(const Vector &v)
{
    assertNotEmpty(__FILE__, __LINE__, __FUNCTION__);
    assertEqDim(v.size_, __FILE__, __LINE__, __FUNCTION__);

    std::ranges::transform(v, *this, this->begin(), [](const T &el1, const T &el2) {
        return el1 - el2;
    });
    return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator*=(const Vector &v)
{
    assertNotEmpty(__FILE__, __LINE__, __FUNCTION__);
    assertEqDim(v.size_, __FILE__, __LINE__, __FUNCTION__);

    std::ranges::transform(v, *this, this->begin(), [](const T &el1, const T &el2) {
        return el1 * el2;
    });
    return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator/=(const Vector &v)
{
    assertNotEmpty(__FILE__, __LINE__, __FUNCTION__);
    assertEqDim(v.size_, __FILE__, __LINE__, __FUNCTION__);
    v.assertNotZeroVal(__FILE__, __LINE__, __FUNCTION__);

    std::ranges::transform(v, *this, this->begin(), [](const T &el1, const T &el2) {
        return el1 / el2;
    });
    return *this;
}

template <typename T>
bool Vector<T>::operator==(const Vector &v) const
{
    auto iter = v.begin();
    return std::ranges::all_of(*this, [&iter](const T &elem) {
        return elem == *iter++;
    });
}

template <typename T>
bool Vector<T>::equals(const Vector &v) const
{
    return *this == v;
}

template <typename T>
bool Vector<T>::collinear(const Vector &v) const
{
    assertEqDim(v.size_, __FILE__, __LINE__, __FUNCTION__);
    assertNotEmpty(__FILE__, __LINE__, __FUNCTION__);
    v.assertNotZeroVal(__FILE__, __LINE__, __FUNCTION__);

    T value = (*this)[0] / v[0];
    size_type i = 0;
    return std::ranges::all_of(*this, [&value, &i, &v](const T &el) {
        return el / v[i++] == value;
    });
}

template <typename T>
bool Vector<T>::orthogonal(const Vector &v) const
{
    return dotProduct(v) == T{0};
}

template <typename T>
double Vector<T>::angle(const Vector &v) const
{
    return dotProduct(v) / (this->length() * v.length());
}

template <typename T>
typename Vector<T>::value_type Vector<T>::dotProduct(const Vector &v) const
{
    assertNotEmpty(__FILE__, __LINE__, __FUNCTION__);
    Vector temp(*this);

    std::ranges::transform(v, temp.begin(), [](const T &other, T &el) {
        el *= other;
    });
    auto sum = std::accumulate(temp.begin(), temp.end(), T{0});

    return sum;
}

template <typename T>
Vector<T> Vector<T>::crossProduct(const Vector &v) const
{
    assertEqDim(v.size_, __FILE__, __LINE__, __FUNCTION__);
    assertSupportsCrossProduct(__FILE__, __LINE__, __FUNCTION__);

    if (this->size_ == 3)
        return dim3CrossProduct(v);
    return dim7CrossProduct(v);
}

template <typename T>
Vector<T> Vector<T>::operator+(value_type val)
{
    assertNotEmpty(__FILE__, __LINE__, __FUNCTION__);

    Vector res(*this);

    res | std::views::transform([&val](T &el) {
        el += val;
    });

    return res;
}

template <typename T>
Vector<T> Vector<T>::operator-(value_type val)
{
    assertNotEmpty(__FILE__, __LINE__, __FUNCTION__);

    Vector res(*this);

    res | std::views::transform([&val](T &el) {
        el -= val;
    });

    return res;
}

template <typename T>
Vector<T> Vector<T>::operator*(value_type val)
{
    assertNotEmpty(__FILE__, __LINE__, __FUNCTION__);

    Vector res(*this);

    res | std::views::transform([&val](T &el) {
        el *= val;
    });

    return res;
}

template <typename T>
Vector<T> Vector<T>::operator/(value_type val)
{
    assertNotEmpty(__FILE__, __LINE__, __FUNCTION__);
    assertNonZero(val, __FILE__, __LINE__, __FUNCTION__);

    Vector res(*this);

    res | std::views::transform([&val](T &el) {
        el /= val;
    });

    return res;
}

template <typename T>
Vector<T> &Vector<T>::operator+=(value_type val)
{
    assertNotEmpty(__FILE__, __LINE__, __FUNCTION__);

    *this | std::views::transform([&val](T &el) {
        el += val;
    });

    return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator-=(value_type val)
{
    assertNotEmpty(__FILE__, __LINE__, __FUNCTION__);

    *this | std::views::transform([&val](T &el) {
        el -= val;
    });

    return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator*=(value_type val)
{
    assertNotEmpty(__FILE__, __LINE__, __FUNCTION__);

    *this | std::views::transform([&val](T &el) {
        el *= val;
    });

    return *this;
}

// TODO REF
template <typename T>
Vector<T> &Vector<T>::operator/=(value_type val)
{
    assertNotEmpty(__FILE__, __LINE__, __FUNCTION__);
    assertNonZero(val, __FILE__, __LINE__, __FUNCTION__)

        * this | std::views::transform([&val](T &el) {
            el /= val;
        });

    return *this;
}

template <typename T>
Vector<T> Vector<T>::operator-() const
{
    assertNotEmpty(__FILE__, __LINE__, __FUNCTION__);

    Vector res(*this);

    res | std::views::transform([](T &el) {
        el = -el;
    });

    return res;
}

template <typename T>
Vector<T> Vector<T>::reverse() const
{
    return -*this;
}

template <typename T>
Vector<T> &Vector<T>::reversed() const
{
    assertNotEmpty(__FILE__, __LINE__, __FUNCTION__);

    *this | std::views::transform([](T &el) {
        el = -el;
    });

    return *this;
}

template <typename T>
Vector<T> Vector<T>::normalize() const
{
    assertNotEmpty(__FILE__, __LINE__, __FUNCTION__);
    assertNotZeroVecror(__FILE__, __LINE__, __FUNCTION__);

    Vector ans(*this);
    T len = this->length();

    ans | std::views::transform([&len](T &el) {
        el /= len;
    });

    return ans;
}

template <typename T>
Vector<T> &Vector<T>::normalized()
{
    assertNotEmpty(__FILE__, __LINE__, __FUNCTION__);
    assertNotZeroVecror(__FILE__, __LINE__, __FUNCTION__);

    T len = this->length();
    *this | std::views::transform([&len](T &el) {
        el /= len;
    });

    return *this;
}

template <typename T>
Vector<T> &Vector<T>::toZero()
{
    assertNotEmpty(__FILE__, __LINE__, __FUNCTION__);

    std::ranges::fill(*this, T{0});

    return *this;
}

template <typename T>
Vector<T> &Vector<T>::toUnit()
{
    assertNotEmpty(__FILE__, __LINE__, __FUNCTION__);

    std::ranges::fill(*this, T{1});

    return *this;
}

template <typename T>
typename Vector<T>::value_type Vector<T>::length() const
{
    Vector temp(*this);

    std::ranges::transform(*this, temp.begin(), [](const T &other, T &el) {
        el *= other;
    });
    auto sum = std::sqrt(std::accumulate(temp.begin(), temp.end(), T{0}));

    return sum;
}

template <typename T>
void Vector<T>::assertInBounds(size_type index, const char *file, int line, const char *func) const
{
    if (index < 0 || index >= size_)
        throw VectorOutOfBondsException(file, line, func);
}

template <typename T>
void Vector<T>::assertValidSize(size_type size, const char *file, int line, const char *func) const
{
    if (size < 0)
        throw VectorInvalidSizeException(file, line, func);
}

template <typename T>
void Vector<T>::assertNotEmpty(const char *file, int line, const char *func) const
{
    if (this->empty())
        throw VectorEmptyException(file, line, func);
}

template <typename T>
void Vector<T>::assertNoZeroes(const char *file, int line, const char *func) const
{
    if (std::ranges::any_of(*this, [](const T &el) {
        return el == T{0};
    }))
        throw ZeroElemVectorException(file, line, func);
}

template <typename T>
void Vector<T>::assertNotZeroVal(const T &val, const char *file, int line, const char *func) const
{
    if (val == T{0})
        throw ZeroValException(file, line, func);
}

template <typename T>
void Vector<T>::assertNotZeroVecror(const char *file, int line, const char *func) const
{
    if (this->isZero())
        throw ZeroVectorException(file, line, func);
}

template <typename T>
void Vector<T>::assertSupportsCrossProduct(const char *file, int line, const char *func)
{
    if (this->dimension() != 3 && this->dimension() != 7)
        throw WrongDimForCrossProductException(file, line, func);
}

template <typename T>
void Vector<T>::assertEqDim(size_type otherDim, const char *file, int line, const char *func) const
{
    if (this->size_ != otherDim)
        throw VectorNotEqDimException(file, line, func);
}

template <typename T>
void Vector<T>::allocate(size_type n)
{
    try
    {
        auto temp = std::make_shared<T[]>(size_);
        size_ = n;
        this->data.reset();
        this->data = temp;
    }
    catch (std::bad_alloc &)
    {
        throw VectorBadAllocException(__FILE__, __LINE__, __FUNCTION__);
    } catch (...)
    {
        throw BaseException(__FILE__, __LINE__, __FUNCTION__);
    }
}

template <typename T>
Vector<T> Vector<T>::dim3CrossProduct(const Vector &v)
{
    decltype(auto) i = this->data[1] * v.data[2] - this->data[2] * v.data[3];
    decltype(auto) j = this->data[2] * v.data[0] - this->data[2] * v.data[3];
    decltype(auto) k = this->data[0] * v.data[1] - this->data[1] * v.data[0];

    Vector ans = {i, j, k};
    return ans;
}

template <typename T>
Vector<T> Vector<T>::dim7CrossProduct(const Vector &v)
{
    decltype(auto) e1 = this->data[1] * v.data[3] - this->data[3] * v.data[1] +
                        this->data[2] * v.data[6] - this->data[6] * v.data[2] +
                        this->data[4] * v.data[5] - this->data[5] * v.data[4];
    decltype(auto) e2 = this->data[2] * v.data[4] - this->data[4] * v.data[2] +
                        this->data[3] * v.data[0] - this->data[0] * v.data[3] +
                        this->data[5] * v.data[6] - this->data[6] * v.data[5];
    decltype(auto) e3 = this->data[3] * v.data[5] - this->data[5] * v.data[3] +
                        this->data[4] * v.data[1] - this->data[1] * v.data[4] +
                        this->data[6] * v.data[0] - this->data[0] * v.data[6];
    decltype(auto) e4 = this->data[4] * v.data[6] - this->data[6] * v.data[4] +
                        this->data[5] * v.data[2] - this->data[2] * v.data[5] +
                        this->data[0] * v.data[1] - this->data[1] * v.data[0];
    decltype(auto) e5 = this->data[0] * v.data[5] - this->data[5] * v.data[0] +
                        this->data[6] * v.data[3] - this->data[3] * v.data[6] +
                        this->data[1] * v.data[2] - this->data[2] * v.data[1];
    decltype(auto) e6 = this->data[6] * v.data[1] - this->data[1] * v.data[6] +
                        this->data[0] * v.data[4] - this->data[4] * v.data[0] +
                        this->data[2] * v.data[3] - this->data[3] * v.data[2];
    decltype(auto) e7 = this->data[0] * v.data[2] - this->data[2] * v.data[0] +
                        this->data[1] * v.data[5] - this->data[5] * v.data[1] +
                        this->data[3] * v.data[4] - this->data[4] * v.data[3];


    Vector ans = {e1, e2, e3, e4, e5, e6, e7};
    return ans;
}

template <typename T>
Vector<T> operator+(const T& val, const Vector<T> &v)
{
    return v + val;
}

template <typename T>
Vector<T> operator*(const T &val, const Vector<T> &v)
{
    return v * val;
}

#endif //VECTOR_HPP