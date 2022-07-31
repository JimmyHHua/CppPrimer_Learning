/*
 * @Author: Jimmy Hua
 * @Date: 2022-07-24 22:59:03
 * @LastEditTime: 2022-07-24 23:01:19
 * @FilePath: /C++Primer/chapter1/1.5.cpp
 * @Description:
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>

int main()
{
    int v1, v2;
    std::cout << "Enter two numbers:" << std::endl;
    std::cin >> v1;
    std::cin >> v2;
    std::cout << "The product of ";
    std::cout << v1;
    std::cout << " and ";
    std::cout << v2;
    std::cout << " is ";
    std::cout << v1 * v2;
    std::cout << std::endl;

    return 0;
}