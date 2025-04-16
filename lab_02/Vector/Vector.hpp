#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <ranges>
#include "Vector.h"
#include <cfloat>
#include "VectorExceptions.h"
#include <numeric>
#include <iostream>

template <Storable T>
Vector<T> Vector<T>::zeroVector(size_type n) requires HasZeroElement<T>
{
    assertValidSize(n, __FILE__, __LINE__, __FUNCTION__);

    Vector zero(n);
    std::ranges::fill(zero, T{0});
    return zero;
}

template <Storable T>
Vector<T> Vector<T>::unitVector(size_type n) requires HasUnitElement<T>
{
    assertValidSize(n, __FILE__, __LINE__, __FUNCTION__);

    Vector unit(n);
    std::ranges::fill(unit, T{1});
    return unit;
}

template <Storable T>
Vector<char> Vector<T>::fromString(const std::string &str)
{
    assertValidSize(str.size(), __FILE__, __LINE__, __FUNCTION__);

    Vector<char> v(str.size());
    std::ranges::copy(str, v.begin());
    return v;
}

template <Storable T>
Vector<char> Vector<T>::fromString(std::string &&str)
{
    assertValidSize(str.size(), __FILE__, __LINE__, __FUNCTION__);

    Vector<char> v(str.size());
    std::ranges::copy(str, v.begin());
    return v;
}

template <Storable T>
template <Convertible<T> U>
Vector<T>::Vector(const Vector<U> &v)
{
    allocate(v.size());
    std::ranges::copy(v, begin());
}

template <Storable T>
Vector<T>::Vector(const Vector &v)
{
    allocate(v.size());
    std::ranges::copy(v, begin());
}

template <Storable T>
Vector<T>::Vector(Vector &&v) noexcept
{
    this->size_ = v.size();
    this->data.reset();
    this->data = v.data;
}

template <Storable T>
template <Convertible<T> U>
Vector<T>::Vector(std::initializer_list<U> lst)
{
    assertValidSize(lst.size(), __FILE__, __LINE__, __FUNCTION__);

    allocate(lst.size());
    std::ranges::copy(lst, begin());
}

template <Storable T>
Vector<T>::Vector(size_type n)
{
    assertValidSize(n, __FILE__, __LINE__, __FUNCTION__);

    allocate(n);
}

template <Storable T>
Vector<T>::Vector(size_type n, const_reference v)
{
    assertValidSize(n, __FILE__, __LINE__, __FUNCTION__);

    allocate(n);
    std::ranges::fill(begin(), end(), v);
}

template <Storable T>
template <Convertible<T> U>
Vector<T>::Vector(const U *carr, size_type n)
{
    assertNonNullArray(carr, __FILE__, __LINE__, __FUNCTION__);
    assertValidSize(n, __FILE__, __LINE__, __FUNCTION__);

    allocate(n);
    std::ranges::for_each(*this, [&carr](T &el) { el = *carr++; });
}

template <Storable T>
template <std::ranges::input_range U>
Vector<T>::Vector(const U &rng)
{
    assertValidSize(std::ranges::size(rng), __FILE__, __LINE__, __FUNCTION__);

    allocate(std::ranges::size(rng));
    std::ranges::copy(rng, begin());
}

template <Storable T>
template <std::input_iterator iter, std::sentinel_for<iter> sent>
Vector<T>::Vector(const iter &first, const sent &last)
{
    assertValidSize(std::distance(first, last), __FILE__, __LINE__, __FUNCTION__);

    allocate(std::distance(first, last));
    std::ranges::copy(first, last, begin());
}

template <Storable T>
template <std::input_iterator iter>
Vector<T>::Vector(const iter &first, difference_type n)
{
    assertValidSize(n, __FILE__, __LINE__, __FUNCTION__);

    allocate(n);
    std::ranges::copy(first, first + n, begin());
}

template <Storable T>
Vector<T> &Vector<T>::operator=(const Vector &v)
{
    allocate(v.size());
    std::ranges::copy(v, begin());

    return *this;
}

template <Storable T>
template <Convertible<T> U>
Vector<T> &Vector<T>::operator=(const Vector<U> &v)
{
    allocate(v.size());
    std::ranges::copy(v, begin());

    return *this;
}

template <Storable T>
template <Convertible<T> U>
Vector<T> & Vector<T>::operator=(std::initializer_list<U> lst)
{
    assertValidSize(lst.size(), __FILE__, __LINE__, __FUNCTION__);

    allocate(lst.size());
    std::ranges::copy(lst, begin());

    return *this;
}

