/*
 * @Author: Jimmy Hua
 * @Date: 2022-07-24 22:53:23
 * @LastEditTime: 2022-07-24 23:01:37
 * @FilePath: /C++Primer/chapter1/1.4.cpp
 * @Description:两数相加和相乘
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>

int main()
{
    int v1, v2;
    std::cout << "Enter two numbers:" << std::endl;
    std::cin >> v1 >> v2;
    std::cout << "The product of " << v1 << " and " << v2
              << " is " << v1 * v2 << std::endl;
    return 0;
}