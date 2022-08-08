/*
 * @Author: Jimmy Hua
 * @Date: 2022-08-07 23:11:00
 * @LastEditTime: 2022-08-07 23:24:22
 * @FilePath: /C++Primer/chapter2/2.34.cpp
 * @Description:练习2.34
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>
int main(int argc, char const *argv[])
{
    int i = 0, &r = i;
    auto a = r;
    const int ci = i, &cr = ci;
    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;
    auto &g = ci;
    std::cout << a << " " << b << " " << c << " " << d << " " << e << " " << g << std::endl;
    a = 42;
    b = 42;
    c = 42;
    // d = 42; //非法，d是整型指针
    // e = 42; //非法，e指向整型常量的指针
    // g = 42; //非法，g绑定整型常量
    std::cout << a << " " << b << " " << c << " " << d << " " << e << " " << g << std::endl;

    return 0;
}
