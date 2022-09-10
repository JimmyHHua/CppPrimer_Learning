/*
 * @Author: Jimmy Hua
 * @Date: 2022-08-14 19:17:42
 * @LastEditTime: 2022-08-14 19:23:03
 * @FilePath: /C++Primer/chapter3/3.14.cpp
 * @Description:用cin读入一组整数并把他们存入一个vector对象中
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vInt;
    int i = 0;
    char cont = 'y';
    while (cin >> i)
    {
        vInt.push_back(i);
        cout << "您要继续吗（y or n）？" << endl;
        cin >> cont;
        if (cont != 'y' && cont != 'Y')
            break;
    }
    for (auto m : vInt)
        cout << m << endl;

    return 0;
}
