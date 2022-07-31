/*
 * @Author: Jimmy Hua
 * @Date: 2022-07-27 00:18:07
 * @LastEditTime: 2022-07-27 00:23:16
 * @FilePath: /C++Primer/chapter1/1.19.cpp
 * @Description: 修改练习1.10,使其能处理用户输入的第一数比第二个数的情况
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>
int main(int argc, char const *argv[])
{
    std::cout << "please input two numbers: " << std::endl;
    int a = 0, b = 0;
    std::cin >> a >> b;
    if (a > b)
    {
        while (b <= a)
        {
            std::cout << b << std::endl;
            b++;
        }
    }
    else
    {
        while (a <= b)
        {
            std::cout << a << std::endl;
            a++;
        }
    }
    return 0;
}
