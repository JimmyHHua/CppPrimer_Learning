/*
 * @Author: Jimmy Hua
 * @Date: 2022-07-24 23:29:24
 * @LastEditTime: 2022-07-24 23:32:48
 * @FilePath: /C++Primer/chapter1/1.9.cpp
 * @Description: while循环计算50到100整数相加
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>

int main(int argc, char *argv[])
{
    int sum = 0, val = 50;
    while (val <= 100)
    {
        sum += val;
        ++val;
    }
    std::cout << "sum of 50 ~ 100 is: " << sum << std::endl;
    return 0;
}