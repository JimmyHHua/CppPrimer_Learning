/*
 * @Author: Jimmy Hua
 * @Date: 2022-08-14 19:26:57
 * @LastEditTime: 2022-08-14 19:27:00
 * @FilePath: /C++Primer/chapter3/3.16.cpp
 * @Description:编程把3.13中vector对象的容量和具体内容输出出来
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};

    cout << "v1 的元素个数是：" << v1.size() << endl;
    if (v1.size() > 0) {        // 当 vector 含有元素时逐个输出
        cout << "v1 的元素分别是：" << endl;
        for (auto e : v1)       // 使用范围 for 语句遍历每一个元素
            cout << e << " ";
        cout << endl;
    }

    cout << "v2 的元素个数是：" << v2.size() << endl;
    if (v2.size() > 0) {
        cout << "v2 的元素分别是：" << endl;
        for (auto e : v2)
            cout << e << " ";
        cout << endl;
    }

    cout << "v3 的元素个数是：" << v3.size() << endl;
    if (v3.size() > 0) {
        cout << "v3 的元素分别是：" << endl;
        for (auto e : v3)
            cout << e << " ";
        cout << endl;
    }

    cout << "v4 的元素个数是：" << v4.size() << endl;
    if (v4.size() > 0) {
        cout << "v4 的元素分别是：" << endl;
        for (auto e : v4)
            cout << e << " ";
        cout << endl;
    }

    cout << "v5 的元素个数是：" << v5.size() << endl;
    if (v5.size() > 0) {
        cout << "v5 的元素分别是：" << endl;
        for (auto e : v5)
            cout << e << " ";
        cout << endl;
    }

    cout << "v6 的元素个数是：" << v6.size() << endl;
    if (v6.size() > 0) {
        cout << "v6 的元素分别是：" << endl;
        for (auto e : v6)
            cout << e << " ";
        cout << endl;
    }

    cout << "v7 的元素个数是：" << v7.size() << endl;
    if (v7.size() > 0) {
        cout << "v7 的元素分别是：" << endl;
        for (auto e : v7)
            cout << e << " ";
        cout << endl;
    }

    return 0;
}
