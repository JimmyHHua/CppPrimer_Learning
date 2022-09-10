/*
 * @Author: Jimmy Hua
 * @Date: 2022-09-04 23:55:35
 * @LastEditTime: 2022-09-04 23:59:28
 * @FilePath: /C++Primer/chapter3/3.43.cpp
 * @Description:
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    const int sz = 10;                  // 常量 sz 作为 vector 对象的容量
    vector<int> vInt;
    srand((unsigned) time(NULL));       // 生成随机数种子
    cout << "vector 对象的内容是：" << endl;
    // 利用 for 循环遍历 vector 对象的每个元素
    for (int i = 0; i != sz; i++) {
        vInt.push_back(rand() % 100);   // 生成一个 100 以内的随机数
        cout << vInt[i] << " ";
    }
    cout << endl;

    auto it = vInt.cbegin();
    int a[vInt.size()];
    cout << "数组的内容是：" << endl;
    // 利用范围 for 循环遍历 vector 的每个元素
    for (auto &val : a) {
        val = *it;
        cout << val << " ";
        it++;
    }
    cout << endl;

    return 0;
}