template <Storable T>
Vector<T> &Vector<T>::operator=(Vector &&v) noexcept
{
    this->size_ = v.size();
    this->data.reset();
    this->data = v.data;

    return *this;
}

template <Storable T>
Vector<T>::~Vector()
{
    this->data.reset();
}

template <Storable T>
typename Vector<T>::iterator Vector<T>::begin() noexcept
{
    return Iterator<T>(this->data, this->size_);
}

template <Storable T>
typename Vector<T>::reverse_iterator Vector<T>::rbegin() noexcept
{
    return ReverseIterator<T>{Iterator<T>(this->data, this->size_, this->size_)};
}

template <Storable T>
typename Vector<T>::iterator Vector<T>::end() noexcept
{
    return Iterator<T>(this->data, this->size_, this->size_);
}

template <Storable T>
typename Vector<T>::reverse_iterator Vector<T>::rend() noexcept
{
    return ReverseIterator<T>{Iterator<T>(this->data, this->size_)};
}

template <Storable T>
typename Vector<T>::const_iterator Vector<T>::begin() const noexcept
{
    return ConstIterator<T>(this->data, this->size_);
}

template <Storable T>
typename Vector<T>::const_iterator Vector<T>::end() const noexcept
{
    return ConstIterator<T>(this->data, this->size_, this->size_);
}

template <Storable T>
typename Vector<T>::const_reverse_iterator Vector<T>::rbegin() const noexcept
{
    return ConstReverseIterator<T>{ConstIterator<T>(this->data, this->size_, this->size_)};
}

template <Storable T>
typename Vector<T>::const_reverse_iterator Vector<T>::rend() const noexcept
{
    return ConstReverseIterator<T>{ConstIterator<T>(this->data, this->size_)};
}

template <Storable T>
typename Vector<T>::const_iterator Vector<T>::cbegin() const noexcept
{
    return begin();
}

template <Storable T>
typename Vector<T>::const_iterator Vector<T>::cend() const noexcept
{
    return end();
}

template <Storable T>
typename Vector<T>::const_reverse_iterator Vector<T>::crbegin() const noexcept
{
    return rbegin();
}

template <Storable T>
typename Vector<T>::const_reverse_iterator Vector<T>::crend() const noexcept
{
    return rend();
}

template <Storable T>
bool Vector<T>::isZero() const requires HasZeroElement<T> && EqComparable<T>
{
    return std::ranges::all_of(*this, [](const T &el) {
        return el == T{0};
    });
}

template <Storable T>
bool Vector<T>::isZero() const requires std::is_floating_point_v<T>
{
    return std::ranges::all_of(*this, [](const T &el) {
        return std::abs(el - T{0}) < FLT_EPSILON;
    });
}

template <Storable T>
bool Vector<T>::isUnit() const requires HasUnitElement<T> && EqComparable<T>
{
    return std::ranges::all_of(*this, [](const T &el) {
        return el == T{1};
    });
}

template <Storable T>
bool Vector<T>::isUnit() const requires std::is_floating_point_v<T>
{
    return std::ranges::all_of(*this, [](const T &el) {
        return std::abs(el - T{1}) < FLT_EPSILON;
    });
}

template <Storable T>
typename Vector<T>::size_type Vector<T>::dimension() const noexcept
{
    return this->size_;
}

template <Storable T>
typename Vector<T>::const_reference Vector<T>::operator[](size_type index) const
{
    assertInBounds(index, __FILE__, __LINE__, __FUNCTION__);

    return this->data[index];
}

template <Storable T>
typename Vector<T>::const_reference Vector<T>::getElement(size_type index) const
{
    return (*this)[index];
}

template <Storable T>
template <Convertible<T> U>
void Vector<T>::setElement(const U &value, size_type index)
{
    (*this)[index] = value;
}

template <Storable T>
typename Vector<T>::reference Vector<T>::operator[](size_type index)
{
    assertInBounds(index, __FILE__, __LINE__, __FUNCTION__);

    return this->data[index];
}

template <Storable T>
typename Vector<T>::reference Vector<T>::getElement(size_type index)
{
    return (*this)[index];
}

