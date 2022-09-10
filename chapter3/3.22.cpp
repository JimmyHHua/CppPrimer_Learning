/*
 * @Author: Jimmy Hua
 * @Date: 2022-08-14 23:14:00
 * @LastEditTime: 2022-08-14 23:32:10
 * @FilePath: /C++Primer/chapter3/3.22.cpp
 * @Description:修改之前输出text第一段的程序，首先把text的第一段全部改成大写，然后再输出
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<string> text;
    string s;
    // 利用 getline 读取一句话，直接回车产生一个空串，表示段落结束
    while (getline(cin, s))
    {
        text.push_back(s); // 逐个添加到 text 中
        if (getchar() == 'q')
            break;
    }
    // 利用迭代器遍历全部字符串，遇空串停止循环
    for (auto it = text.begin(); it != text.end() && !it->empty(); ++it)
    {
        for (auto it2 = it->begin(); it2 != it->end(); ++it2)
            *it2 = toupper(*it2);
        cout << *it << endl;
    }
    return 0;
}
