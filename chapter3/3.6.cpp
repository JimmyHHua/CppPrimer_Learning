/*
 * @Author: Jimmy Hua
 * @Date: 2022-08-13 13:13:49
 * @LastEditTime: 2022-08-13 13:25:45
 * @FilePath: /C++Primer/chapter3/3.6.cpp
 * @Description:编写一段程序，使用范围for语句将字符串内的所有字符用x代替
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string str;
    cout << "请输入一个字符串，可以包含空格：" << endl;
    getline(cin, str);
    for (auto &c : str)
        c = 'X';
    cout << str << endl;
    return 0;
}