template <Storable T>
template <Addable<T> U>
decltype(auto) Vector<T>::operator+(const Vector<U> &v) const
{
    assertEqDim(v.size(), __FILE__, __LINE__, __FUNCTION__);

    Vector<decltype(this->data[0] + v[0])> res(this->size_);

    std::ranges::transform(this->begin(), this->end(), v.begin(), v.end(), res.begin(), [](const T &el1, const U &el2) {
        return el1 + el2;
    });

    return res;
}

template <Storable T>
template <Addable<T> U>
decltype(auto) Vector<T>::sum(const Vector<U> &v) const
{
    return *this + v;
}

template <Storable T>
template <Substractable<T> U>
decltype(auto) Vector<T>::operator-(const Vector<U> &v) const
{
    assertEqDim(v.size(), __FILE__, __LINE__, __FUNCTION__);

    Vector<decltype(this->data[0] - v[0])> res(this->size_);

    std::ranges::transform(this->begin(), this->end(), v.begin(), v.end(), res.begin(), [](const T &el1, const U &el2) {
        return el1 - el2;
    });

    return res;
}

template <Storable T>
template <Substractable<T> U>
decltype(auto) Vector<T>::substract(const Vector<U> &v) const
{
    return *this - v;
}

template <Storable T>
template <Multiplicable<T> U>
decltype(auto) Vector<T>::operator*(const Vector<U> &v) const
{
    assertEqDim(v.size(), __FILE__, __LINE__, __FUNCTION__);

    Vector<decltype(this->data[0] * v[0])> res(this->size_);

    std::ranges::transform(*this, v, res.begin(), [](const T &el1, const U &el2) {
        return el1 * el2;
    });

    return res;
}

template <Storable T>
template <Multiplicable<T> U>
decltype(auto) Vector<T>::multiply(const Vector<U> &v) const
{
    return *this * v;
}

template <Storable T>
template <Divisible<T> U>
decltype(auto) Vector<T>::operator/(const Vector<U> &v) const
{
    assertEqDim(v.size(), __FILE__, __LINE__, __FUNCTION__);

    Vector<decltype(this->data[0] / v[0])> res(this->size_);

    std::ranges::transform(*this, v, res.begin(), [](const T &el1, const U &el2) {
        return el1 / el2;
    });

    return res;
}

template <Storable T>
template <Divisible<T> U>
decltype(auto) Vector<T>::divide(const Vector<U> &v) const
{
    return *this / v;
}

template <Storable T>
template <AddableAndAssignable<T> U>
Vector<T> &Vector<T>::operator+=(const Vector<U> &v)
{
    assertEqDim(v.size(), __FILE__, __LINE__, __FUNCTION__);

    std::ranges::transform(v, *this, this->begin(), [](const U &el1, const T &el2) {
        return el1 + el2;
    });
    return *this;
}

template <Storable T>
template <AddableAndAssignable<T> U>
Vector<T> &Vector<T>::sumToThis(const Vector<U> &v)
{
    return *this += v;
}

template <Storable T>
template <SubstractableAndAssignable<T> U>
Vector<T> &Vector<T>::operator-=(const Vector<U> &v)
{
    assertEqDim(v.size(), __FILE__, __LINE__, __FUNCTION__);

    std::ranges::transform(v, *this, this->begin(), [](const U &el1, const T &el2) {
        return el2 - el1;
    });
    return *this;
}

template <Storable T>
template <SubstractableAndAssignable<T> U>
Vector<T> &Vector<T>::substrFromThis(const Vector<U> &v)
{
    return *this -= v;
}

template <Storable T>
template <MultiplicableAndAssignable<T> U>
Vector<T> &Vector<T>::operator*=(const Vector<U> &v)
{
    assertEqDim(v.size(), __FILE__, __LINE__, __FUNCTION__);

    std::ranges::transform(v, *this, this->begin(), [](const U &el1, const T &el2) {
        return el2 * el1;
    });
    return *this;
}

template <Storable T>
template <MultiplicableAndAssignable<T> U>
Vector<T> &Vector<T>::multipToThis(const Vector<U> &v)
{
    return *this *= v;
}

template <Storable T>
template <DivisibleAndAssignable<T> U>
Vector<T> &Vector<T>::operator/=(const Vector<U> &v)
{
    assertEqDim(v.size(), __FILE__, __LINE__, __FUNCTION__);

    std::ranges::transform(v, *this, this->begin(), [](const U &el1, const T &el2) {
        return el2 / el1;
    });
    return *this;
}

template <Storable T>
template <DivisibleAndAssignable<T> U>
Vector<T> &Vector<T>::divideToThis(const Vector<U> &v)
{
    return *this /= v;
}

