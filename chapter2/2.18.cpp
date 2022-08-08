/*
 * @Author: Jimmy Hua
 * @Date: 2022-08-06 10:08:38
 * @LastEditTime: 2022-08-06 10:10:44
 * @FilePath: /C++Primer/chapter2/2.18.cpp
 * @Description:练习2.18：编写代码分别更改指针的值和指针所指对象的值
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>

int main(int argc, char const *argv[])
{   
    int ival = 42, *p = &ival;
    std::cout << "ival = " << ival << " " << "*p = " << *p << std::endl;
    *p = 24;
    std::cout << "ival = " << ival << " " << "*p = " << *p << std::endl;
    ival = 25;
    std::cout << "ival = " << ival << " " << "*p = " << *p << std::endl;

    return 0;
}
