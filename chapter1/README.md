# 第1章 开始
本章以一个实际问题，书店问题，来简单的介绍C的基本特性。这个问题的代码将贯彻整本书，后面的章节会逐一讲解代码中涉及到的 C 语言特性。

这个问题具体，就是要保存书店的所有销售记录的档案，每条记录保存了某本书的一次销售信息，包含三个数据：

```
0-201-70353-X	4	24.99
```

它们分别是书的 ISBN，售出的册数，书的单价。有时，书店老板需要查询此档案，计算每本书的销售量、销售额及平均售价。

这个问题会涉及到的有：

- 定义变量
- 进行输入和输出
- 使用数据结构保存数据
- 检测两条数据是否有相同的 ISBN
- 包含一个循环来处理销售档案中的每条记录

我们首先介绍如何使用 C++ 来解决这些子问题，然后编写书店程序。
## 1.1 编写一个简单的C++程序
从一个简单的C++程序开始
```c
int main()
{
    return 0;
}
```
函数定义包含四部分：返回类型、函数名、一个括号包围的**形参列表** （允许为空） 以及 **函数体** 
在大多数系统中，main的返回值用来指示状态：0表示成功，非0的返回值的含义由系统定义，通常用来指出错误类型。
### 1.1.1 编译、运行程序
![](https://cdn.nlark.com/yuque/0/2022/jpeg/29691192/1658581446730-468653e1-7c53-4d84-9aec-fd5a8308bbb4.jpeg)
UNIX系统中运行GNU编译器的命令是：
```bash
g++ -o -std=c++0x prog1 prog1.cc
```
> -o 表示制定可执行文件文件名；-std=c++0x 表示支持C++11

### 1.1 节练习
#### 练习1.2：改写程序，让它返回-1.返回值-1通常被当作程序错误的标识。重新编译并运行你的程序，观察你的系统如何处理main返回的错误标识。
```cpp
int main()
{
    return -1
}
```
```bash
g++ -o -std=c++0x a.out 1.2.cpp
./a.out #运行程序
echo $? #查看系统状态
# 结果输出：255
```
## 1.2 初识输入输出
在C语言中并未定义任何输入输出（IO）语句，取而代之，包含了一个一个全面的标准库来提供 IO 机制。C++使用了iostream库来提供IO机制，iostream包含了2个基本类型**istream** 和 **ostream**, 分别表示**输入流**和**输出流**。
### 标注输入输出对象

- 标准输入 cin
- 标准输出 cout
- 输出警告和错误消息 cerr
- 输出程序运行时的一般信息 clog
### 一个使用 IO 库的程序
```cpp
#include <iostream>
int main()
{
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The sum of " << v1 << " and " << v2
              << " is " << v1 + v2 << std::endl;
    return 0;
}
```
### 向流读写数据

- 输出运算符 <<
- 输入运算符 >>
- 操纵符 endl，将缓冲区内容刷到设备中；
### 1.2 节练习
#### 练习1.3：编写程序，在标准输出上打印Hello,World；
```cpp
#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "Hello,World" << std::endl;
    return 0;
}
```
#### 练习1.4：我们的程序使用假发运算符+来将两个数相加，编写程序使用乘法运算符*来打印两个数的积；
```cpp
#include <iostream>

int main()
{
    int v1, v2;
    std::cout << "Enter two numbers:" << std::endl;
    std::cin >> v1 >> v2;
    std::cout << "The product of " << v1 << " and " << v2
              << " is " << v1 * v2 << std::endl;
    return 0;
}
```
#### 练习1.5：我们将所有输出操作放在一条很长的语句中，重写程序，将每个运算对象的打印操作放在一条独立的语句中；
```cpp
#include <iostream>

int main()
{
    int v1, v2;
    std::cout << "Enter two numbers:" << std::endl;
    std::cin >> v1;
    std::cin >> v2;
    std::cout << "The product of ";
    std::cout << v1;
    std::cout << " and ";
    std::cout << v2;
    std::cout << " is ";
    std::cout << v1 * v2;
    std::cout << std::endl;

    return 0;
}
```
#### 练习1.6：解释下面程序片段是否合法。
```cpp
std::cout << "The sum of " << v1;
          << " and " << v2;
          << " is " << v1 + v2 << std::endl;
```
如果程序是合法的，它输出什么？如果程序不合法，原因何在？应该如何修正？
> 不合法，应该修改为如下

```cpp
std::cout << "The sum of " << v1;
std::cout << " and " << v2;
std::cout << " is " << v1 + v2 << std::endl;
```
## 1.3 注释简介

- **C++的两种注释**
   - 单行注释： //
   - 多行注释： /* */ 
   - PS：跨行时，每行*开头，多行注释不能嵌套，如果有则用单行注释//替代
```cpp
//注释1
//std::cout << "hello" << std::endl;

/*
* 注释2
*/
std::cin >> val;
```
## 1.4 控制流

- 循环和判断语句
### 1.4.1 while 语句
示例： 求 1 到 10 的和
```cpp
#include <iostream>
int main()
{
    int sum = 0, val = 0;
    //只要val小于等于10，while循环持续执行
    while (val <= 10)
    {
        sum += val; 
        ++val; // 等价于 val = val+1
    }
    std::cout << "Sum of 1 to 10 inclusive is "
              << sum << std::endl;
    return 0;
}
```
#### 1.4.1 节练习
##### 练习1.9：编写程序，使用while循环将50到100的整数相加；
```cpp
#include <iostream>

int main(int argc, char *argv[])
{
    int sum = 0, val = 50;
    while (val <= 100)
    {
        sum += val;
        ++val;
    }
    std::cout << "sum of 50 ~ 100 is: " << sum << std::endl;
    return 0;
}
```
##### 练习1.10：除了++运算符将对象增加1之外，还有一个--运算符实现值减1，编写程序，使用递减运算符在循环中按递减顺序打印出10到0之间的整数；
```cpp
#include <iostream>

int main()
{
    int val = 10;
    while (val >= 0)
    {
        std::cout<< val <<std::endl;
        -- val;
    }
    return 0;
}
```
##### 练习1.11：编写程序，提示用户输入两个整数，打印两个整数所指定的范围内的所有整数；
```cpp
#include <iostream>

int main(int argc, char const *argv[])
{
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    if (v1 > v2)
    {
        std::cout << "The range of " << v2 << "to" << v1 << std::endl;
        while (v2 <= v1)
        {
            std::cout << v2 << std::endl;
            ++v2;
        }
    }
    else
    {
        std::cout << "The range of " << v1 << "to" << v2 << std::endl;
        while (v1 <= v2)
        {
            std::cout << v1 << std::endl;
            ++v1;
        }
    }
    return 0;
}
```
### 1.4.2 for语句
`for` 循环， 将上面 `while` 循环改成  `for`
```cpp
#include <iostream>
int main()
{
    int sum = 0; 
	for (int val = 1; val <= 10; ++val)
        sum += val;
    std::cout << "Sum of 1 to 10 inclusive is "
              << sum << std::endl;
    
    return 0;
    
}
```
**比较for循环和while循环的优缺点：**

- 在for循环中,循环控制变量的初始化和修改都放在语句头部分,形式较简洁,且特别适用于循环次数已知的情况。
- 在while循环中,循环控制变量的初始化一般放在while语句之前,循环控制变量的修改一般放在循环体中,形式上不如for语句简洁,但它比较适用于循环次数不易预知的情况(用某一条件控制循环)。
### 1.4.3 读取数量不定的输入数据
```cpp
#include <iostream>
int main()
{
    int sum = 0, val = 0;
    // 读取数据知道遇到文件尾，计算所有值总和
    while (std::cin >> val)
        sum += val;
    std::cout << "Sum  is " << sum << std::endl;
    return 0;
}
```
上面程序在输入结束后除了按回车键，还需要按**结束符**
> 在Windows 系统中输入结束符是按 `Ctrl + Z`，然后按 `Enter` 或 `Return`键 
> 在 UNIX系统中，包括 Mac OS X 系统中，文件结束符输入用 `Ctrl + D`

### 1.4.4 if 语句
示例
```cpp
#include <iostream>
int main() 
{
    // currVal是我们正在统计的数，我们将读入的新值存入val
    int currVal = 0, val = 0;
    // 读取第一个数，并确保确实有数据可以处理
    if(std::cin >> currVal) {
        int cnt = 1;
        while(std::cin >> val) { // 读取剩余的数
            if(val == currVal) {
                ++cnt;
            }
            else {
                std::cout << currVal << " occurs " 
                          << cnt << " times " << std::endl;
                currVal = val; // 记住新值
                cnt = 1;       // 重置计数器
            }
        } // while循环在这里结束
        // 打印文件中最后一个值的个数
        std::cout << currVal << " occurs " 
                  << cnt << " times " << std::endl;
    }
    return 0;
}
```
## 1.5 类简介
在C++中，我们通过定义**类** 来定义自己的数据结构。一个类定义了一个类型（**类类型**），以及与其关联的一组操作。
### 1.5.1 Sales_item 类
`Sales_item` 类的作用是表示一本书的销售总额、售出册数和平均售价。
#### 读写 Sales_item
把 `Sales_item` 当做是一个普通的变量（对象），它的操作和内置类型是一样的
```cpp
#include <iostream>
#include "../Sales_item.h"   // 包含书中提供的Sales_item类代码
int main() 
{
    Sales_item book;
    // 读入 ISBN 号、售出的册数以及销售价格
    std::cin  >> book;
    // 写入 ISBN、售出的册数、总销售额和平均价格
    std::cout << book << std::endl;
    return 0;
}
```
#### Sales_item 对象的加法
像操作两个`int` 变量一样，将两个 `Sales_item` 对象相加
```cpp
#include <iostream>
#include "../Sales_item.h"
int main() 
{
    Sales_item item1, item2;
    std::cin  >> item1 >> item2;	// 读取一对交易记录
    std::cout << item1 + item2 << std::endl;	// 打印它们的和
    return 0;
}
```
### 1.5.2 初识成员函数
将两个 `Sales_item` 对象相加的程序首先应该检查两个对象是否具有相同的 ISBN，`Sales_item` 提供了获取 ISBN 的方法（成员函数）
```cpp
#include <iostream>
#include "../Sales_item.h"
int main() 
{
    Sales_item item1, item2;
    std::cin >> item1 >> item2;
    if(item1.isbn() == item2.isbn()) {
        std::cout << item1 + item2 << std::endl;
        return 0;
    } else {
        std::cerr << "Data must refer to same ISBN" 
                << std::endl;
        return -1;
    }
}
```
#### 什么是成员函数？
```cpp
item1.isbn() == item2.isbn()
```
**成员函数**是定义为类的一部分的函数，有时也称为**方法**
我们通常是使用一个类对象来调用成员函数，如下代码，使用点运算符 （`.`） 来调用对应的成员
```cpp
iterm1.isbn()
```
### **文件重定向：**
程序可以通过标准输入输出向文件中读取以及输出流。例如：
```cpp
addItems <infile> outfile
```
### 1.5 练习习题
#### 练习1.20：读取一组书籍销售记录，将每条记录打印到标准输出上；
```cpp
#include <iostream>
#include "Sales_item.h"

int main(int argc, char const *argv[])
{
    Sales_item book;
    while(std::cin >> book)
    {
        std::cout << book << std::endl;
    }
    return 0;
}
```
#### 练习1.21：读取两个ISBN相同的Sales_item对象，输出他们的和；
```cpp
#include <iostream>
#include "Sales_item.h"

int main(int argc, char const *argv[])
{
    Sales_item book1;
    Sales_item book2;

    std::cin >> book1 >> book2;
    std::cout << book1 + book2 << std::endl;

    return 0;
}
```
#### 练习1.22：读取多个具有相同ISBN的销售纪录，输出所有记录的和；
```cpp
#include <iostream>
#include "Sales_item.h"

int main(int argc, char const *argv[])
{
    Sales_item book, book_sum;
    while (std::cin >> book)
    {
        book_sum += book;
    }
    std::cout << book_sum << std::endl;
    return 0;
}
```
#### 练习1.23：读取多条销售记录，并统计每个ISBN有几条销售记录；
```cpp
#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item currItem, valItem;
    if (std::cin >> currItem)
    {
        int cnt = 1;
        while (std::cin >> valItem)
        {
            if (valItem.isbn() == currItem.isbn())
            {
                ++cnt;
            }
            else
            {
                std::cout << currItem.isbn() << " occurs " << cnt << " times " << std::endl;
                currItem = valItem;
                cnt = 1;
            }
        }
        std::cout << currItem.isbn() << " occurs " << cnt << " times " << std::endl;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}
```
#### 练习1.24：输入表示多个ISBN的多条销售记录来测试上一个程序，每个ISBN的记录应该聚在一起；
输入命令windows为例：
```cpp
a.exe <u1.txt >u2.txt
```
输入file- u1.txt:
```
0-201-70353-X 4 24.99
0-201-82470-1 4 45.39
0-201-88954-4 2 15.00 
0-201-88954-4 5 12.00 
0-201-88954-4 7 12.00 
0-201-88954-4 2 12.00 
0-399-82477-1 2 45.39
0-399-82477-1 3 45.39
0-201-78345-X 3 20.00
0-201-78345-X 2 25.00
```
输出file- u2.txt:
```
0-201-70353-X occurs 1 times 
0-201-82470-1 occurs 1 times 
0-201-88954-4 occurs 4 times 
0-399-82477-1 occurs 2 times 
0-201-78345-X occurs 2 times 
```
#### 练习1.25：借助[网站](https://www.informit.com/store/c-plus-plus-primer-9780321714114)上的Sales_item.h 头文件，编译并运行本节给出的书店程序
```cpp
/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
 * Lippman, Josee Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 * 
 * "Copyright (c) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E. Moo."
 * 
 * 
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 * 
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address: 
 * 
 *     Pearson Education, Inc.
 *     Rights and Permissions Department
 *     One Lake Street
 *     Upper Saddle River, NJ  07458
 *     Fax: (201) 236-3290
*/ 

/* This file defines the Sales_item class used in chapter 1.
 * The code used in this file will be explained in
 * Chapter 7 (Classes) and Chapter 14 (Overloaded Operators)
 * Readers shouldn't try to understand the code in this file
 * until they have read those chapters.
*/

#ifndef SALESITEM_H
// we're here only if SALESITEM_H has not yet been defined 
#define SALESITEM_H

// Definition of Sales_item class and related functions goes here
#include <iostream>
#include <string>

class Sales_item {
// these declarations are explained section 7.2.1, p. 270 
// and in chapter 14, pages 557, 558, 561
friend std::istream& operator>>(std::istream&, Sales_item&);
friend std::ostream& operator<<(std::ostream&, const Sales_item&);
friend bool operator<(const Sales_item&, const Sales_item&);
friend bool 
operator==(const Sales_item&, const Sales_item&);
public:
    // constructors are explained in section 7.1.4, pages 262 - 265
    // default constructor needed to initialize members of built-in type
    Sales_item() = default;
    Sales_item(const std::string &book): bookNo(book) { }
    Sales_item(std::istream &is) { is >> *this; }
public:
    // operations on Sales_item objects
    // member binary operator: left-hand operand bound to implicit this pointer
    Sales_item& operator+=(const Sales_item&);
    
    // operations on Sales_item objects
    std::string isbn() const { return bookNo; }
    double avg_price() const;
// private members as before
private:
    std::string bookNo;      // implicitly initialized to the empty string
    unsigned units_sold = 0; // explicitly initialized
    double revenue = 0.0;
};

// used in chapter 10
inline
bool compareIsbn(const Sales_item &lhs, const Sales_item &rhs) 
{ return lhs.isbn() == rhs.isbn(); }

// nonmember binary operator: must declare a parameter for each operand
Sales_item operator+(const Sales_item&, const Sales_item&);

inline bool 
operator==(const Sales_item &lhs, const Sales_item &rhs)
{
    // must be made a friend of Sales_item
    return lhs.units_sold == rhs.units_sold &&
           lhs.revenue == rhs.revenue &&
           lhs.isbn() == rhs.isbn();
}

inline bool 
operator!=(const Sales_item &lhs, const Sales_item &rhs)
{
    return !(lhs == rhs); // != defined in terms of operator==
}

// assumes that both objects refer to the same ISBN
Sales_item& Sales_item::operator+=(const Sales_item& rhs) 
{
    units_sold += rhs.units_sold; 
    revenue += rhs.revenue; 
    return *this;
}

// assumes that both objects refer to the same ISBN
Sales_item 
operator+(const Sales_item& lhs, const Sales_item& rhs) 
{
    Sales_item ret(lhs);  // copy (|lhs|) into a local object that we'll return
    ret += rhs;           // add in the contents of (|rhs|) 
    return ret;           // return (|ret|) by value
}

std::istream& 
operator>>(std::istream& in, Sales_item& s)
{
    double price;
    in >> s.bookNo >> s.units_sold >> price;
    // check that the inputs succeeded
    if (in)
        s.revenue = s.units_sold * price;
    else 
        s = Sales_item();  // input failed: reset object to default state
    return in;
}

std::ostream& 
operator<<(std::ostream& out, const Sales_item& s)
{
    out << s.isbn() << " " << s.units_sold << " "
        << s.revenue << " " << s.avg_price();
    return out;
}

double Sales_item::avg_price() const
{
    if (units_sold) 
        return revenue/units_sold; 
    else 
        return 0;
}
#endif

```
```cpp
#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item total;
    if (std::cin >> total) //读取第一条交易记录，并确保有数据可以处理
    {
        Sales_item trans;
        while (std::cin >> trans) //读取并处理剩余交易记录
        {
            if (trans.isbn() == total.isbn()) //如果我们仍在处理相同的书
            {
                total += trans; //更新总销售额
            }
            else
            {
                std::cout << total << std::endl; //打印前一本书的结果
                total = trans;                   // total现在表示下一本书的销售额
            }
        }
        std::cout << total << std::endl; //打印最后一本书的结果
    }
    else
    {
        std::cerr << "No data?!" << std::endl; //没有输入警告读者
        return -1;                             // 表示失败
    }
    return 0;
}
```
`a.exe <u1.txt >u2.txt`输出结果
```cpp
0-201-70353-X 4 99.96 24.99
0-201-82470-1 4 181.56 45.39
0-201-88954-4 16 198 12.375
0-399-82477-1 5 226.95 45.39
0-201-78345-X 5 110 22
```
