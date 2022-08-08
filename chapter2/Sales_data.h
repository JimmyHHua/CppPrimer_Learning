/*
 * @Author: Jimmy Hua
 * @Date: 2022-08-08 23:51:22
 * @LastEditTime: 2022-08-08 23:51:25
 * @FilePath: /C++Primer/chapter2/Sales_data.h
 * @Description:
 * Copyright (c) 2022 by Jimmy Hua, All Rights Reserved.
 */
#ifndef SALESDATA_H
// we're here only if SALESDATA_H has not yet been defined
#define SALESDATA_H

// Definition of Sales_data class and related functions goes here
#include <iostream>
#include <string>

// 头文件不应包含 using 声明
// using namespace std;

class Sales_data
{
    // 友元函数
    friend std::istream &operator>>(std::istream &, Sales_data &);

    // 友元函数
    friend std::ostream &operator<<(std::ostream &, const Sales_data &);

    // 友元函数
    friend bool operator<(const Sales_data &, const Sales_data &);

    // 友元函数
    friend bool operator==(const Sales_data &, const Sales_data &);

public: // 构造函数的 3 种形式
    Sales_data() = default;

    Sales_data(const std::string &book) : bookNo(book) {}

    Sales_data(std::istream &is) { is >> *this; }

    Sales_data &operator+=(const Sales_data &);

    std::string isbn() const { return bookNo; }

private:
    std::string bookNo;        // 书籍编号，隐式初始化为空串
    unsigned units_sold = 0;   // 销售量，显式初始化为 0
    double sellingprice = 0.0; // 原始价格，显式初始化为 0.0
    double saleprice = 0.0;    // 实售价格，显式初始化为 0.0
    double discount = 0.0;     // 折扣，显式初始化为 0.0
};

inline bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() == rhs.isbn();
}

Sales_data operator+(const Sales_data &, const Sales_data &);

inline bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.units_sold == rhs.units_sold &&
           lhs.sellingprice == rhs.sellingprice &&
           lhs.saleprice == rhs.saleprice &&
           lhs.isbn() == rhs.isbn();
}

inline bool operator!=(const Sales_data &lhs, const Sales_data &rhs)
{
    return !(lhs == rhs); // 基于运算符 == 给出 != 的定义
}

Sales_data &Sales_data::operator+=(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    saleprice = (rhs.saleprice * rhs.units_sold + saleprice * units_sold) / (rhs.units_sold + units_sold);
    if (sellingprice != 0)
        discount = saleprice / sellingprice;
    return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data ret(lhs); // 把 lhs 的内容拷贝到临时变量 ret 中，这种做法便于运算
    ret += rhs;          // 把 rhs 的内容加入其中
    return ret;          // 返回 ret
}

std::istream &operator>>(std::istream &in, Sales_data &s)
{
    in >> s.bookNo >> s.units_sold >> s.sellingprice >> s.saleprice;
    if (in && s.sellingprice != 0)
        s.discount = s.saleprice / s.sellingprice;
    else
        s = Sales_data(); // 输入错误，重置输入的数据
    return in;
}

std::ostream &operator<<(std::ostream &out, const Sales_data &s)
{
    out << s.isbn() << " " << s.units_sold << " "
        << s.sellingprice << " " << s.saleprice << " " << s.discount;
    return out;
}

#endif
