/*
 * @Author: Jimmy Hua
 * @Date: 2022-07-31 17:48:20
 * @LastEditTime: 2022-07-31 17:48:23
 * @FilePath: /C++Primer/chapter1/1.20.cpp
 * @Description:读取一组书籍销售记录，将每条记录打印到标准输出上；
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>
#include "Sales_item.h"

int main(int argc, char const *argv[])
{
    Sales_item book;
    while(std::cin >> book)
    {
        std::cout << book << std::endl;
    }
    return 0;
}