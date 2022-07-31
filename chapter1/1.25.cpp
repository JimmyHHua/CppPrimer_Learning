/*
 * @Author: Jimmy Hua
 * @Date: 2022-07-31 17:51:07
 * @LastEditTime: 2022-07-31 17:52:42
 * @FilePath: /C++Primer/chapter1/1.24.cpp
 * @Description:借助网站上的Sales_item.h 头文件，编译并运行本节给出的书店程序
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item total;
    if (std::cin >> total) //读取第一条交易记录，并确保有数据可以处理
    {
        Sales_item trans;
        while (std::cin >> trans) //读取并处理剩余交易记录
        {
            if (trans.isbn() == total.isbn()) //如果我们仍在处理相同的书
            {
                total += trans; //更新总销售额
            }
            else
            {
                std::cout << total << std::endl; //打印前一本书的结果
                total = trans;                   // total现在表示下一本书的销售额
            }
        }
        std::cout << total << std::endl; //打印最后一本书的结果
    }
    else
    {
        std::cerr << "No data?!" << std::endl; //没有输入警告读者
        return -1;                             // 表示失败
    }
    return 0;
}