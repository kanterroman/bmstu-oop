#include "ConstIterator.hpp"
#include "Iterator.hpp"
#include "Vector.hpp"
#include "ReverseIterator.h"
#include "ConstReverseIterator.h"
#include "ConstReverseIterator.hpp"
#include "ReverseIterator.hpp"
#include <vector>

#include <iostream>

// class A
// {
    // int b = 0;
// public:
    // template <typename T>
    // A operator+(T &a) noexcept(!std::same_as<T, double>) { b += a; return *this; }
    // template <typename T>
    // A operator-(T &a) noexcept(true) { throw std::bad_alloc() ;return *this; }
// };

int main()
{
    // Создание
    {
        Vector<int> v1(1);
        int arr[] = { 1 , 2, 3, 4, 5 };
        Vector<int> a(arr, 5);
        std::cout << a << std::endl;
        // auto range = std::ranges::subrange(v3.begin(), v3.end());
        Vector<double> v2(3, 1);
        Vector<double> v3({ 1.3, 2.0, 33.3 });
        // std::cout << noexcept(v3 + v2);
        std::cout << std::endl;
        // Vector<double> vtest(range.begin(), 2);
        // std::cout << vtest << std::endl;
    }
    // Работа с итератором
    {
        Vector<std::vector<int>> vv(5);
        vv.begin()->size();
        Vector<double> v({1});
        v = { 1, 2, 3, 4 };
        auto itb = v.begin();
        // auto ite = v.end();
        // auto rng = std::ranges::subrange(v.begin(), v.end());
        Vector<double> v1(std::move(v));
        // v += 2;
        std::cout << "AA " << v1 << std::endl;
        // const Iterator<double> it{v.begin()};
        // *it = 3;
        // std::cout << "TEST" << std::endl;
        // for (auto i = cv.begin(); i != cv.end(); ++i)
        // {
        //     std::cout << *i << " ";
        //     *i = 0;
        // }
        std::cout << std::endl;
        auto iter = v.begin();
        iter++;
        ++iter;
        std::cout << iter[2] << std::endl;
        std::cout << *iter << std::endl;
        try
        {
            iter[10];
        } catch (IterOutOfBondsException& e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << v.end() - v.begin() << std::endl;
        auto citer = v.cbegin();
        citer++;
        ++citer;
        // *citer = 3; ERROR
    }
    // Проверки на векторы
    {
        Vector<long> v1({1, 2, 3});
        Vector<long> v2({0, 0, 0});
        Vector<int> v3({1, 1, 1});
        std::cout << v1.isUnit() << v1.isZero() << std::endl;
        std::cout << v2.isUnit() << v2.isZero() << std::endl;
        std::cout << v3.isUnit() << v3.isZero() << std::endl;
    }
    // Геттеры/сеттеры
    {
        Vector<double> v1({ 10.5, 2.1, 1., 3.3, 11. });
        Vector<int> v2({ 10, 0 });
        std::cout << v1.dimension() << v2.dimension() << std::endl;
        std::cout << v1.getElement(0) << v1[0] << std::endl;
        std::cout << v2.getElement(0) << v2[0] << std::endl;

        v1.setElement(13, 0);
        std::cout << v1[0] << std::endl;
    }
    // Операции с двумя векторами
    {
        Vector<double> v1({ 10.0, 5.3, 4.5 });
        Vector<int> v2({ 10, 5, 4 });
        auto v3 = v1 + v2;
        std::cout << v3 << std::endl;
        auto v4 = v2 + v1;
        std::cout << v4 << std::endl;
        auto v5 = v1 - v2;
        std::cout << v5 << std::endl;
        auto v6 = v1 * v2;
        std::cout << v6 << std::endl;
        auto v7 = v1 / v2;
        std::cout << v7 << std::endl;
        v1 += v2;
        std::cout << v1 << std::endl;
        v1 -= v2;
        std::cout << v1 << std::endl;
        v1 *= v2;
        std::cout << v1 << std::endl;
        v1 /= v2;
        std::cout << v1 << std::endl;

        Vector<int> v_1({ 1, 2, 3 });
        Vector<int> v_2({ 1, 2, 3 });
        std::cout << (v_1 == v_2) << v_1.equals(v_2) << std::endl;
        v_1 += v_2;
        std::cout << (v_1 == v_2) << v_1.equals(v_2) << std::endl;

        Vector<int> v_1_({ 12, 15, 2 });
        Vector<double> v_2_({ 1.2, 1.5, 0.2 });
        std::cout << (v_1_ || v_2_) << std::endl;

        Vector<int> _v_1({ 1, 0 });
        Vector<int> _v_2({ 0, 1 });
        std::cout << _v_1.orthogonal(_v_2) << std::endl;
        std::cout << _v_1.angle(_v_2) << std::endl;

        Vector<double> _v_3({ 1.5, 4.5, 9.1 });
        Vector<short> _v_4({ 10, 4, 1 });
        std::cout << _v_3.dotProduct(_v_4) << std::endl;

        auto _v_pr = _v_3.crossProduct(_v_4);
        std::cout << _v_pr << std::endl;

        Vector<int> _v_7_1({ 1, 2, 3, 4, 5, 6, 7 });
        // Vector<int> _v_7_1 = { 1, 0, 0, 0, 0, 0, 0 };
        Vector<int> _v_7_2({ 7, 6, 5, 4, 3, 2, 1 });
        // Vector<int> _v_7_2 = { 0, 1, 0, 0, 0, 0, 0 };
        auto res = _v_7_1.crossProduct(_v_7_2);
        std::cout << res << std::endl;
        std::cout << res.angle(_v_7_1) << std::endl;
    }
    // Вектор и число
    {
        Vector<int> v1({ 1, 2, 3, 4 });
        double add = 1.5;
        std::cout << (v1 + add) << std::endl;
        std::cout << (v1 - add) << std::endl;
        std::cout << (v1 * add) << std::endl;
        std::cout << (v1 / add) << std::endl;
    }
    // Действия над вектором
    {
        Vector<double> v1({ 1.1, 2.1, 3.1, 4. });
        std::cout << -v1 << std::endl;
        v1.reversed();
        std::cout << v1 << std::endl;
        v1.reversed();
        auto v2 = v1.normalize();
        v1.normalized();
        std::cout << v2 << v2.length() << std::endl;
        std::cout << v1.toUnit() << std::endl;
        std::cout << v2.toZero() << std::endl;
    }
    // {
        // A test;
        // double a = 1;
        // std::cout << noexcept(test - a) << std::endl;
        // test - a;
    // }
}