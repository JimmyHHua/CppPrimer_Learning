/*
 * @Author: Jimmy Hua
 * @Date: 2022-07-26 23:19:47
 * @LastEditTime: 2022-07-26 23:30:17
 * @FilePath: /C++Primer/chapter1/1.13.cpp
 * @Description:使用for循环重做1.4.1所有练习
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */

#include <iostream>
int main(int argc, char const *argv[])
{
    // Exercise 1.9
    int sum1 = 0;
    for (int val = 50; val <= 100; val++)
    {
        sum1 += val;
    }
    std::cout << "The sum is: " << sum1 << std::endl;

    // Exercise 1.10
    for (int i = 10; i >= 0; i--)
    {
        std::cout << i << " " << std::endl;
    }

    // Exercise 1.11
    std::cout << "please input two numbers: " << std::endl;
    int a = 0, b = 0;
    std::cin >> a >> b;
    if (a <= b)
    {
        int temp = b;
        b = a;
        a = temp;
    }
    for (; b <= a; b++)
    {
        std::cout << b << " ";
    }
    std::cout << std::endl;

    return 0;
}
