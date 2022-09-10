/*
 * @Author: Jimmy Hua
 * @Date: 2022-09-04 23:52:11
 * @LastEditTime: 2022-09-04 23:53:02
 * @FilePath: /C++Primer/chapter3/3.41.cpp
 * @Description: 
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved. 
 */
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    const int sz = 10;              // 常量 sz 作为数组的维度
    int a[sz];
    srand((unsigned) time(NULL));   // 生成随机数种子
    cout << "数组的内容是：" << endl;
    // 利用范围 for 循环遍历数组的每个元素
    for (auto &val : a) {
        val = rand() % 100;         // 生成一个 100 以内的随机数
        cout << val << " ";
    }
    cout << endl;

    vector<int> vInt(begin(a), end(a));
    cout << "vector 的内容是：" << endl;
    // 利用范围 for 循环遍历 vector 的每个元素
    for (auto val : vInt) {
        cout << val << " ";
    }
    cout << endl;

    return 0;

}
