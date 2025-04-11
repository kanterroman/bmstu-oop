#ifndef VECTOR_H
#define VECTOR_H

#include "BaseVector.h"
#include "VectorConcepts.h"
#include "../Iterators/Iterator.h"
#include "../Iterators/ConstIterator.h"

template <Storable T>
class Vector : public BaseVector
{
public:
#pragma region definitions
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using iterator = Iterator<T>;
    using const_iterator = ConstIterator<T>;
    using difference_type = ptrdiff_t;
    using size_type = size_t;
#pragma endregion

#pragma region statics
    static Vector zeroVector(size_type n) requires HasZeroElement<T>;
    static Vector unitVector(size_type n) requires HasUnitElement<T>;
#pragma endregion

#pragma region constructors/destructors and assignments
    template <Convertible<T> U>
    explicit Vector(const Vector<U>& v);
    Vector(const Vector& v);
    Vector(Vector&& v) noexcept;
    Vector(std::initializer_list<T> lst);
    explicit Vector(size_type n);
    Vector(size_type n, const_reference v);

    Vector& operator=(const Vector& v);
    template <Convertible<T> U>
    Vector& operator=(const Vector<U>& v);
    Vector& operator=(Vector&& v) noexcept;

    ~Vector() override;
#pragma endregion

#pragma region iterators
    iterator begin() noexcept;
    iterator end() noexcept;
    const_iterator begin() const noexcept;
    const_iterator end() const noexcept;
    const_iterator cbegin() const noexcept;
    const_iterator cend() const noexcept;
#pragma endregion

#pragma region checks
    bool isZero() const noexcept requires HasZeroElement<T> && std::regular<T>;
    bool isUnit() const noexcept requires HasUnitElement<T> && std::regular<T>;
#pragma endregion

#pragma region getters
    [[nodiscard]] size_type dimension() const noexcept;
    const_reference operator[](size_type index) const;
    const_reference getElement(size_type index) const;
#pragma endregion

#pragma region setters
    template <Convertible<T> U>
    void setElement(const U &value, size_type index);
    reference operator[](size_type index);
#pragma endregion

#pragma region two vector
    template <Addable<T> U>
    decltype(auto) operator+(const Vector<U> &v) const;
    template <Substractable<T> U>
    decltype(auto) operator-(const Vector<U> &v) const;
    template <Multiplicable<T> U>
    decltype(auto) operator*(const Vector<U> &v) const;
    template <Divisible<T> U>
    decltype(auto) operator/(const Vector<U> &v) const;

    template <AddableAndAssignable<T> U>
    Vector& operator+=(const Vector<U> &v);
    template <SubstractableAndAssignable<T> U>
    Vector& operator-=(const Vector<U> &v);
    template <MultiplicableAndAssignable<T> U>
    Vector& operator*=(const Vector<U> &v);
    template <DivisibleAndAssignable<T> U>
    Vector& operator/=(const Vector<U> &v);

    bool operator==(const Vector & v) const requires std::regular<T>;
    bool operator==(const Vector & v) const requires std::regular<T> && std::is_floating_point_v<T>;
    bool equals(const Vector & v) const requires std::regular<T>;

    template <ComparableDivision<T> U>
    bool colinear(const Vector<U>& v) const;
    template <ComparableDivision<T> U>
    bool operator||(const Vector<U>& v) const;
    template <ComparableDivision<T> U>
    bool colinear(const Vector<U>& v) const requires std::is_floating_point_v<T> && std::is_floating_point_v<U>;
    template <DotProductComputable<T> U>
    bool orthogonal(const Vector<U>& v) const requires HasZeroElement<T>;
    template <DotProductComputable<T> U>
    bool orthogonal(const Vector<U>& v) const requires HasZeroElement<T> && std::is_floating_point_v<T> && std::is_floating_point_v<U>;

    template <AngleComputable<T> U>
    double angle(const Vector<U>& v) const;

    template <DotProductComputable<T> U>
    decltype(auto) dotProduct(const Vector<U>& v) const;
    template <DotProductComputable<T> U>
    decltype(auto) operator^(const Vector<U>& v) const;
    template <MultiplicableAndSunstractable<T> U>
    decltype(auto) crossProduct(const Vector<U>& v) const;
    template <MultiplicableAndSunstractable<T> U>
    decltype(auto) operator&(const Vector<U>& v) const;
#pragma endregion

#pragma region vector and value
    template <Addable<T> U>
    decltype(auto) operator+(const U& val) const;
    template <Addable<T> U>
    decltype(auto) addVal(const U& val) const;
    template <Multiplicable<T> U>
    decltype(auto) operator*(const U& val) const;
    template <Multiplicable<T> U>
    decltype(auto) multipVal(const U& val) const;
    template <Substractable<T> U>
    decltype(auto) operator-(const U& val) const;
    template <Substractable<T> U>
    decltype(auto) substrVal(const U& val) const;
    template <Divisible<T> U>
    decltype(auto) operator/(const U& val) const;
    template <Divisible<T> U>
    decltype(auto) divideVal(const U& val) const;

    template <AddableAndAssignable<T> U>
    Vector& operator+=(const U &val);
    template <AddableAndAssignable<T> U>
    Vector& addValToThis(const U &val);
    template <MultiplicableAndAssignable<T> U>
    Vector& operator*=(const U& val);
    template <MultiplicableAndAssignable<T> U>
    Vector& multipValToThis(const U& val);
    template <SubstractableAndAssignable<T> U>
    Vector& operator-=(const U& val);
    template <SubstractableAndAssignable<T> U>
    Vector& substrValToThis(const U& val);
    template <DivisibleAndAssignable<T> U>
    Vector& operator/=(const U& val);
    template <DivisibleAndAssignable<T> U>
    Vector& divideValToThis(const U& val);
#pragma endregion

#pragma region solo vector
    decltype(auto) operator-() const requires Inversible<T>;
    decltype(auto) reverse() const requires Inversible<T>;
    Vector& reversed() requires InversibleAndAssignable<T>;

    Vector normalize() const requires LengthComputable<T> && DivisibleAndAssignable<T, double>;
    Vector& normalized() requires LengthComputable<T> && DivisibleAndAssignable<T, double>;

    Vector &toZero() requires HasZeroElement<T>;
    Vector &toUnit() requires HasUnitElement<T>;

    double length() const requires LengthComputable<T>;
#pragma endregion

private:
#pragma region assertions
    void assertInBounds(size_type index, const char *file, int line, const char *func) const;
    void assertValidSize(size_type size, const char *file, int line, const char *func) const;
    void assertSupportsCrossProduct(const char *file, int line, const char *func) const;
    void assertEqDim(size_type otherDim, const char *file, int line, const char *func) const;
#pragma endregion
    void allocate(size_type n);
    template <MultiplicableAndSunstractable<T> U>
    decltype(auto) dim3CrossProduct(const Vector<U> &v) const;
    template <MultiplicableAndSunstractable<T> U>
    decltype(auto) dim7CrossProduct(const Vector<U> &v) const;

    std::shared_ptr<value_type[]> data;
};

template <Storable T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& v) requires Outable<T>;

#pragma region vector and value
template <Storable T, Addable<T> U>
decltype(auto) operator+(const U& val, const Vector<T> &v);
template <Storable T, Multiplicable<T> U>
decltype(auto) operator*(const U& val, const Vector<T> &v);
#pragma endregion

#endif //VECTOR_H
