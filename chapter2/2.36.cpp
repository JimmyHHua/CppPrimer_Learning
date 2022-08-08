/*
 * @Author: Jimmy Hua
 * @Date: 2022-08-07 23:39:34
 * @LastEditTime: 2022-08-07 23:39:36
 * @FilePath: /C++Primer/chapter2/2.36.cpp
 * @Description:练习2.36
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>
#include <typeinfo>

int main() {
    int a = 3, b = 4;
    decltype(a) c = a;
    decltype((b)) d = a;
    ++c;
    ++d;
    std::cout << typeid(c).name() << std::endl; // int
    std::cout << typeid(d).name() << std::endl; // int &
    std::cout << c << std::endl; // 4
    std::cout << d << std::endl; // 4

    return 0;
}