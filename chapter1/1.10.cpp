/*
 * @Author: Jimmy Hua
 * @Date: 2022-07-24 23:33:32
 * @LastEditTime: 2022-07-24 23:34:35
 * @FilePath: /C++Primer/chapter1/1.10.cpp
 * @Description:打印10到0的所有整数
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>

int main()
{
    int val = 10;
    while (val >= 0)
    {
        std::cout<< val <<std::endl;
        -- val;
    }
    return 0;
}