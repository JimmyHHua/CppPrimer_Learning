/*
 * @Author: Jimmy Hua
 * @Date: 2022-08-11 22:01:52
 * @LastEditTime: 2022-08-11 22:01:56
 * @FilePath: /C++Primer/chapter3/3.3.cpp
 * @Description: string和getline的使用区别示例
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
    string word, line;
    cout << "请选择读取字符串的方式：1 表示逐词读取， 2 表示整行读取" << endl;
    char ch;
    cin >> ch;
    if (ch == '1') {
        cout << "请输入字符串：    Welcome to C++ family!  " << endl;
        cin >> word;
        cout << "系统读取的有效字符串是：" << endl;
        cout << word << endl;
        return 0;
    }

    // 清空输入缓冲区
    cin.clear();
    cin.ignore();

    if (ch == '2') {
        cout << "请输入字符串：    Welcome to C++ family!  " << endl;
        getline(cin, line);
        cout << "系统读取的有效字符串是：" << endl;
        cout << line << endl;
        return 0;
    }
    cout << "您的输入有误！";

    return -1;
}
