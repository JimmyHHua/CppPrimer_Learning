/*
 * @Author: Jimmy Hua
 * @Date: 2022-07-31 17:35:16
 * @LastEditTime: 2022-07-31 17:46:21
 * @FilePath: /C++Primer/chapter2/2.8.cpp
 * @Description:利用转义序列写一段程序，要求输出2M，然后转到新一行，修改程序使其输出2，然后输出制表符，在输出M，最后转到新一行
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>

int main(int argc, char const *argv[])
{
    // 使用八进制
    std::cout << "-------- Using Oct Output 2M --------" << std::endl;
    std::cout << "\62\115\12";

    std::cout << "-------- output 2 M \n----------" <<std::endl;
    std::cout << "\62";
    std::cout << "\11";
    std::cout << "\115";
    std::cout << "\12";
    return 0;
}
