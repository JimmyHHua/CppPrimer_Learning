/*
 * @Author: Jimmy Hua
 * @Date: 2022-08-02 00:15:15
 * @LastEditTime: 2022-08-02 00:16:19
 * @FilePath: /C++Primer/chapter2/2.10.cpp
 * @Description:下列变量的初值分别是什么
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>

std::string global_str;
int global_int;

int main(int argc, char const *argv[])
{
    int local_int;
    std::string local_str;
    std::cout << "global_str = " << global_str << std::endl;
    std::cout << "global_int = " << global_int << std::endl;
    std::cout << "local_str = " << local_str << std::endl;
    std::cout << "local_int = " << local_int << std::endl;

    return 0;
}
