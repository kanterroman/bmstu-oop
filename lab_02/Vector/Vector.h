#ifndef VECTOR_H
#define VECTOR_H

#include "BaseVector.h"
#include "VectorConcepts.h"
#include "Iterator.h"
#include "ConstIterator.h"
#include <ranges>

template <Storable T>
class Vector : public BaseVector
{
public:
#pragma region definitions
    using value_type = T;
    using reference = T &;
    using const_reference = const T &;
    using iterator = Iterator<T>;
    using const_iterator = ConstIterator<T>;
    using reverse_iterator = ReverseIterator<T>;
    using const_reverse_iterator = ConstReverseIterator<T>;
    using difference_type = ptrdiff_t;
    using size_type = size_t;
#pragma endregion

#pragma region statics
    static Vector zeroVector(size_type n) requires HasZeroElement<T>;
    static Vector unitVector(size_type n) requires HasUnitElement<T>;
    static Vector<char> fromString(const std::string &str);
    static Vector<char> fromString(std::string &&str);
#pragma endregion

#pragma region constructors/destructors and assignments
    template <Convertible<T> U>
    explicit Vector(const Vector<U> &v);
    explicit Vector(const Vector &v);
    template <Convertible<T> U>
    explicit Vector(std::initializer_list<U> lst);
    explicit Vector(size_type n);
    Vector(Vector &&v) noexcept;
    Vector(size_type n, const_reference v);
    template <Convertible<T> U>
    Vector(const U *carr, size_type n);

    template <std::ranges::input_range range>
    explicit Vector(const range &rng);
    template <std::input_iterator iter, std::sentinel_for<iter> sent>
    Vector(const iter& first, const sent& last);
    template <std::input_iterator iter>
    Vector(const iter& first, difference_type n);


    Vector &operator=(const Vector &v);
    template <Convertible<T> U>
    Vector &operator=(const Vector<U> &v);
    template <Convertible<T> U>
    Vector &operator=(std::initializer_list<U> lst);
    Vector &operator=(Vector &&v) noexcept;


    ~Vector() override;
#pragma endregion

#pragma region iterators
    iterator begin() noexcept;
    iterator end() noexcept;
    reverse_iterator rbegin() noexcept;
    reverse_iterator rend() noexcept;

    const_iterator begin() const noexcept;
    const_iterator end() const noexcept;
    const_reverse_iterator rbegin() const noexcept;
    const_reverse_iterator rend() const noexcept;

    const_iterator cbegin() const noexcept;
    const_iterator cend() const noexcept;
    const_reverse_iterator crbegin() const noexcept;
    const_reverse_iterator crend() const noexcept;
#pragma endregion

#pragma region checks
    bool isZero() const requires HasZeroElement<T> && EqComparable<T>;
    bool isZero() const requires std::is_floating_point_v<T>;
    bool isUnit() const requires HasUnitElement<T> && EqComparable<T>;
    bool isUnit() const requires std::is_floating_point_v<T>;;
#pragma endregion

#pragma region getters
    size_type dimension() const noexcept;
    const_reference operator[](size_type index) const;
    const_reference getElement(size_type index) const;
#pragma endregion

#pragma region setters
    template <Convertible<T> U>
    void setElement(const U &value, size_type index);
    reference operator[](size_type index);
    reference getElement(size_type index);
#pragma endregion

#pragma region two vector
    template <Addable<T> U>
    decltype(auto) operator+(const Vector<U> &v) const;

    template <Addable<T> U>
    decltype(auto) sum(const Vector<U> &v) const;

    template <Substractable<T> U>
    decltype(auto) operator-(const Vector<U> &v) const;

    template <Substractable<T> U>
    decltype(auto) substract(const Vector<U> &v) const;

    template <Multiplicable<T> U>
    decltype(auto) operator*(const Vector<U> &v) const;

    template <Multiplicable<T> U>
    decltype(auto) multiply(const Vector<U> &v) const;

    template <Divisible<T> U>
    decltype(auto) operator/(const Vector<U> &v) const;

    template <Divisible<T> U>
    decltype(auto) divide(const Vector<U> &v) const;


    template <AddableAndAssignable<T> U>
    Vector &operator+=(const Vector<U> &v);

    template <AddableAndAssignable<T> U>
    Vector &sumToThis(const Vector<U> &v);

    template <SubstractableAndAssignable<T> U>
    Vector &operator-=(const Vector<U> &v);

    template <SubstractableAndAssignable<T> U>
    Vector &substrFromThis(const Vector<U> &v);

    template <MultiplicableAndAssignable<T> U>
    Vector &operator*=(const Vector<U> &v);

    template <MultiplicableAndAssignable<T> U>
    Vector &multipToThis(const Vector<U> &v);

    template <DivisibleAndAssignable<T> U>
    Vector &operator/=(const Vector<U> &v);

