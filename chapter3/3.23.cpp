/*
 * @Author: Jimmy Hua
 * @Date: 2022-08-14 23:33:28
 * @LastEditTime: 2022-08-14 23:39:45
 * @FilePath: /C++Primer/chapter3/3.23.cpp
 * @Description:创建一个含有10个整数的vector对象，然后使用迭代器将所有元素的值都变成原来两倍，输出内容
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vInt;
    srand((unsigned)time(NULL));
    for (int i = 0; i < 10; i++)
    {
        vInt.push_back(rand() % 1000);
    }
    cout << "随机生成的10个数字是：" << endl;

    for (auto it = vInt.begin(); it != vInt.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << "翻倍后10个数字是：" << endl;
    for (auto it = vInt.begin(); it != vInt.end(); it++)
    {
        *it *= 2;
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
