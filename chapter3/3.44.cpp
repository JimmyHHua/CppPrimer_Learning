/*
 * @Author: Jimmy Hua
 * @Date: 2022-09-10 15:37:57
 * @LastEditTime: 2022-09-10 15:38:59
 * @FilePath: /C++Primer/chapter3/3.44.cpp
 * @Description:
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>
using namespace std;

// using int_array = int[4];
typedef int int_array[4];

int main(int argc, char const *argv[])
{
    int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    cout << "使用类别别名多维数组内容为： " << endl;
    for (int_array(&row) : ia)
    {
        for (int &col : row)
            cout << col << " ";
        cout << endl;
    }
    return 0;
}