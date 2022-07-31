/*
 * @Author: Jimmy Hua
 * @Date: 2022-07-26 23:55:54
 * @LastEditTime: 2022-07-27 00:15:08
 * @FilePath: /C++Primer/chapter1/1.18.cpp
 * @Description:编译并运行本节程序，输入全部相等的值，再次运行程序，输入没有重复的值；
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>

int main(int argc, char const *argv[])
{
    int currVal = 0, val = 0;
    if (std::cin >> currVal)
    {
        int cnt = 1;
        while (std::cin >> val)
        {
            if (currVal == val)
                ++cnt;
            else
            {
                std::cout << currVal << " occurs " << cnt << " times " << std::endl;
                currVal = val;
                cnt = 1;
            }
        }
        std::cout << currVal << " occurs " << cnt << " times " << std::endl;
    }
    return 0;
}
