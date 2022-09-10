/*
 * @Author: Jimmy Hua
 * @Date: 2022-09-04 23:31:13
 * @LastEditTime: 2022-09-04 23:31:15
 * @FilePath: /C++Primer/chapter3/3.37.cpp
 * @Description:
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>

using namespace std;

int main() {
    const char ca[] = {'h', 'e', 'l', 'l', 'o'};
    const char *cp = ca;
    while (*cp) {
        cout << *cp << endl;
        ++cp;
    }

    return 0;
}