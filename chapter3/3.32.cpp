/*
 * @Author: Jimmy Hua
 * @Date: 2022-09-04 18:31:22
 * @LastEditTime: 2022-09-04 18:34:29
 * @FilePath: /C++Primer/chapter3/3.32.cpp
 * @Description:拷贝数组
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>
#include <vector>
using namespace std;

void copyArray()
{
    const int sz = 10; // 常量 sz 作为数组的维度
    int a[sz], b[sz];

    for (int i = 0; i < sz; i++)
        a[i] = i;
    for (int j = 0; j < sz; j++)
        b[j] = a[j];
    // 通过范围 for 循环输出数组的全部元素
    for (auto val : b)
        cout << val << " ";
    cout << endl;
}

void copy_vector(){
    const int sz = 10;          // 常量 sz 作为 vector 的容量
    vector<int> vInt, vInt2;
    // 通过 for 循环为 vector 对象的元素赋值
    for (int i = 0; i < sz; i++)
        vInt.push_back(i);
    for (int j = 0; j < sz; j++)
        vInt2.push_back(vInt[j]);
    // 通过范围 for 循环输出 vector 对象的全部元素
    for (auto val : vInt2)
        cout << val << " ";
    cout << endl;
}

int main(int argc, char const *argv[])
{
    // copyArray();
    copy_vector();
    return 0;
}
