/*
 * @Author: Jimmy Hua
 * @Date: 2022-09-04 23:40:31
 * @LastEditTime: 2022-09-04 23:49:03
 * @FilePath: /C++Primer/chapter3/3.40.cpp
 * @Description:
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
    char str1[] = "hello world ";
    char str2[] = "by jimmy";


    char result[strlen(str1) + strlen(str2) + 1];
    strcpy(result, str1);
    strcat(result, str2);

    cout << "第一个字符串是：" << str1 << endl;
    cout << "第二个字符串是：" << str2 << endl;
    cout << "拼接后的字符串是：" << result << endl;

    return 0;
}
