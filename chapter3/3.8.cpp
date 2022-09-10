/*
 * @Author: Jimmy Hua
 * @Date: 2022-08-13 13:29:20
 * @LastEditTime: 2022-08-14 17:27:26
 * @FilePath: /C++Primer/chapter3/3.8.cpp
 * @Description: 分别用while循环和传统的for循环重写3.6程序，你觉得哪种形式更好？
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>
#include <string>

using namespace std;

// 使用while
void CodeByWhile()
{
    string str;
    cout << "请输入一个字符串，可以包含空格：" << endl;
    getline(cin, str);
    int i = 0;
    while (str[i] != '\0')
    {
        str[i] = 'X';
        i++;
    }
    cout << str << endl;
}

//使用for
void CodeByFor()
{
    string str;
    cout << "请输入一个字符串，可以包含空格：" << endl;
    getline(cin, str);
    for (unsigned int i = 0; i < str.size(); i++)
    {
        str[i] = 'X';
    }
    cout << str << endl;
}

int main(int argc, char const *argv[])
{
    // CodeByWhile();
    CodeByFor();
    return 0;
}
