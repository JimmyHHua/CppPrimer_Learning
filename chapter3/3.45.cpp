/*
 * @Author: Jimmy Hua
 * @Date: 2022-09-10 15:41:00
 * @LastEditTime: 2022-09-10 15:41:03
 * @FilePath: /C++Primer/chapter3/3.45.cpp
 * @Description:
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    cout << "使用类别别名多维数组内容为： " << endl;
    for (auto &row : ia)
    {
        for (int &col : row)
            cout << col << " ";
        cout << endl;
    }

    cout << "利用for循环和指针输出数组内容为：" << endl;
    for (auto p = ia; p != ia + 3; p++)
    {
        for (auto q = *p; q != *p + 4; q++)
            cout << *q << " ";
        cout << endl;
    }

    return 0;
}