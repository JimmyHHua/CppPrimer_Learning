/*
 * @Author: Jimmy Hua
 * @Date: 2022-08-14 19:36:39
 * @LastEditTime: 2022-08-14 19:50:08
 * @FilePath: /C++Primer/chapter3/3.20.cpp
 * @Description:读入一组整数并把他们存入一个vector对象，将没对相邻整数的和输出出来。改写程序，先输出第一个和最后一个元素的和，然后输出第2个核倒数第2个的和，以此类推
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>
#include <vector>

using namespace std;

void SumNeighbor()
{
    vector<int> vInt;
    int iVal;
    cout << "请输入一组数字：" << endl;
    while (cin >> iVal)
        vInt.push_back(iVal);
    if (vInt.size() == 0)
    {
        cout << "没有任何元素" << endl;
        return;
    }
    cout << "相邻两项的和依次是：" << endl;

    for (decltype(vInt.size()) i = 0; i < vInt.size() - 1; i += 2)
    {
        cout << vInt[i] + vInt[i + 1] << " ";
        if ((i + 2) % 10 == 0) //每行输出5个数字
            cout << endl;
    }
    //如果元素是奇数
    if (vInt.size() % 2 != 0)
        cout << vInt[vInt.size() - 1];
}

void SumHeadTail()
{
    vector<int> vInt;
    int iVal;
    cout << "请输入一组数字：" << endl;
    while (cin >> iVal)
        vInt.push_back(iVal);
    if (vInt.size() == 0)
    {
        cout << "没有任何元素" << endl;
        return;
    }
    cout << "首尾两项的和依次是：" << endl;

    for (decltype(vInt.size()) i = 0; i < vInt.size() - 1; i += 2)
    {
        cout << vInt[i] + vInt[vInt.size() - i - 1] << " ";
        if ((i + 2) % 10 == 0) //每行输出5个数字
            cout << endl;
    }
    //如果元素是奇数
    if (vInt.size() % 2 != 0)
        cout << vInt[vInt.size() / 2];
}

int main(int argc, char const *argv[])
{
    SumHeadTail();
    return 0;
}