template <Storable T>
bool Vector<T>::operator==(const Vector &v) const requires std::regular<T>
{
    assertEqDim(v.size(), __FILE__, __LINE__, __FUNCTION__);

    auto iter = v.begin();
    return std::ranges::all_of(*this, [&iter](const T &elem) {
        return elem == *iter++;
    });
}

template <Storable T>
bool Vector<T>::operator==(const Vector &v) const requires std::regular<T> && std::is_floating_point_v<T>
{
    assertEqDim(v.size(), __FILE__, __LINE__, __FUNCTION__);

    auto iter = v.begin();
    return std::ranges::all_of(*this, [&iter](const T &elem) {
        return std::abs(elem - *iter++) < FLT_EPSILON;
    });
}

template <Storable T>
bool Vector<T>::equals(const Vector &v) const requires std::regular<T>
{
    return *this == v;
}

template <Storable T>
template <ComparableDivision<T> U>
bool Vector<T>::colinear(const Vector<U> &v) const
{
    assertEqDim(v.size(), __FILE__, __LINE__, __FUNCTION__);

    decltype(auto) value = (*this)[0] / v[0];
    size_type i = 0;
    return std::ranges::all_of(*this, [&value, &i, &v](const T &el) {
        return el / v[i++] == value;
    });
}

template <Storable T>
template <ComparableDivision<T> U>
bool Vector<T>::operator||(const Vector<U> &v) const
{
    return colinear(v);
}

template <Storable T>
template <ComparableDivision<T> U>
bool Vector<T>::colinear(const Vector<U> &v) const requires std::is_floating_point_v<T> && std::is_floating_point_v<U>
{
    assertEqDim(v.size(), __FILE__, __LINE__, __FUNCTION__);

    decltype(auto) value = (*this)[0] / v[0];
    size_type i = 0;
    return std::ranges::all_of(*this, [&value, &i, &v](const T &el) {
        return std::abs(el / v[i++] - value) < FLT_EPSILON;
    });
}

template <Storable T>
template <DotProductComputable<T> U>
bool Vector<T>::orthogonal(const Vector<U> &v) const requires HasZeroElement<T>
{
    return dotProduct(v) == T{0};
}

template <Storable T>
template <DotProductComputable<T> U>
bool Vector<T>::orthogonal(const Vector<U> &v) const requires HasZeroElement<T> && std::is_floating_point_v<T> && std::
                                                              is_floating_point_v<U>
{
    return std::abs(dotProduct(v) - T{0}) < FLT_EPSILON;
}

template <Storable T>
template <AngleComputable<T> U>
double Vector<T>::angle(const Vector<U> &v) const
{
    return std::acos(dotProduct(v) / (this->length() * v.length()));
}

template <Storable T>
template <DotProductComputable<T> U>
decltype(auto) Vector<T>::dotProduct(const Vector<U> &v) const
{
    assertEqDim(v.size(), __FILE__, __LINE__, __FUNCTION__);

    decltype(this->data[0] * v[0]) sum{0};

    auto iter = v.begin();
    std::ranges::for_each(*this, [&sum, &iter](const T &el1) {
        sum += el1 * *iter;
        ++iter;
    });

    return sum;
}

template <Storable T>
template <DotProductComputable<T> U>
decltype(auto) Vector<T>::operator^(const Vector<U> &v) const
{
    return dotProduct(v);
}

template <Storable T>
template <CrossProductComputable<T> U>
decltype(auto) Vector<T>::crossProduct(const Vector<U> &v) const
{
    assertEqDim(v.size(), __FILE__, __LINE__, __FUNCTION__);
    assertSupportsCrossProduct(__FILE__, __LINE__, __FUNCTION__);

    if (this->size_ == 3)
        return dim3CrossProduct(v);
    return dim7CrossProduct(v);
}

template <Storable T>
template <CrossProductComputable<T> U>
decltype(auto) Vector<T>::operator&(const Vector<U> &v) const
{
    return crossProduct(v);
}

template <Storable T>
template <Addable<T> U>
decltype(auto) Vector<T>::operator+(const U &val) const
{
    Vector<decltype(this->data[0] + val)> res(this->size_);

    std::ranges::transform(*this, res.begin(), [&val](const T &el) {
        return el + val;
    });

    return res;
}

template <Storable T>
template <Addable<T> U>
decltype(auto) Vector<T>::sumVal(const U &val) const
{
    return *this + val;
}

