/*
 * @Author: Jimmy Hua
 * @Date: 2022-08-14 23:47:25
 * @LastEditTime: 2022-08-14 23:55:38
 * @FilePath: /C++Primer/chapter3/3.24.cpp
 * @Description:用迭代器重做3.3.3最后一题
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */

#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char const *argv[])
{
    vector<int> vInt;
    int iVal;
    cout << "请输入一组数字：" << endl;
    while (cin >> iVal)
        vInt.push_back(iVal);
    if (vInt.cbegin() == vInt.cend())
    {
        cout << "没有任何元素" << endl;
        return -1;
    }
    cout << "相邻两项的和依次是：" << endl;

    for (auto it = vInt.cbegin(); it != vInt.cend() -1; it++)
    {
        cout << *it + *(++it) << " ";
        if ((it - vInt.begin() + 1) % 10 == 0) //每行输出5个数字
            cout << endl;
    }
    //如果元素是奇数
    if (vInt.size() % 2 != 0)
        cout << *(vInt.cend() - 1);
    return 0;
}
