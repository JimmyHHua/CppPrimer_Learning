/*
 * @Author: Jimmy Hua
 * @Date: 2022-08-13 13:25:55
 * @LastEditTime: 2022-08-13 13:26:59
 * @FilePath: /C++Primer/chapter3/3.7.cpp
 * @Description: 就上一题，如果将循环变量的类型设为char将发生什么？
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
    for (char &c : str)
        c = 'X';
    cout << str << endl;
    return 0;
}