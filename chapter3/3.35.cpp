/*
 * @Author: Jimmy Hua
 * @Date: 2022-09-04 18:40:52
 * @LastEditTime: 2022-09-04 18:41:59
 * @FilePath: /C++Primer/chapter3/3.35.cpp
 * @Description:利用begin和end
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a[10], i = 0;
    for (int i = 0; i < 10; i++)
    {
        a[i] = i;
    }
    cout << "初始状态下数组的内容是：" << endl;
    for (auto val : a)
        cout << val << " ";
    cout << endl;

    int *p = begin(a);
    while(p != end(a)){
        *p = 0;
        p++;
    }
    cout << "修改后的数组内容是：" << endl;
    // 通过范围 for 循环输出数组的全部元素
    for (auto val : a)
        cout << val << " ";
    cout << endl;
    return 0;
}
