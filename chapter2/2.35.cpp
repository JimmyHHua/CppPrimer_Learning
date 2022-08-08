/*
 * @Author: Jimmy Hua
 * @Date: 2022-08-07 23:27:34
 * @LastEditTime: 2022-08-07 23:34:18
 * @FilePath: /C++Primer/chapter2/2.35.cpp
 * @Description:练习2.35
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>
#include <typeinfo>

int main()
{
    const int i = 42;
    auto j = i;
    const auto &k = i;
    auto *p = &i;
    const auto j2 = i, &k2 = i;
    std::cout << typeid(i).name() << std::endl;  // i
    std::cout << typeid(j).name() << std::endl;  // i
    std::cout << typeid(k).name() << std::endl;  // i
    std::cout << typeid(p).name() << std::endl;  // PKi
    std::cout << typeid(j2).name() << std::endl; // i
    std::cout << typeid(k2).name() << std::endl; // i

    std::cout << std::endl;
    std::cout << std::boolalpha; // 接下来的输出把 bool 值显示成 true/false

    std::cout << "i and j have same type? "
              << std::is_same<decltype(i), decltype(j)>::value << std::endl;
    std::cout << "i and k have same type? "
              << std::is_same<decltype(i), decltype(k)>::value << std::endl;
    std::cout << "i and j2 have same type? "
              << std::is_same<decltype(i), decltype(j2)>::value << std::endl;
    std::cout << "j and j2 have same type? "
              << std::is_same<decltype(j), decltype(j2)>::value << std::endl;
    std::cout << "k and k2 have same type? "
              << std::is_same<decltype(k), decltype(k2)>::value << std::endl;

    return 0;
}
