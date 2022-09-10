/*
 * @Author: Jimmy Hua
 * @Date: 2022-08-14 23:59:49
 * @LastEditTime: 2022-08-15 00:02:03
 * @FilePath: /C++Primer/chapter3/3.25.cpp
 * @Description:
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 该 vector 对象记录各分数段的人数，初始值为 0
    vector<unsigned> vScore(11);
    auto it = vScore.begin();
    int iVal;
    cout << "请输入一组成绩（0 ～ 100）：" << endl;
    while (cin >> iVal)
        if (iVal < 101)
            ++*(it + iVal / 10);
    cout << "您总计输入了 " << vScore.size() << " 个成绩" << endl;
    cout << "各分数段的人数分布是（成绩从低到高）：" << endl;
    // 利用迭代器遍历 vUS 的元素并逐个输出
    for (; it != vScore.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