template <Storable T>
template <Substractable<T> U>
decltype(auto) Vector<T>::operator-(const U &val) const
{
    Vector<decltype(this->data[0] + val)> res(this->size_);

    std::ranges::transform(*this, res.begin(), [&val](const T &el) {
        return el - val;
    });

    return res;
}

template <Storable T>
template <Substractable<T> U>
decltype(auto) Vector<T>::substrVal(const U &val) const
{
    return *this - val;
}

template <Storable T>
template <Multiplicable<T> U>
decltype(auto) Vector<T>::operator*(const U &val) const
{
    Vector<decltype(this->data[0] + val)> res(this->size_);

    std::ranges::transform(*this, res.begin(), [&val](const T &el) {
        return el * val;
    });

    return res;
}

template <Storable T>
template <Multiplicable<T> U>
decltype(auto) Vector<T>::multipVal(const U &val) const
{
    return *this * val;
}

template <Storable T>
template <Divisible<T> U>
decltype(auto) Vector<T>::operator/(const U &val) const
{
    Vector<decltype(this->data[0] + val)> res(this->size_);

    std::ranges::transform(*this, res.begin(), [&val](const T &el) {
        return el / val;
    });

    return res;
}

template <Storable T>
template <Divisible<T> U>
decltype(auto) Vector<T>::divideVal(const U &val) const
{
    return *this / val;
}

template <Storable T>
template <AddableAndAssignable<T> U>
Vector<T> &Vector<T>::operator+=(const U &val)
{
    std::ranges::transform(*this, begin(), [&val](T &el) {
        return el + val;
    });

    return *this;
}

template <Storable T>
template <AddableAndAssignable<T> U>
Vector<T> &Vector<T>::sumValAndThis(const U &val)
{
    return *this += val;
}

template <Storable T>
template <SubstractableAndAssignable<T> U>
Vector<T> &Vector<T>::operator-=(const U &val)
{
    std::ranges::transform(*this, begin(), [&val](T &el) {
        return el - val;
    });

    return *this;
}

template <Storable T>
template <SubstractableAndAssignable<T> U>
Vector<T> &Vector<T>::substrValToThis(const U &val)
{
    return *this -= val;
}

template <Storable T>
template <MultiplicableAndAssignable<T> U>
Vector<T> &Vector<T>::operator*=(const U &val)
{
    std::ranges::transform(*this, begin(), [&val](T &el) {
        return el * val;
    });

    return *this;
}

template <Storable T>
template <MultiplicableAndAssignable<T> U>
Vector<T> &Vector<T>::multipValToThis(const U &val)
{
    return *this *= val;
}

template <Storable T>
template <DivisibleAndAssignable<T> U>
Vector<T> &Vector<T>::operator/=(const U &val)
{
    std::ranges::transform(*this, begin(), [&val](T &el) {
        return el / val;
    });

    return *this;
}

template <Storable T>
template <DivisibleAndAssignable<T> U>
Vector<T> &Vector<T>::divideValToThis(const U &val)
{
    return *this /= val;
}

template <Storable T>
decltype(auto) Vector<T>::operator-() const requires Inversible<T>
{
    Vector<decltype(-(*this)[0])> res(this->size());

    std::ranges::transform(*this, res.begin(), [](const T &el) {
        return -el;
    });

    return res;
}

template <Storable T>
decltype(auto) Vector<T>::reverse() const requires Inversible<T>
{
    return -*this;
}

template <Storable T>
Vector<T> &Vector<T>::reversed() requires InversibleAndAssignable<T>
{
    std::ranges::transform(*this, begin(), [](const T &el) {
        return -el;
    });

    return *this;
}

template <Storable T>
Vector<T> Vector<T>::normalize() const requires LengthComputable<T> && DivisibleAndAssignable<T, double>
{
    Vector ans(this->size_);
    double len = this->length();

    std::ranges::transform(*this, ans.begin(), [&len](const T &el) {
        return el / len;
    });

    return ans;
}

template <Storable T>
Vector<T> &Vector<T>::normalized() requires LengthComputable<T> && DivisibleAndAssignable<T, double>
{
    double len = this->length();
    std::ranges::transform(*this, this->begin(), [&len](T &el) {
        return el / len;
    });

    return *this;
}

template <Storable T>
Vector<T> &Vector<T>::toZero() requires HasZeroElement<T>
{
    std::ranges::fill(*this, T{0});

    return *this;
}

