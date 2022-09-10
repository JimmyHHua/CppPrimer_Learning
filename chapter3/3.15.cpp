/*
 * @Author: Jimmy Hua
 * @Date: 2022-08-14 19:24:30
 * @LastEditTime: 2022-08-14 19:25:44
 * @FilePath: /C++Primer/chapter3/3.15.cpp
 * @Description:改写3.14程序，不过这次读入字符串
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<string> vInt;
    string str;
    char cont = 'y';
    while (cin >> str)
    {
        vInt.push_back(str);
        cout << "您要继续吗（y or n）？" << endl;
        cin >> cont;
        if (cont != 'y' && cont != 'Y')
            break;
    }
    for (auto m : vInt)
        cout << m << endl;

    return 0;
}