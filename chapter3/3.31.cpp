/*
 * @Author: Jimmy Hua
 * @Date: 2022-09-04 18:29:08
 * @LastEditTime: 2022-09-04 18:30:12
 * @FilePath: /C++Primer/chapter3/3.31.cpp
 * @Description:
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    const int sz = 10;
    int a[sz];

    for(int i = 0; i < sz; i++)
        a[i] = i;
    for (auto val: a)
        cout << val << " ";
    cout << endl;
    return 0;
}
