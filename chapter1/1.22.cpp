/*
 * @Author: Jimmy Hua
 * @Date: 2022-07-31 17:49:50
 * @LastEditTime: 2022-07-31 17:50:03
 * @FilePath: /C++Primer/chapter1/1.22.cpp
 * @Description:读取多个具有相同ISBN的销售纪录，输出所有记录的和；
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>
#include "Sales_item.h"

int main(int argc, char const *argv[])
{
    Sales_item book, book_sum;
    while (std::cin >> book)
    {
        book_sum += book;
    }
    std::cout << book_sum << std::endl;
    return 0;
}