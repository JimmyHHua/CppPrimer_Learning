/*
 * @Author: Jimmy Hua
 * @Date: 2022-09-04 23:34:37
 * @LastEditTime: 2022-09-04 23:38:44
 * @FilePath: /C++Primer/chapter3/3.39.cpp
 * @Description:
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{   
    // C++风格
    /*
    string st1, st2;
    cout << "请输入两个字符串： " << endl;
    cin >> st1 >> st2;

    if (st1 > st2)
        cout << "第一个字符串大于第二个字符串" << endl;
    else if (st1 < st2)
        cout << "第一个字符串小于于第二个字符串" << endl;
    else
        cout << "第一个字符串等于第二个字符串"<< endl;
    */

    char st1[80], st2[80];
    cout << "请输入两个字符串：" << endl;
    cin >> st1 >> st2;

    // 利用 cstring 头文件中定义的 strcmp 函数比较大小
    auto result = strcmp(st1, st2);
    if(result > 0)
        cout << "第一个字符串大于第二个字符串" << endl;
    else if (result < 0)
        cout << "第一个字符串小于第二个字符串" << endl;
    else
        cout << "两个字符串相等" << endl;
    return 0;
}
