/*
 * @Author: Jimmy Hua
 * @Date: 2022-09-10 15:22:42
 * @LastEditTime: 2022-09-10 15:36:33
 * @FilePath: /C++Primer/chapter3/3.43.cpp
 * @Description:
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    cout << "使用范围for语句输出多维数组内容为： " << endl;
    for (int(&row)[4] : ia)
    {
        for (int &col : row)
            cout << col << " ";
        cout << endl;
    }

    cout << "利用for循环和下标运算符输出数组内容为：" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            cout << ia[i][j] << " ";
        cout << endl;
    }

    cout << "利用for循环和指针输出数组内容为：" << endl;
    for (int(*p)[4] = ia; p != ia + 3; p++)
    {
        for (int *q = *p; q != *p + 4; q++)
            cout << *q << " ";
        cout << endl;
    }

    return 0;
}
