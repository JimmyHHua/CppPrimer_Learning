/*
 * @Author: Jimmy Hua
 * @Date: 2022-08-13 10:27:06
 * @LastEditTime: 2022-08-13 10:45:55
 * @FilePath: /C++Primer/chapter3/3.5.cpp
 * @Description:编写一段程序重标准输入中读入多个字符串并将它们连在一起，输出连接成的大字符串。然后修改程序，用空格把输入的多个字符串分隔开来？
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>
#include <string>

using namespace std;

//字符拼接
void ConcatString()
{
    char cont = 'y';
    string s, result;
    cout << "请输入第一个字符串：" << endl;
    while (cin >> s)
    {
        result += s;
        cout << "是否继续（y or n）？" << endl;
        cin >> cont;
        if (cont == 'y' || cont == 'Y')
            cout << "请输入下一个字符串：" << endl;
        else
            break;
    }
    cout << "拼接后的字符串是：" << result << endl;
}

//字符拼接，通过空格连接
void ConcatStringWithSpace()
{
    char cont = 'y';
    string s, result;
    cout << "请输入第一个字符串：" << endl;
    while (cin >> s)
    {
        if (!result.size()) // 第一个拼接的字符串之前不加空格
            result += s;
        else // 之后拼接的字符串加空格
            result = result + " " + s;
        cout << "是否继续（y or n）？" << endl;
        cin >> cont;
        if (cont == 'y' || cont == 'Y')
            cout << "请输入下一个字符串：" << endl;
        else
            break;
    }
    cout << "拼接后的字符串是：" << result << endl;
}

int main(int argc, char const *argv[])
{
    // ConcatString();
    ConcatStringWithSpace();
    return 0;
}
