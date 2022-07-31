/*
 * @Author: Jimmy Hua
 * @Date: 2022-07-26 23:41:00
 * @LastEditTime: 2022-07-26 23:41:03
 * @FilePath: /C++Primer/chapter1/1.16.cpp
 * @Description: 编写程序，从cin读取一组数，输出其和
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */

#include <iostream>

int main(int argc, char const *argv[])
{
    int sum = 0, val = 0;
    while (std::cin >> val)
    {
        sum += val;
    }
    std::cout << "The sum is: " << sum << std::endl;
    return 0;
}
