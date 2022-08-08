/*
 * @Author: Jimmy Hua
 * @Date: 2022-08-07 17:30:32
 * @LastEditTime: 2022-08-07 23:11:15
 * @FilePath: /C++Primer/chapter2/2.29.cpp
 * @Description:练习2.29
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include <iostream>

int main(int argc, char const *argv[])
{
    int i = 2;
    int *p1, *const p2 = &i;

    const int ic = 2, &r = ic;
    const int *const p3 = &i;
    const int *p;

    i = ic;
    // p1 = p3; //错误, 不能将指针常量分配到 int *指针上；
    // p1 = &ic; /错误, 不能将指针常量分配到 int *指针上；
    // p3 = &ic; //常量指针不能被赋值
    // p2 = p1;  //常量指针不能被赋值
    // ic = *p3; //常量不能被赋值

    return 0;
}
