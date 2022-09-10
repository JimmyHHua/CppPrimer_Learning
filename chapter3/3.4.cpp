/*
 * @Author: Jimmy Hua
 * @Date: 2022-08-11 22:03:13
 * @LastEditTime: 2022-08-11 22:20:21
 * @FilePath: /C++Primer/chapter3/3.4.cpp
 * @Description:编写一段程序读入两个字符串，比较其是否相等并输出结果；如果不相等，输出较大的那个字符串；该写上述程序，比较两个字符串是否等长，如果不等长，输出较大的那个？
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>
#include <string>

// 比较是否相等
void compare_equals()
{
    std::string s1, s2;
    std::cout << "请输入两个字符串：" << std::endl;
    std::cin >> s1 >> s2;
    if (s1 == s2)
        std::cout << "两个字符串相等" << std::endl;
    else if (s1 > s2)
        std::cout << s1 << "大于" << s2 << std::endl;
    else
        std::cout << s2 << " 大于 " << s1 << std::endl;
}

//比较长度
void compare_lenght()
{
    std::string s1, s2;
    std::cout << "请输入两个字符串：" << std::endl;
    std::cin >> s1 >> s2;

    auto len1 = s1.size();
    auto len2 = s2.size();

    if (len1 == len2)
        std::cout << s1 << " 和 " << s2 << " 的长度都是 " << len1 << std::endl;
    else if (len1 > len2)
        std::cout << s1 << " 比 " << s2 << " 的长度多 " << len1 - len2 << std::endl;
    else
        std::cout << s1 << " 比 " << s2 << " 的长度小 " << len2 - len1 << std::endl;
}

int main()
{   
    //compare_equals();
    compare_lenght();
}