#ifndef VECTORCONCEPTS_H
#define VECTORCONCEPTS_H

#include <concepts>
#include <iostream>

template <typename T>
concept Storable = std::semiregular<T>;

template <typename T, typename U>
concept Convertible = std::convertible_to<U, T>;

template <typename T>
concept HasZeroElement = requires()
{
    { T{0} } -> std::convertible_to<T>;
};

template <typename T>
concept HasUnitElement = requires()
{
    { T{1} } -> std::convertible_to<T>;
};

template <typename T, typename U>
concept Addable = requires(const T &t, const U &u)
{
    { t + u };
    { u + t };
};

template <typename T, typename U>
concept Substractable = requires(const T &t, const U &u)
{
    { t - u };
};

template <typename T, typename U>
concept Multiplicable = requires(const T &t, const U &u)
{
    { t * u };
    { u * t };
};

template <typename T, typename U>
concept Divisible = requires(const T &t, const U &u)
{
    { t / u };
};

template <typename T, typename U>
concept AddableAndAssignable = Addable<T, U> && requires(const T &t, const U &u)
{
    std::is_assignable_v<T, decltype(t + u)>;
};

template <typename T, typename U>
concept SubstractableAndAssignable = Substractable<T, U> && requires(const T &t, const U &u)
{
    std::is_assignable_v<T, decltype(t - u)>;
};

template <typename T, typename U>
concept MultiplicableAndAssignable = Multiplicable<T, U> && requires(const T &t, const U &u)
{
    std::is_assignable_v<T, decltype(t * u)>;
};

template <typename T, typename U>
concept DivisibleAndAssignable = Divisible<T, U> && requires(const T &t, const U &u)
{
    std::is_assignable_v<T, decltype(t / u)>;
};

template <typename T>
concept LengthComputable = Addable<T, T> && Multiplicable<T, T> &&
                           requires(T t1, T t2)
                           {
                               { t1 * t2 + t1 * t2 } -> std::convertible_to<double>;
                           };

template <typename T, typename U>
concept MultiplicableAndSunstractable = Multiplicable<T, U> &&
                                        requires(const T &t, const U &u)
                                        {
                                            Substractable<std::common_type_t<T, U>, std::common_type_t<T, U>>;
                                        };

template <typename T>
concept InversibleAndAssignable = requires(T &t)
{
    std::is_assignable_v<T, decltype(-t)>;
};

template <typename T>
concept Inversible = requires(T &t)
{
    { -t };
};

template <typename T, typename U>
concept ComparableDivision = Divisible<T, U> &&
                             requires(const T &t, const U &u)
                             {
                                 { t / u } -> std::equality_comparable;
                             };

template <typename T, typename U>
concept AngleComputable = LengthComputable<T> && LengthComputable<U> &&
                          requires(T t, U u)
                          {
                              { (t * u + u * t) / double{1} } -> std::convertible_to<double>;
                          };

template <typename T, typename U>
concept DotProductComputable = Multiplicable<T, U> &&
                               requires(const T &t, const U &u)
                               {
                                   { t * u } -> AddableAndAssignable<decltype(t * u)>;
                               };

template <typename T>
concept Outable = requires(std::ostream &os, const T &t)
{
    { os << t } -> std::same_as<std::ostream &>;
};

#endif //VECTORCONCEPTS_H