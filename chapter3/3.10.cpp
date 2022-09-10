/*
 * @Author: Jimmy Hua
 * @Date: 2022-08-14 17:29:24
 * @LastEditTime: 2022-08-14 17:32:05
 * @FilePath: /C++Primer/chapter3/3.10.cpp
 * @Description: 编写程序，读入一个包含标点符号的字符串，将标点符号去除后输出字符串剩余的部分
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string str;
    cout << "请输入一个字符串，最好含有某些标点符号：" << endl;
    getline(cin, str);
    for (auto c : str)
        if (!ispunct(c))
            cout << c;
    return 0;
}
