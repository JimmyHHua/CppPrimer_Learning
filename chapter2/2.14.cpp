/*
 * @Author: Jimmy Hua
 * @Date: 2022-08-02 00:24:50
 * @LastEditTime: 2022-08-02 00:26:56
 * @FilePath: /C++Primer/chapter2/2.14.cpp
 * @Description:判断下面的程序合法吗
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>
int main(int argc, char const *argv[])
{
    int i = 100, sum = 0;
    for (int i = 0; i!=10; ++i)
        sum += i ;
        std::cout << i << " " << sum << std::endl;   
        return 0;
}
