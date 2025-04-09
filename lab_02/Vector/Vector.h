#ifndef VECTOR_H
#define VECTOR_H

#include "BaseVector.h"
#include "../Iterators/Iterator.h"
#include "../Iterators/ConstIterator.h"

template <typename T>
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

#pragma region constructors/destructors and assignments
    Vector() = default;
    Vector(const Vector& v);
    Vector(Vector&& v) noexcept;
    Vector(std::initializer_list<value_type> lst);
    explicit Vector(size_type n);
    Vector(size_type n, const_reference v);

    Vector& operator=(const Vector& v);
    Vector& operator=(Vector&& v) noexcept ;

    ~Vector() override;
#pragma endregion

#pragma region iterators
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    const_iterator cbegin() const;
    const_iterator cend() const;
#pragma endregion

#pragma region checks
    [[nodiscard]] bool empty() const noexcept;
    [[nodiscard]] bool isZero() const noexcept;
    [[nodiscard]] bool isUnit() const noexcept;
#pragma endregion

#pragma region getters
    [[nodiscard]] size_type dimension() const noexcept;
    const_reference operator[](size_type index) const;
    const_reference getElement(size_type index) const;
#pragma endregion

#pragma region setters
    void setElement(const value_type &value, size_type index);
    reference operator[](size_type index);
#pragma endregion

#pragma region two vector
    Vector operator+(const Vector &v) const;
    Vector operator-(const Vector &v) const;
    Vector operator*(const Vector &v) const;
    Vector operator/(const Vector &v) const;

    Vector& operator+=(const Vector &v);
    Vector& operator-=(const Vector &v);
    Vector& operator*=(const Vector &v);
    Vector& operator/=(const Vector &v);

    bool operator==(const Vector & v) const;
    bool equals(const Vector & v) const;

    bool collinear(const Vector& v) const;
    bool orthogonal(const Vector& v) const;

    //TODO hmmm
    double angle(const Vector& v) const;

    value_type dotProduct(const Vector& v) const;
    Vector crossProduct(const Vector& v) const;
#pragma endregion

#pragma region vector and value
    Vector operator+(value_type val);
    Vector operator*(value_type val);
    Vector operator-(value_type val);
    Vector operator/(value_type val);

    Vector& operator+=(value_type val);
    Vector& operator*=(value_type val);
    Vector& operator-=(value_type val);
    Vector& operator/=(value_type val);
#pragma endregion

#pragma region solo vector
    Vector operator-() const;
    Vector reverse() const;
    Vector& reversed() const;

    Vector normalize() const;
    Vector& normalized();

    Vector &toZero();
    Vector &toUnit();

    value_type length() const;
#pragma endregion

private:
#pragma region assertions
    void assertInBounds(size_type index, const char *file, int line, const char *func) const;
    void assertValidSize(size_type size, const char *file, int line, const char *func) const;
    void assertNotEmpty(const char *file, int line, const char *func) const;
    void assertNoZeroes(const char *file, int line, const char *func) const;
    void assertNotZeroVal(const T& val, const char *file, int line, const char *func) const;
    void assertNotZeroVecror(const char *file, int line, const char *func) const;
    void assertSupportsCrossProduct(const char *file, int line, const char *func);
    void assertEqDim(size_type otherDim, const char *file, int line, const char *func) const;
#pragma endregion
    void allocate(size_type n);
    Vector dim3CrossProduct(const Vector &v);
    Vector dim7CrossProduct(const Vector &v);

    std::shared_ptr<value_type[]> data;
};

#pragma region vector and value
template <typename T>
Vector<T> operator+(const T& val, const Vector<T> &v);
template <typename T>
Vector<T> operator*(const T& val, const Vector<T> &v);
#pragma endregion

#endif //VECTOR_H