template <Storable T>
Vector<T> &Vector<T>::toUnit() requires HasUnitElement<T>
{
    std::ranges::fill(*this, T{1});

    return *this;
}

template <Storable T>
double Vector<T>::length() const requires LengthComputable<T>
{
    T elemSum = T{0};

    std::ranges::for_each(*this, [&elemSum](const T &el) {
        elemSum += el * el;
    });
    double sum = std::sqrt(static_cast<double>(elemSum));

    return sum;
}

template <Storable T>
void Vector<T>::assertInBounds(size_type index, const char *file, int line, const char *func) const
{
    if (index >= size_)
        throw VectorOutOfBondsException(file, line, func);
}

template <Storable T>
void Vector<T>::assertValidSize(size_type size, const char *file, int line, const char *func)
{
    if (size == 0)
        throw VectorInvalidSizeException(file, line, func);
}

template <Storable T>
void Vector<T>::assertSupportsCrossProduct(const char *file, int line, const char *func) const
{
    if (this->dimension() != 3 && this->dimension() != 7)
        throw WrongDimForCrossProductException(file, line, func);
}

template <Storable T>
void Vector<T>::assertEqDim(size_type otherDim, const char *file, int line, const char *func) const
{
    if (this->size_ != otherDim)
        throw VectorNotEqDimException(file, line, func);
}

template <Storable T>
template <typename U>
void Vector<T>::assertNonNullArray(const U *array, const char *file, int line, const char *func)
{
    if (!array)
        throw NullArrayException(file, line, func);
}

template <Storable T>
void Vector<T>::allocate(size_type n)
{
    try
    {
        auto temp = std::make_shared<T[]>(n);
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

template <Storable T>
template <CrossProductComputable<T> U>
decltype(auto) Vector<T>::dim3CrossProduct(const Vector<U> &v) const
{
    decltype(auto) i = this->data[1] * v[2] - this->data[2] * v[1];
    decltype(auto) j = this->data[2] * v[0] - this->data[0] * v[2];
    decltype(auto) k = this->data[0] * v[1] - this->data[1] * v[0];

    Vector ans({i, j, k});
    return ans;
}

template <Storable T>
template <CrossProductComputable<T> U>
decltype(auto) Vector<T>::dim7CrossProduct(const Vector<U> &v) const
{
    decltype(auto) e1 = this->data[1] * v[3] - this->data[3] * v[1] +
                        this->data[2] * v[6] - this->data[6] * v[2] +
                        this->data[4] * v[5] - this->data[5] * v[4];
    decltype(auto) e2 = this->data[2] * v[4] - this->data[4] * v[2] +
                        this->data[3] * v[0] - this->data[0] * v[3] +
                        this->data[5] * v[6] - this->data[6] * v[5];
    decltype(auto) e3 = this->data[3] * v[5] - this->data[5] * v[3] +
                        this->data[4] * v[1] - this->data[1] * v[4] +
                        this->data[6] * v[0] - this->data[0] * v[6];
    decltype(auto) e4 = this->data[4] * v[6] - this->data[6] * v[4] +
                        this->data[5] * v[2] - this->data[2] * v[5] +
                        this->data[0] * v[1] - this->data[1] * v[0];
    decltype(auto) e5 = this->data[5] * v[0] - this->data[0] * v[5] +
                        this->data[6] * v[3] - this->data[3] * v[6] +
                        this->data[1] * v[2] - this->data[2] * v[1];
    decltype(auto) e6 = this->data[6] * v[1] - this->data[1] * v[6] +
                        this->data[0] * v[4] - this->data[4] * v[0] +
                        this->data[2] * v[3] - this->data[3] * v[2];
    decltype(auto) e7 = this->data[0] * v[2] - this->data[2] * v[0] +
                        this->data[1] * v[5] - this->data[5] * v[1] +
                        this->data[3] * v[4] - this->data[4] * v[3];

    Vector ans({e1, e2, e3, e4, e5, e6, e7});
    return ans;
}

template <Storable T>
std::ostream &operator<<(std::ostream &os, const Vector<T> &v) requires Outable<T>
{
    std::ranges::for_each(v, [&os](const T &el) {
        os << el << " ";
    });

    return os;
}

template <Storable T, Addable<T> U>
decltype(auto) operator+(const U &val, const Vector<T> &v)
{
    return v + val;
}

template <Storable T, Multiplicable<T> U>
decltype(auto) operator*(const U &val, const Vector<T> &v)
{
    return v * val;
}

#endif //VECTOR_HPP