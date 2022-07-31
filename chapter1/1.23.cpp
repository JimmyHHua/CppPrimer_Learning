/*
 * @Author: Jimmy Hua
 * @Date: 2022-07-31 17:50:17
 * @LastEditTime: 2022-07-31 17:50:50
 * @FilePath: /C++Primer/chapter1/1.23.cpp
 * @Description: 读取多条销售记录，并统计每个ISBN有几条销售记录；
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item currItem, valItem;
    if (std::cin >> currItem)
    {
        int cnt = 1;
        while (std::cin >> valItem)
        {
            if (valItem.isbn() == currItem.isbn())
            {
                ++cnt;
            }
            else
            {
                std::cout << currItem.isbn() << " occurs " << cnt << " times " << std::endl;
                currItem = valItem;
                cnt = 1;
            }
        }
        std::cout << currItem.isbn() << " occurs " << cnt << " times " << std::endl;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}