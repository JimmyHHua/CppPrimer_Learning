/*
 * @Author: Jimmy Hua
 * @Date: 2022-07-24 23:40:55
 * @LastEditTime: 2022-07-24 23:46:49
 * @FilePath: /C++Primer/chapter1/1.11.1.cpp
 * @Description:提示用户输入两个整数，打印两个整数所指定的范围内的所有整数；
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>

int main(int argc, char const *argv[])
{
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    if (v1 > v2)
    {
        std::cout << "The range of " << v2 << "to" << v1 << std::endl;
        while (v2 <= v1)
        {
            std::cout << v2 << std::endl;
            ++v2;
        }
    }
    else
    {
        std::cout << "The range of " << v1 << "to" << v2 << std::endl;
        while (v1 <= v2)
        {
            std::cout << v1 << std::endl;
            ++v1;
        }
    }
    return 0;
}
