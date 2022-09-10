/*
 * @Author: Jimmy Hua
 * @Date: 2022-08-14 19:28:25
 * @LastEditTime: 2022-08-14 19:30:28
 * @FilePath: /C++Primer/chapter3/3.17.cpp
 * @Description:从cin读入一组词并存入vector，然后所有改成大写，输出结果，每个词占一行；
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<string> str;
    string s;
    char cont = 'y'; // 与用户交互，决定是否继续输入
    cout << "请输入第一个词：" << endl;
    while (cin >> s)
    {
        str.push_back(s); // 向 vector 对象中添加元素
        cout << "您要继续吗（y or n）？" << endl;
        cin >> cont;
        if (cont != 'y' && cont != 'Y')
            break;
        cout << "请输入下一个词：" << endl;
    }
    cout << "转换后的结果是：" << endl;
    for (auto &m : str)
    {
        for (auto &c : m)
            c =toupper(c);
        cout << m << endl;
    }

    return 0;
}
