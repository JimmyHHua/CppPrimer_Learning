/*
 * @Author: Jimmy Hua
 * @Date: 2022-07-31 17:18:58
 * @LastEditTime: 2022-07-31 17:21:24
 * @FilePath: /C++Primer/chapter2/2.3.cpp
 * @Description:读写程序结果
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>

int main(int argc, char const *argv[])
{
    std::cout << sizeof(unsigned) << std::endl;
    std::cout << sizeof(int) << std::endl;
    std::cout << "**************************" << std::endl;

    unsigned u = 10, u2 = 42;
    std::cout << u2 - u << std::endl;
    std::cout << u - u2 << std::endl;
    std::cout << "**************************" << std::endl;

    int i = 10, i2 = 42;
    std::cout << i2 - i << std::endl;
    std::cout << i - i2 << std::endl;
    std::cout << i - u << std::endl;
    std::cout << u - i << std::endl;

    return 0;
}
