/*
 * @Author: Jimmy Hua
 * @Date: 2022-08-06 10:01:34
 * @LastEditTime: 2022-08-06 10:02:39
 * @FilePath: /C++Primer/chapter2/2.17.cpp
 * @Description:练习2.17：执行下面你的代码段输出什么结果？
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>

int main(int argc, char const *argv[])
{
    int i, &ri = i;
    i = 5;
    ri = 10;
    std::cout << i <<" " << ri << std::endl; 
    return 0;
}
