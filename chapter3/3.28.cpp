/*
 * @Author: Jimmy Hua
 * @Date: 2022-09-04 18:17:53
 * @LastEditTime: 2022-09-04 18:21:36
 * @FilePath: /C++Primer/chapter3/3.28.cpp
 * @Description:
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */

#include <iostream>
using namespace std;

string sa[10];
int ia[10];

int main()
{
    string sa2[10];
    int ia2[10];

    for (auto c : sa)
        cout << c << " ";
    cout << endl;
    for (auto c : sa2)
        cout << c << " ";
    cout << endl;
    for (auto c : ia)
        cout << c << " ";
    cout << endl;
    for (auto c : ia2)
        cout << c << " ";
    cout << endl;
    return 0;
}