/*
 * @Author: Jimmy Hua
 * @Date: 2022-07-26 23:33:24
 * @LastEditTime: 2022-07-26 23:33:28
 * @FilePath: /C++Primer/chapter1/1.15.cpp
 * @Description:编译器中常见的一些错误信息
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#include<iostream>
int main() 
{
	//语法错误syntax error：例如
	/*
	1，单行命令结尾忘记写分号
	2，字符串输出忘记加双引号
	3，main的参数列表忘记了
	4，大括号，破折号，引号等没有对等好
	*/

	//类型错误type error:
	/*
	例如，定义的是int型变量，却传入了一个字符型数据
	*/

	//声明错误declaration error	
	/*
	应用未声明的变量: 如用cin忘记添加std::或者用变量i却没有定义
	*/
}