    template <DivisibleAndAssignable<T> U>
    Vector &divideToThis(const Vector<U> &v);

    bool operator==(const Vector &v) const requires std::regular<T>;
    bool operator==(const Vector &v) const requires std::regular<T> && std::is_floating_point_v<T>;
    bool equals(const Vector &v) const requires std::regular<T>;

    template <ComparableDivision<T> U>
    bool colinear(const Vector<U> &v) const;
    template <ComparableDivision<T> U>
    bool operator||(const Vector<U> &v) const;
    template <ComparableDivision<T> U>
    bool colinear(const Vector<U> &v) const requires std::is_floating_point_v<T> && std::is_floating_point_v<U>;
    template <DotProductComputable<T> U>
    bool orthogonal(const Vector<U> &v) const requires HasZeroElement<T>;
    template <DotProductComputable<T> U>
    bool orthogonal(const Vector<U> &v) const requires
        HasZeroElement<T> && std::is_floating_point_v<T> && std::is_floating_point_v<U>;

    template <AngleComputable<T> U>
    double angle(const Vector<U> &v) const;

    template <DotProductComputable<T> U>
    decltype(auto) dotProduct(const Vector<U> &v) const;
    template <DotProductComputable<T> U>
    decltype(auto) operator^(const Vector<U> &v) const;
    template <CrossProductComputable<T> U>
    decltype(auto) crossProduct(const Vector<U> &v) const;
    template <CrossProductComputable<T> U>
    decltype(auto) operator&(const Vector<U> &v) const;
#pragma endregion

#pragma region vector and value
    template <Addable<T> U>
    decltype(auto) operator+(const U &val) const;

    template <Addable<T> U>
    decltype(auto) sumVal(const U &val) const;

    template <Multiplicable<T> U>
    decltype(auto) operator*(const U &val) const;

    template <Multiplicable<T> U>
    decltype(auto) multipVal(const U &val) const;

    template <Substractable<T> U>
    decltype(auto) operator-(const U &val) const;

    template <Substractable<T> U>
    decltype(auto) substrVal(const U &val) const;

    template <Divisible<T> U>
    decltype(auto) operator/(const U &val) const;

    template <Divisible<T> U>
    decltype(auto) divideVal(const U &val) const;


    template <AddableAndAssignable<T> U>
    Vector &operator+=(const U &val);
    template <AddableAndAssignable<T> U>
    Vector &sumValAndThis(const U &val);

    template <MultiplicableAndAssignable<T> U>
    Vector &operator*=(const U &val);
    template <MultiplicableAndAssignable<T> U>
    Vector &multipValToThis(const U &val);

    template <SubstractableAndAssignable<T> U>
    Vector &operator-=(const U &val);
    template <SubstractableAndAssignable<T> U>
    Vector &substrValToThis(const U &val);

    template <DivisibleAndAssignable<T> U>
    Vector &operator/=(const U &val);
    template <DivisibleAndAssignable<T> U>
    Vector &divideValToThis(const U &val);
#pragma endregion

#pragma region solo vector
    decltype(auto) operator-() const requires Inversible<T>;
    decltype(auto) reverse() const requires Inversible<T>;
    Vector &reversed() requires InversibleAndAssignable<T>;

    Vector normalize() const requires LengthComputable<T> && DivisibleAndAssignable<T, double>;
    Vector &normalized() requires LengthComputable<T> && DivisibleAndAssignable<T, double>;

    Vector &toZero() requires HasZeroElement<T>;
    Vector &toUnit() requires HasUnitElement<T>;

    double length() const requires LengthComputable<T>;
#pragma endregion

private:
#pragma region assertions
    void assertInBounds(size_type index, const char *file, int line, const char *func) const;
    static void assertValidSize(size_type size, const char *file, int line, const char *func);
    void assertSupportsCrossProduct(const char *file, int line, const char *func) const;
    void assertEqDim(size_type otherDim, const char *file, int line, const char *func) const;
    template <typename U>
    static void assertNonNullArray(const U* array, const char *file, int line, const char *func);
#pragma endregion

#pragma region helpers
    void allocate(size_type n);
    template <CrossProductComputable<T> U>
    decltype(auto) dim3CrossProduct(const Vector<U> &v) const;
    template <CrossProductComputable<T> U>
    decltype(auto) dim7CrossProduct(const Vector<U> &v) const;
#pragma endregion

    std::shared_ptr<value_type[]> data;
};

template <Storable T>
std::ostream &operator<<(std::ostream &os, const Vector<T> &v) requires Outable<T>;

#pragma region vector and value
template <Storable T, Addable<T> U>
decltype(auto) operator+(const U &val, const Vector<T> &v);
template <Storable T, Multiplicable<T> U>
decltype(auto) operator*(const U &val, const Vector<T> &v);
#pragma endregion

#endif //VECTOR_H