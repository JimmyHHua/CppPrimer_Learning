/*
 * @Author: Jimmy Hua
 * @Date: 2022-07-31 17:49:20
 * @LastEditTime: 2022-07-31 17:49:27
 * @FilePath: /C++Primer/chapter1/1.21.cpp
 * @Description:读取两个ISBN相同的Sales_item对象，输出他们的和
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>
#include "Sales_item.h"

int main(int argc, char const *argv[])
{
    Sales_item book1;
    Sales_item book2;

    std::cin >> book1 >> book2;
    std::cout << book1 + book2 << std::endl;

    return 0;
}