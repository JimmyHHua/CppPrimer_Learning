/*
 * @Author: Jimmy Hua
 * @Date: 2022-08-07 23:46:42
 * @LastEditTime: 2022-08-07 23:46:44
 * @FilePath: /C++Primer/chapter2/2.38.cpp
 * @Description:练习2.38
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>
#include <typeinfo>

int main()
{
    int a = 3;
    auto c1 = a;
    decltype(a) c2 = a;
    decltype((a)) c3 = a;

    const int d = 5;
    auto f1 = d;
    decltype(d) f2 = d;

    std::cout << typeid(c1).name() << std::endl; // int
    std::cout << typeid(c2).name() << std::endl; // int
    std::cout << typeid(c3).name() << std::endl; // int &
    std::cout << typeid(f1).name() << std::endl; // int
    std::cout << typeid(f2).name() << std::endl; // const int

    c1++;
    c2++;
    c3++;
    f1++;
    // f2++;    // 错误：f2 是整型常量，不能执行自增操作
    std::cout << a << " " << c1 << " " << c2 << " " << c3 << " " << f1
              << " " << f2 << std::endl;

    return 0;
}
