/*
 * @Author: Jimmy Hua
 * @Date: 2022-08-10 23:16:13
 * @LastEditTime: 2022-08-11 21:50:50
 * @FilePath: /C++Primer/chapter3/3.2.cpp
 * @Description:编写一段程序从标准输入中一次读入一整行，然后修改该程序使其一次读入一个词
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>
#include <string>
using std::string;

//输入一行输出一行
void input_line()
{
    string line;
    while (getline(std::cin, line))
        std::cout << line << std::endl;
}

//一次读入一个词，遇到空白停止
void input_word()
{
    string s;
    while (std::cin >> s)
        std::cout << s << std::endl;
}

int main(int argc, char const *argv[])
{
    // input_line();
    input_word();

    return 0;
}
