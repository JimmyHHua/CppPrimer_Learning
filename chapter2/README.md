# 2.1 基本内置类型
## 2.1.1 算术类型
算术类型分为两类： **整型** （包括字符和布尔类型在内）和 **浮点型**![image.png](https://cdn.nlark.com/yuque/0/2022/png/29691192/1659256587299-4b38b438-978f-469d-ae66-06bf88adda87.png#clientId=u60bc39c5-ee5d-4&crop=0&crop=0&crop=1&crop=1&id=trFRu&name=image.png&originHeight=464&originWidth=827&originalType=binary&ratio=1&rotation=0&showTitle=false&size=144153&status=done&style=none&taskId=ue26cbdac-b9f7-4b39-b120-5a8c78f4cba&title=)
## 2.1.2 类型转换
当在程序中使用一种类型而其实对象应该取另一种类型时，程序会自动进行类型转换。
```cpp
bool b = 42;		// b 为真
int i = b;			// i 的值为3
i = 3.14;			// i 的值为3
double pi = i;		// pi 的值为 3.0
unsigned char c = -1; 	// 假设 char 占8bit， c 的值为255
signed char c2 = 256;	// 假设 char 占8bit, c2 的值是为定义的
```
#### 含有无符号类型的表达式

- 无符号和有符号数混用带来的问题

示例1：
```cpp
unsigned u = 10;
int i = -42;
std::cout << i + i << std::endl;   // 输出 -84
std::cout << u + i << std::endl;   // 如果 int 占 32bit，输出 4294967264
```

- 当一个算术表达式中既有无符号数又有 `int` 值时，那个 `int` 值就会转换成无符号数；
```cpp
unsigned u1 = 42, u2 = 10;
cout << u1 - u2 << endl;
cout << u2 - u1 << endl;
```
示例2：
```cpp
for (int i = 10; i >= 0; --i)
    std::cout << i << std::endl;
// 错误： 变量u永远不会小于0，循环条件一直成立
for (unsigned i = 10; i >= 0; --i)
    std::cout << i << std::endl;
```
这时候可以修改为使用while语句
```cpp
unsigned u = 11; //确定要输出的最大数，从比它大1的数开始
while (u > 0){
    --u;  		 //先减1，这样最后一次迭代时就会输出0
    std::cout << u << std::endl;
}
```
## 2.1.3 字面值常量
一个形如 42 的值被称作**字面值常量** ， 每个字面值常量都对应一种数据类型，字面值常量的形式和值决定了它的数据类型。
#### 2.1.3.1 整型和浮点型字面值

- 整型
```cpp
20		// 十进制
024		// 八进制
0x14	// 	十六进制
```

- 浮点型
```
3.14159		3.14159E0		0.		0e0		.001
```
#### 2.1.3.2 字符和字符串字面值
```cpp
'a'		// 字符字面值
"Hello World!"  // 字符串字面值
```
字符字面值的类型是 `char` ，字符串字面值是字符数组类型 `const char[]`
##### 分行书写
```cpp
//分多行书写的字符串字面值
std::cout << "a really, really long string literal "
             "that spans two lines" << std::endl;
```
##### 转义序列
两类程序员不能直接使用的字符：

- 不可打印（nonprintable）的字符，如退格或其他控制字符，因为他们没有可视的图符；
- 特殊含义的字符（单引号、双引号、问号、反斜线）

这些情况下就需要使用转移序列（escape sequence)
![image.png](https://cdn.nlark.com/yuque/0/2022/png/29691192/1659257452490-f9cda567-51dd-4a7e-9d3c-ed58d7fedddb.png#clientId=u60bc39c5-ee5d-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=218&id=u35a399f2&name=image.png&originHeight=218&originWidth=1288&originalType=binary&ratio=1&rotation=0&showTitle=false&size=118930&status=done&style=none&taskId=u1f3a531d-90e9-4d3b-b113-f05e1e4824e&title=&width=1288)
![image.png](https://cdn.nlark.com/yuque/0/2022/png/29691192/1659257491096-051512e7-c622-470b-8535-ac66ea3e5d98.png#clientId=u60bc39c5-ee5d-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=666&id=uc7f09cd6&name=image.png&originHeight=666&originWidth=1608&originalType=binary&ratio=1&rotation=0&showTitle=false&size=470773&status=done&style=none&taskId=u0a450943-ecfe-4d92-82d5-b0d01407694&title=&width=1608)
#### 2.1.3.3 指定字面值的类型
我们可以通过下表的符号来指定字面值的类型
![image.png](https://cdn.nlark.com/yuque/0/2022/png/29691192/1659257081295-29713eb6-6c15-4167-8aa0-49172aaea9c7.png#clientId=u60bc39c5-ee5d-4&crop=0&crop=0&crop=1&crop=1&id=Gbnrs&name=image.png&originHeight=398&originWidth=835&originalType=binary&ratio=1&rotation=0&showTitle=false&size=131618&status=done&style=none&taskId=u601e42d4-52cd-4f05-a113-1ea92e42b78&title=)
示例：
```cpp
L'a'		// 宽字符型字面值，类型是 wchar_t
u8"hi!"		// utf-8 字符串字面值
42ULL		// 无符号整型字面值，类型是 unsigned long long
1E-3F		// 单精度浮点型字面值，类型是 float
3.14159L	// 扩展精度浮点类型字面值，类型是 long double
```
#### 2.1.3.4 布尔字面值和指针字面值
`true` 和 `false` 是布尔类型的字面值：
```cpp
bool test = false;
```
`nullptr` 是指针字面值。
## 2.1.4 小节练习
#### 练习2.1：类型int、long long 和 short的区别是什么？无符号类型和带符号类型的区别是什么？float和double的区别是什么？

- int、long、long long 和 short 表示整型类型，C语言规定它们表示数的范围 `short ≤ int ≤ long ≤ long long`。其中，数据类型 long long 是在 C11 中新定义的；
- 带符号类型可以表示正数、负数和 0，无符号类型则仅能表示大于等于 0 的值。类型 int、short、long 和 long long 都是带符号的，通过在这些类型名前添加 unsigned 就可以得到无符号类型，例如 unsigned long。类型 unsigned int 可以缩写为 unsigned；
- float 和 double 用于表示浮点数，其中，float 表示单精度浮点数，double 表示双精度浮点数。执行浮点数运算选用 double，这是因为 float 通常精度不够而且双精度浮点数和单精度浮点数的计算代价相差无几。事实上，对于某些机器来说，双精度运算甚至比单精度还快。long double 提供的精度在一般情况下是没有必要的，况且它带来的运算时消耗也不容忽视。
#### 练习2.2：计算按揭贷款时，对于利率、本金和付款分别应选择何种数据类型？说明你的理由。

- 利率（rat）：float，本金（principal）：long long，付款（payment）：long long。
- 利率一般是小数点后保留四位有效数字，float 合适；本金和付款使用最大的带符号整型表示。
#### 练习2.3：读程序写结果
```cpp
#include <iostream>

int main(int argc, char const *argv[])
{
    std::cout << sizeof(unsigned) << std::endl;
    std::cout << sizeof(int) << std::endl;
    std::cout << "**************************" << std::endl;
    
    unsigned u = 10, u2 = 42;
    std::cout << u2 - u << std::endl;
    std::cout << u - u2 << std::endl;
    std::cout << "**************************" << std::endl;
    
    int i = 10, i2 = 42;
    std::cout << i2 - i << std::endl;
    std::cout << i - i2 << std::endl;
    std::cout << i - u << std::endl;
    std::cout << u - i << std::endl;
    
    return 0;
}
```
输出结果：
```cpp
4
4
**************************
32
4294967264
**************************
32
-32
0
0
```
```cpp
unsigned int 占 4 字节
int 占 4 字节
**************************
u2 - u = 42 - 10 = 32
u - u2 = 10 - 42 = unsigned(-32) = 4294967264
分析一：
32 的二进制表示为 0000 0000 0000 0000 0000 0000 0010 0000
-32 的二进制补码表示为 1111 1111 1111 1111 1111 1111 1110 0000
也就是说 -32 的十六进制表示为 FFFF FFE0
若将 FFFF FFE0 转换为 unsigned int 类型，则高位的符号位全部成为了数值位，FFFF FFE0 按无符号数转换成十进制数为 4294967264。
分析二：
把负数转换成无符号数类似于直接给无符号数赋一个负值，结果等于这个负数加上无符号数的模。
unsigned int 占 4 字节，4 字节的无符号数模为 4294967296。
-32 + 4294967296 = 4294967264
**************************
i2 - i = 42 - 10 = 32
i - i2 = 10 - 42 = -32
当一个算术表达式中既有无符号数又有 int 值时，那个 int 值就会转换成无符号数。
i - u = unsigned(10) - 10 = 0
u - i = 10 - unsigned(10) = 0
分析：
有符号数 10 转换成无符号数 10，因为 10 是正数，符号位为 0，故转换成无符号数时，符号位不会对对应无符号数产生副作用。
```
#### 练习2.5：指出下述字面值的数据类型并说明每一组内几种字面值的区别：
**（a）'a',   L'a',   "a"，L"a"**![image.png](https://cdn.nlark.com/yuque/0/2022/png/29691192/1659259754351-8fad19f7-0990-411b-acbf-f61637fd25ad.png#clientId=ue1a24c5b-729b-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=188&id=u40ca3c53&name=image.png&originHeight=188&originWidth=773&originalType=binary&ratio=1&rotation=0&showTitle=false&size=17007&status=done&style=none&taskId=uc791793f-829f-44da-9da5-c6156c0087a&title=&width=773)
**（b) 10，10u，10L， 10uL，012，0xc**
![image.png](https://cdn.nlark.com/yuque/0/2022/png/29691192/1659259823359-17f59c37-6d8d-4344-a503-b93814dbb24b.png#clientId=ue1a24c5b-729b-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=252&id=ud488077f&name=image.png&originHeight=252&originWidth=764&originalType=binary&ratio=1&rotation=0&showTitle=false&size=31654&status=done&style=none&taskId=u2e5e15d0-2ea3-4201-82d4-82763f92a9f&title=&width=764)
**（c) 3.14，3.14f，3.14L**
![image.png](https://cdn.nlark.com/yuque/0/2022/png/29691192/1659259832977-f9228ae7-8e81-4e84-a0c3-03f44c105a1e.png#clientId=ue1a24c5b-729b-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=146&id=u618dbc46&name=image.png&originHeight=146&originWidth=762&originalType=binary&ratio=1&rotation=0&showTitle=false&size=18915&status=done&style=none&taskId=u63c989a5-0325-4b25-9c69-b4a45657e42&title=&width=762)
**（d) 10, 10u，10.，10e-2**
![image.png](https://cdn.nlark.com/yuque/0/2022/png/29691192/1659259848756-2cecdc12-5fe1-4b18-a621-0d68cb0c4452.png#clientId=ue1a24c5b-729b-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=183&id=ucd75cf2f&name=image.png&originHeight=183&originWidth=762&originalType=binary&ratio=1&rotation=0&showTitle=false&size=22541&status=done&style=none&taskId=u5b8e0961-794c-427e-a200-0b6bc1a00c6&title=&width=762)
#### 练习2.6：下面两组定义是否有区别，如果有，请叙述之；
```cpp
// 9 和 7 是十进制数，正确的赋值
int month = 9, day = 7;
// 以 0 开始表示八进制，八进制各位范围是 0 ～ 7，赋值不合法
int month = 09, day = 07;
```
#### 练习2.7：下面字面值表示何种含义？他们各自的数据类型是什么？
![image.png](https://cdn.nlark.com/yuque/0/2022/png/29691192/1659259977265-5d28d1ab-356f-42f2-8aa3-a6e1b6ecad83.png#clientId=ue1a24c5b-729b-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=185&id=ue573d983&name=image.png&originHeight=185&originWidth=765&originalType=binary&ratio=1&rotation=0&showTitle=false&size=28999&status=done&style=none&taskId=u08d27f50-86af-42fd-93ca-d8971e7a9e6&title=&width=765)
#### 练习2.8：利用转义序列写一段程序，要求输出2M，然后转到新一行，修改程序使其输出2，然后输出制表符，在输出M，最后转到新一行；
字符集查询地址：[ASCII](https://www.asciitable.com/)
```cpp
#include <iostream>

int main(int argc, char const *argv[])
{
    // 使用八进制
    std::cout << "-------- Using Oct Output 2M --------" << std::endl;
    std::cout << "\62\115\12";

    std::cout << "-------- output 2 M \n----------" <<std::endl;
    std::cout << "\62";
    std::cout << "\11";
    std::cout << "\115";
    std::cout << "\12";
    return 0;
}
```
# 2.2 变量
## 2.2.1 变量定义
C++变量的定义要指定变量的类型

- 变量：具有类型、具有名称、可操作的存储空间。
- 类型决定了变量所需要的内存空间、布局方式、以及能够表示值的范围。
```cpp
int sum=0,value,//sum、value和unit_sold都是int
        units_sold=0;//sum和units_sold初值为0

Sales_item item;//item的类型是Sales_item

//string 是一种库类型，表示一个可变长的字符序列
std::string book("0-2-1-78345-X");//book通过一个string字面值初始
```
### 初始值

- 在C++中变量的初始化和赋值是有区别的，初始化不是赋值，初始化的含义是创建变量时赋予其一个初始值，而赋值的含义是把对象的当前值擦除，而以一个新值来替代；
### 列表初始化

- 作为C++新标准的一部分，使用花括号来初始化变量得到了全面应用；
```cpp
int units_sold = 0;
int units_sold = {0};//列表初始化
int units_sold{0};//列表初始化 
int units_sold(0);
```

- 如果我们使用列表初始化，且初始值存在丢失信息的风险，则编译器将报错；
```cpp
long double ld = 3.1415926536;
int a{ld},b={ld};//错误：转换未执行，因为存在丢失信息的风险
int c(ld),d=ld;//正确：转换执行，且确实丢失了部分值
```
### 默认初始化

- 如果定义变量没有定义初始值，则变量被赋予默认值。
- 默认值是由变量类型决定的，同时定义变量的位置也会有影响。
- 内置类型：由定义的位置决定，函数体之外初始化为0每个类各自决定其初始化对象的方式；
- 定义在函数体内的局部变量和类中的成员属性是不会被初始化的 （不同编译器的实现可能会不同）， 所以不用试图使用任何方式去访问这些变量。
```cpp
std:::string empty;//empty非现实地初始化一个空串
Sales_item item;//被默认初始化的Sales_item对象
```
## 2.2.2 变量声明和定义的关系

- **声明（declaration）**，使程序知道变量（对象）的存在
- **定义（definition）**，负责创建于名字关联的实体;
- C++是一种静态类型语言。要求在使用某个变量之前必须先声明；
- 如果想声明一个变量而非定义它，就在变量名前添加extern关键字，而且不要显示的初始化；
```cpp
extern int i;	//声明i
int j;		//声明并定义j
extern double pi = 3.1416;	//定义
```
变量能且只能被定义一次，但是可以被多次声明
extern 不是定义, 是引入(声明)在其它源文件中定义的非 static 全局变量
## 2.2.3 标识符

- C++标识符（identifier）由字母、数字和下划线组成，其中必须以字母或下划线开头；
- 标识符的长度没有限制，但对大小写敏感；
- 不能使用保留的关键字；

**命名规则参考：**

- 普通的局部变量和函数参数名使用小驼峰（第一个单词首字母小写，其他单词首字母大写）， 例： `userName`
- 全局变量前加 `g_`, 后面的按小驼峰规则 ， `g_userName`
- 静态变量前加 `s_` , 后面按小驼峰规则， `s_userName`
- 类名使用大驼峰，所有单词的首字母大写 ,  `UserManage`
- 类属性（成员变量）前面加 `m_` ,后面按小驼峰规则  ， `m_userName`
- 常量全部使用大写，多个单词用`_` 分割， `MAX_NUMBER`
## 2.2.4 名字的作用域

- 同一个名字如果出现在程序的不同位置，也可能指向不同的实体；
- C++中大多数作用域都以花括号分隔；
- 名字的有效区域始于名字的声明语句，以声明语句所在的作用域末端为结束。

![image.png](https://cdn.nlark.com/yuque/0/2022/png/29691192/1659370124810-2bdfccca-1ef6-466e-b7ea-0269c52e5601.png#clientId=ub5edd8bf-9d1a-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=526&id=u2ba249de&name=image.png&originHeight=526&originWidth=1382&originalType=binary&ratio=1&rotation=0&showTitle=false&size=94033&status=done&style=none&taskId=u43c113bf-b05b-496a-a768-8573033fdea&title=&width=1382)
如果函数有可能用到某全局变量，则不宜再定义一个同名的局部变量。
![image.png](https://cdn.nlark.com/yuque/0/2022/png/29691192/1659370173234-884a357c-78c8-479b-8710-c1b6072cb889.png#clientId=ub5edd8bf-9d1a-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=1058&id=uc6e72b0f&name=image.png&originHeight=1058&originWidth=1242&originalType=binary&ratio=1&rotation=0&showTitle=false&size=160624&status=done&style=none&taskId=u00984c18-2bc1-43af-b227-aca9d811421&title=&width=1242)
## 2.2.5 小节练习
### 练习2.9：解析下列定义的含义，对于非法的定义，请说明错在何处并将其改正；
```cpp
// (a)
// std::cin >> int input_value;  // Error: variable must be defined before using for input
int input_value;
std::cin >> input_value;

// (b)
// int i = { 3.14 };   // Error: loss information in list initialization
double d = { 3.14 };  // OK
double d2 = { 3 };    // OK

// (c)
// double salary = wage = 9999.99;  // Error
double salary, wage;
salary = wage = 9999.99;

// (d)
int i2 = 3.14;  // OK, `i2` is 3
```
### 练习2.10：下列变量的初值分别是什么？
```cpp
#include <iostream>

std::string global_str;
int global_int;
int main () {
    int local_int;
    std::string local_str;
    std::cout << "global_str = " << global_str << std::endl;
    std::cout << "global_int = " << global_int << std::endl;
    std::cout << "local_str = " << local_str << std::endl;
    std::cout << "local_int = " << local_int << std::endl;
    return 0;
}
```
### 练习2.11：指出下面的语句是声明还是定义：
```cpp
extern int ix = 1024;		// 定义
int iy;		// 声明并定义 iy
extern int iz;		// 声明 iz 而非定义 iz		
```
### 练习2.12：指出下面的名字中哪些是非法的？
```cpp
int double = 3.14;	// 错误，c++关键字 double 不能作为标识符
int _;	// 正确
int catch-22;	// 错误，标识符由数字、字母和下划线组成
int 1_or_2 = 1;	// 错误，标识符必须以字母或下划线开头
double Double = 3.14;	// 正确，标识符长度没有限制，大小写敏感
```
### 练习2.13：下面程序中j的值是多少？
```cpp
int i = 42;
int main()
{
    int i = 100;
    int j = i;
}
//输出j的数字为100
```
### 练习2.14：下面的程序合法吗？如果合法，它将输出什么？
```cpp
#include <iostream>

int main () {
    int i = 100, sum = 0;
    for (int i = 0; i != 10; ++i)
        sum += i;
    std::cout << i << " " << sum << std::endl;

    return 0;
}
//输出的结果是100 45
```
# 2.3 复合类型
符合类型的声明语句是由一个 **基本数据类型** 和紧随其后的一个 **声明符** 列表组成。
## 2.3.1 引用
**引用（reference）**就是为变量（对象）起一个别名

- 定义引用时，把引用和它的初始值绑定在一起，而不是将初始值拷贝给引用;
- 引用本身并不是对象，所以不能定义引用的引用;
- `&` 符号可以紧靠基本类型(int), 也可以紧靠变量名；
```cpp
int ival = 1024;
int &refVal = ival;//refVal指向ival(是ival的另一个名字)
int &refVal2;//报错：引用必须初始化

refVal = 2;//把2给refVal指向的对象，此处即是赋给了ival
int li = refVal;//等同于li=ival

//正确：refVal13绑定到了那个与refVal绑定的对象上，即绑定了ival
int &refVal3 = refVal;
```
**以上说的引用都是左值引用，C++11还有右值引用**
## 2.3.2 指针
**指针（pointer）**对地址的封装，本身就是一个对象

- 定义指针类型的方法是将声明符写成`*d`的形式;
- 如果一条语句中定义了几个指针变量，每个变量前面都必须加上`*`符号;
- 和其他内置类型一样，在块作用域内定义指针如果没有初始化，将拥有一个不确定的值;
```cpp
int *p1, *p2;	// ip1和ip2都是指向int型对象的指针
double dp, *dp2;	//dp2实质性double型对象的指针，dp是double型对象
```
> 指针使用建议：
> 1. 指针定义是可以不初始化，但建议定义时初始化，如果没有想好指向哪个变量，可以初始化为空指针；
> 1. 操作指针时，须确定操作的不是空指针和野指针（无效指针）

### 获取对象的地址

- 指针存放某个对象的地址，要想获取该地址，需要使用 **取地址符** （操作符`&`）：
```cpp
nt ival = 42;
int *p = &ival;//p是指向ival的指针
double *dp = &ival;//错误：类型不匹配
```
### 指针值
指针值（即地址）应属于下列4种状态之一：

1. 指向一个对象
1. 指紧邻对象所占空间的下一个位置
1. 空指针，意味着指针没有指向任何对象
1. 无效指针，也就是上述情况之外的其他值
### 利用指针访问对象
如果指针指向一个对象，则允许使用 **解引用符** （操作符`*` ）来访问对象
```cpp
int ival = 42;
int *p = &ival;
cout << *p;		// 由符号 * 得到指针p所指向的对象，输出 42

*p = 0;			// 由符号 * 得到指针p所指向的对象，即可经由p为变量ival赋值
cout << *p;		// 输出0
```
> 解引用操作仅使用与那些切实指向了某个对象的有效指针；

### 空指针
空指针不指向任何对象，在操作指针之前必须确定为一个非空指针。下列几个生成空指针的方法
```cpp
int *p1 = nullptr;		// 等价于 int *p1 = 0;
int *p2 = 0;			// 直接将 p2初始化为字面常量0
// 需要首先 #include <cstdlib>
int *p3 = NULL;			// 等价于 int *p3 = 0;
```
int 变量直接赋值给指针是错误的操作，即使int变量的值恰好等于0也不行
```cpp
int zero = 0;
p1 = zero; //错误：类型不匹配
```
### 赋值和指针
指针变量的赋值是指将一个地址值赋值给指针变量，从而指向一个新的对象;
### 赋值和指针
指针变量的赋值是指将一个地址值赋值给指针变量，从而指向一个新的对象
```cpp
int i = 42;
int *pi = 0;	// pi被初始化，但没有指向任何对象
int *pi2 = &i;	// pi2 被初始化，存有i的地址
int *pi3;		// 如果 pi3 定义于块内，则pi3的值是无法确定的

pi3 = pi2;		// pi3和pi2指向同一个对象
pi2 = 0;		// 现在pi2不执行任何对象
```
区分对指针指向对象的赋值
```cpp
*pi = 0;	// ival 的值被改变，指针pi并没有改变
```
### 其他指针操作
只要指针拥有一个合法值，就能将它用在条件表达式中。如果指针的值是 0， 条件取 `false`，任何非0的指针对应的条件值都是 `true`
```cpp
int ival = 1024;	
int *pi = 0;	// pi 合法，是一个空指针
int *pi2 = &ival;	// pi2是一个合法的指针，存放着ival的地址
if (pi)			// pi 的值是0，条件的值为false
    // ...
if (pi2)		// pi2 指向ival，它的值不为0， 条件的值是true
    // ...
```
> 对于两个类型相同的合法指针，还可以用相等操作符 （`==`）或不相等操作符 （`!=`）来比较它们，比较的结果是布尔类型。

### void* 指针

- 纯粹的地址封装，与类型无关。可以用于存放任意对象的地址
```cpp
double obj = 3.14, *pd = &obj; // 正确： void* 能存放任意类型对象的地址
void *pv = &obj;	// obj 可以是任意类型的对象
pv = pd;			// pv 可以存放任意类型的指针
```
## 2.3.3 理解复合类型的声明
```cpp
int i = 42;     //i是一个int型的数
int *p;			//p是int型的指针
int *&r = p;	//r是一个对指针p的引用

r = &i;			//r是一个指针引用，因此给r赋值&i就是令p指向i
*r = 0;			//解引用r,就是解引用指针p,将p指向的变量i的值改为0
```
> Tip: 面对一条比较复杂的指针或引用的声明语句时，从右向左读有助于弄清楚它的真实含义。

### 定义多个变量
```cpp
int* p1, p2; //p1是指向int的指针，p2是int
```
涉及指针或引用的两种写法
```cpp
int *p1, *p2 //p1和p2都是int型指针
int *p1;
int *p2;
```
### 指向指针的指针

- 通过`*`的个数可以区分指针的级别
```cpp
int ival = 1024;
int *pi = &ival;
int **ppi = &pi;//ppi指向一个int型的指针
```
![image.png](https://cdn.nlark.com/yuque/0/2022/png/29691192/1659629854717-8e375745-3ed2-43dd-811c-9bb081512221.png#clientId=u6c9d95a5-ebca-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=64&id=ua6513df1&name=image.png&originHeight=65&originWidth=385&originalType=binary&ratio=1&rotation=0&showTitle=false&size=2983&status=done&style=none&taskId=u4bfb29be-297b-4ede-8b8d-332f0216e53&title=&width=379.5)
### 指向指针的引用

- 通过`*`的个数可以区分指针的级别
```cpp
int i = 1024;
int *p;
int *&r = p; //r是一个对指针p的引用

r = &i;//r引用了一个指针，就是令p指向i
*r = 0;//解引用r得到i，也就是p指向的对象，将i的值改为0
```
## 2.3.4 小结练习
### 练习2.15：下面哪个定义不合法？为什么？
```cpp
#include <iostream>

int main () {
    // 正确，隐式的将 1.01 转换成 1
    int ival= 1.01;
    // 错误，除 2.4.1 节（第 55 页）和 15.2.3 节（第 534 页）将
    // 要介绍的两种例外情况，引用的类型都要和与之绑定的对象严格匹
    // 配。而且，引用只能绑定在对象上，而不能与字面值或某个表达式的
    // 计算结果绑定在一起，相关原因将在 2.4.1 节详述
    int &rval1 = 1.01;
    // 正确
    int &rval2 = ival;
    // 错误，引用必须被初始化,且初始值必须是一个对象
    int &rval3;

    return 0;
}
```
### 练习2.16：考察下面的所有赋值然后回答哪些不合法？为什么？它们执行了什么操作？
```cpp
#include <iostream>

int main () {
    int i = 0, &r1 = i;
    double d = 0, &r2 = d;
    // 正确
    r2 = 3.14159;
    std::cout << r2 << "\n";
    // 正确，发送自动类型转换
    r2 = r1;
    std::cout << r2 << '\n';
    // 正确，发送自动类型转换
    i = r2;
    std::cout << i << std::endl;
    // 正确，发送自动类型转换
    r1 = d;
    std::cout << r1 << std::endl;

    return 0;
}
```
### 练习2.17：执行下面你的代码段输出什么结果？
```cpp
#include <iostream>

int main(int argc, char const *argv[])
{
    int i, &ri = i;
    i = 5;
    ri = 10;
    std::cout << i <<" " << ri << std::endl; 
    return 0;
}
//输出结果
10, 10
```
### 练习2.18：编写代码分别更改指针的值和指针所指对象的值
```cpp
#include <iostream>

int main(int argc, char const *argv[])
{   
    int ival = 42, *p = &ival;
    std::cout << "ival = " << ival << " " << "*p = " << *p << std::endl;
    *p = 24;
    std::cout << "ival = " << ival << " " << "*p = " << *p << std::endl;
    ival = 25;
    std::cout << "ival = " << ival << " " << "*p = " << *p << std::endl;

    return 0;
}

/*输出
ival = 42 *p = 42
ival = 24 *p = 24
ival = 25 *p = 25
*/
```
### 练习2.19：说明指针和引用的主要区别

- **引用（reference）**为对象起了另外一个名字，引用类型引用（refers to）另外一种类型。
- **指针（pointer）**是"指向（point to）"另外一种类型的复合类型。与引用类似，指针也实现了对其他对象的间接访问。然而指针与引用相比又有很多不同点。
   - 指针本身就是一个对象，允许对指针赋值和拷贝，而且在指针的生命周期内它可以先后指向几个不同的对象；
   - 指针无须在定义时赋初值；
   - 因为引用不是对象，没有实际地址，所以不能定义指向引用的指针；
   - 除特殊情况，其他所有指针的类型都要和它所指向的对象严格匹配；
### 练习2.20：请叙述下面代码的作用
```cpp
#include <iostream>

int main () {
    int i = 42;
    int *p1 = &i;
    *p1 = *p1 * *p1;
    std::cout << "i = " << i << " " << "*p1 = " << *p1;

    return 0;
}
/*输出
i = 1764 *p1 = 1764
*/
```
### 练习2.21：请解释下述定义，这些定义哪些是非法的吗？如果有，为什么？
```cpp
int i = 0;
double *dp = &i;	// 错误，指针的类型都要和它所指向的对象严格匹配
int *ip = i;		// 错误，忘记取地址符 &
int *p = &i;		// 正确
```
### 练习2.22：假设`p`是一个int的指针，请说明下述代码的含义

- `if (p) `表示指针 p 不为空；
- `if (*p) `表示指针所指向的对象不为空，或者不等于0 
### 练习2.23：给定指针p，你能知道它是否指向一个合法对象吗？如果能，请说明判断思路；如果不能，也请说明原因；

- 不能，因为维护指针的构成对象需要的成本比较高；
- C++的智能指针能够判断对象是否合法；
### 练习2.24：在下面这段代码中为什么`p`合法而`lp`？
```cpp
int main() {
  int i = 42;
  void *p = &i;   // OK, a `void *` pointer can point to any type
  //long *lp = &i;  // Error, a `long *` pointer can not point to `int *`

  return 0;
}
```
### 练习2.25：说明下列变量的类型和值
```cpp
#include <iostream>

int main() {
    {
        int* ip, i, &r = i;  // `ip` is `int *`, `i` is `int`, `r` is `int &`
        std::cout << "(a)" << std::endl;
        std::cout << "ip\t" << typeid(ip).name() << std::endl;
        std::cout << "i\t" << typeid(i).name() << std::endl;
        std::cout << "r\t" << typeid(r).name() << std::endl;
        // Note that `typeid` will lose the `const` qualifier and reference
    }
    {
        int i, *ip = 0;  // `i` is `int`, `ip` is `int *`
        std::cout << "(b)" << std::endl;
        std::cout << "i\t" << typeid(i).name() << std::endl;
        std::cout << "ip\t" << typeid(ip).name() << std::endl;
    }
    {
        int* ip, ip2;  // `ip` is `int *`, `ip2` is `int`
        std::cout << "(c)" << std::endl;
        std::cout << "ip\t" << typeid(ip).name() << std::endl;
        std::cout << "ip2\t" << typeid(ip2).name() << std::endl;
    }

    return 0;
}
```
# 2.4. const 限定符

- **使用**`**const**`**对变量的类型加以限定，变量的值不能被改变**
```cpp
const int bufSize = 512; //输入缓冲区大小
bufSize = 512; //错误：试图向const对象写值
```

- `**const**`** 用于定义一个不能改变的变量, 所以定义时就必须初始化**
```cpp
cont int bufSize = 512;		//用字面值常量初始化
cont int i = get_size();	//用函数返回值初始化， 运行时初始化
int j = 10;
cont int k = j;				//用其他变量初始化
```

- `**const**`** 定义的变量只对本文件可见，要使其他文件也可见需使用 **`**extern**`
```cpp
//file_1.cc定义并初始化了一个常量，该常量能被其他文件访问
extern const int bufSize = fcn();
//file_1.h头文件
extern const int bufSize;
```
## 2.4.1 const的引用

- **对常量的引用（reference to const）**
```cpp
const int ci = 1024;
const int &r1 = ci; //正确：引用及其绑定的对象都是常量
r1 = 42;//错误，相当于c1=42，试图修改常量
int &r2 = ci;//错误：ci是常量，存在通过r2改变ci（const）的风险


int i = 42;
const int &r1 = i; //正确：i依然可以通过其他途径修改
const int &r2 = 42;
const int &r3 = r1*2;
int &r4 = r1*2; //错误：不能通过一个非常量的引用指向一个常量

int i = 42;
const int &r1 = i; //正确：i依然可以通过其他途径修改
const int &r2 = 42;
const int &r3 = r1*2;
int &r4 = r1*2; //错误：不能通过一个非常量的引用指向一个常量
```
组合关系:

|  | `int i` | `cont int i` |
| --- | --- | --- |
| `int &r` | ✔ | ❌ |
| `cont int &r` | ✔ | ✔ |

## 2.4.2 指针和const

- **指向常量的指针**
```cpp
const double pi = 3.14;
double *ptr = &pi; //错误：存在通过ptr指针修改pi的风险
const double * cptr = &pi;
*cptr = 42; //错误

double dval = 3.14;
cptr = &dval; //正确：但不能通过cptr修改dval的值
```
组合关系:

|  | `int i` | `cont int i` |
| --- | --- | --- |
| `int *p` | ✔ | ❌ |
| `cont int *p` | ✔ | ✔ |

- **const指针：**指针是对象，也可以限定为常量（必须初始化）
   - 把`*`放在const之前，说明指针是一个常量
   - 不变的是指针本身的值，而非指向的那个值
```cpp
int errNumb = 0;
int *const curErr = &errNumb;
const double pi = 3.14159;
const double *const pip = &pi;//指向常量的常量指针

*pi = 2.71;//错误： 试图修改常量pi

if(*curErr){
errorHandler();
*curErr = 0; //正确：试图修改变量errNumb
}
```
## 2.4.3 顶层const

   - 顶层const：表示指针/变量本身是一个常量
   - 底层const：表示指针所指向的对象是一个const
```cpp
int i = 0;
int *const p1 = &i; //顶层
const int ci = 42; //顶层
const int *p2 = &ci;//底层
const int *const p3 = p2;//（左：底层 ）， （右：顶层）

i = ci;//正确
p2 = p3;//正确

int *p = p3;//错误：存在通过*p修改*p3（const）的风险
p2 = &i;  //正确：只是不能通过p2修改i而已
int &r = ci; //错误：存在通过r修改ci（const)的风险
const int &r2 = i; //正确：只是不能通过r2修改i而已
```
## 2.4.4 constexpr和常量表达式 

- **常量表达式（const expression）**是指：值不会改变并且在编译过程就能得到计算结果的表达式。
```cpp
const int max_files = 20; //是
const int limit = max_files +1; //是
int staff_size = 27; //不是
const int sz = get_size(); //不是
```

- **constexpr变量**
   - C++11标准规定，允许将变量声明为constexpr类型，以便由编译器来验证变量的值是否是一个常量表达式。
      - 一定是一个常量
      - 必须用常量表达式初始化
   - 需要在编译时就得到计算，声明constexpr时用到的类型必须显而易见，容易得到（称为：字面值类型）。
   - 自定义类型（例如：Sales_item）、IO库、string等类型不能被定义为constexpr
```cpp
constexpr int mf = 20;
constexpr int limit = mf +1;
constexpr int sz = size(); //只有当size是一个constexpr函数时才正确
```

   - 指针和constexpr
      - 限定符仅对指针有效，对指针所指的对象无关
```cpp
constexpr int *np = nullptr; //常量指针
int j = 0;
constexpr int i = 42;
… ....
//i和j必须定义在函数之外
constexpr const int *p = &i; //p是常量指针，指向常量
constexpr int *p1 = &j; //p1是常量指针，指向变量j
```
## 2.4.5 小节练习
### 练习2.26：下面哪些句子是合法的？如果不合法，说明为什么？
```cpp
//(a)不合法：const对象必须初始化
const int buf;
//(b)合法
int cnt = 0;
//(c)合法
const int sz = cnt;
//(d)不合法，const对象不能修改
++cnt;
++sz;
```
### 练习2.27：下面哪些初始化是合法的？说明原因
![image.png](https://cdn.nlark.com/yuque/0/2022/png/29691192/1659863541960-f2227a12-16f9-4671-946a-c36845bee80b.png#clientId=u6c9d95a5-ebca-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=73&id=u10b7efcb&name=image.png&originHeight=85&originWidth=524&originalType=binary&ratio=1&rotation=0&showTitle=false&size=32266&status=done&style=none&taskId=u103e7d56-6da8-4502-9d51-f135b8fa642&title=&width=450)
```cpp
(a): 非法，非常量引用r不能引用字面值常量0；
(b): 合法，p2常量指针，p2永远指向变量i2；
(c): 合法，i是常量，r是一个常量引用；
(d): 合法，p3常量指针，p3永远指向变量i2；同时，p3指向的是常量，无法通过p3改变所指对象的值；
(e): 合法，p1指向一个常量，无法通过p1修改其所指向的对象的值；
(f): 非法，引用本身不是对象，因此不能让引用恒定不变；
(g): 合法，i2是一个常量，r是一个常量引用；
```
### 练习2.28：说明下面的这些定义是什么意思，挑出其中不合法的
![image.png](https://cdn.nlark.com/yuque/0/2022/png/29691192/1659864068098-72fc73f3-ade0-44ae-a5c6-823397199162.png#clientId=u6c9d95a5-ebca-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=61&id=u2ad80393&name=image.png&originHeight=104&originWidth=692&originalType=binary&ratio=1&rotation=0&showTitle=false&size=36972&status=done&style=none&taskId=u8945cdae-1580-4e95-b434-177611ef5e6&title=&width=407)
```cpp
(a): 非法，cp是一个常量指针，所以需要被初始化；
(b): 非法，p2是一个常量指针，所以需要被初始化；
(c): 非法，ic是一个常量，需要被初始化；
(d): 非法，p3常量指针，需要被初始化；
(e): 合法，但是p没有指向任何实际的对象；
```
### 练习2.29：假设已经有上一节定义的变量，下面哪些语句是合法的？说明原因
![image.png](https://cdn.nlark.com/yuque/0/2022/png/29691192/1659864337317-4a010dfe-5228-4224-bcfd-e148b19b8b1d.png#clientId=u6c9d95a5-ebca-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=87&id=ub83f1daa&name=image.png&originHeight=97&originWidth=536&originalType=binary&ratio=1&rotation=0&showTitle=false&size=24909&status=done&style=none&taskId=ue6fa67c1-2164-4bba-b84d-b9804a08890&title=&width=478)
```cpp
（a）是合法的，常量 ic 的值赋给了非常量 i。

（b）是非法的，普通指针 p1 指向了一个常量，从语法上说，p1 的值可以随意改变，显然是不合理的。因为 p1 改变了，p1 所指对象因该也同时改变了，但是 p1 所指对象是一个常量，不能被修改。

（c）是非法的，普通指针 p1 指向了一个常量，错误情况与上一条类似。

（d）是非法的，p3 是一个常量指针，不能被赋值。

（e）是非法的，p2 是一个常量指针，不能被赋值。

（f）是非法的，ic 是一个常量，不能被赋值。
```
### 练习2.30：下面的语句，说明对象是顶层const还是底层const?
```cpp
cost int v2 = 0; //顶层
int v1 = v2;
int *p1 = &v1, &r1 = v1;
const int *p2 = &v2, *const p3 = &i, &r2 = v2;
//输出：
//v2和p3是顶层const，分别表示一个int常量和一个int常量指针；
//p2和r2是底层const，分别表示它们所指（引用）的对象是常量；
```
### 练习2.31：假设已有上一节的变量声明，下面哪些句子是合法的？请说明顶层const和底层const在每个例子中有何体现?
> 在执行拷贝操作时，顶层 const 和底层 const 区别明显。其中，顶层 const 不受影响，这是因为拷贝操作并不会改变被拷贝对象的值。底层 const 的限制则不容忽视，拷入和拷出的对象必须具有相同的底层 const 资格，或者两个对象的数据类型必须能够转换。一般说来，非常量可以转换成常量，反之则不行。

```cpp
r1 = v2; 是合法的，r1 是一个非常量引用，v2 是一个常量（顶层 const），把 v2 的值拷贝给 r1 不会对 v2 有任何影响。

p1 = p2; 是非法的，p1 是普通指针，指向的对象可以是任意值，p2 是指向常量的指针（底层 const），令 p1 指向 p2 所指的内容，有可能错误地通过 p1 改变 p2 所指常量的值。

p2 = p1; 是合法的，与上一条语句相反，p2 可以指向一个非常量，只不过我们不会通过 p2 更改它所指的值。

p1 = p3; 是非法的，p3 包含底层 const 定义（p3 所指的对象是常量），不能把 p3 的值赋给普通指针。

p2 = p3; 是合法的，p2 和 p3 包含相同的底层 const，p3 的顶层 const 则可以忽略不计。
```
### 练习2.32：下面的代码是否合法？如果非法，请设法将其修改正确
```cpp
//原题
int null = 0, *p = null;
//修改为：
int null = 0, *p = &null;
//或者修改为：
int null = 0, *p = nullptr;
```
# 2.5 处理类型
## 2.5.1 类型别名
> 提高代码的可读性

### typedef 和 using

- 传统的方法是使用 `typedef` 关键字定义类型别名；
- C++11 提供了一种新的方式，使用 `using`
```cpp
typedef double wages; 
typedef wages base, *p; //base是double的同义词，p是double *的同义词

//数组的别名
typedef int arrT[10];		//arrT是一个类型别名，他表示的类型是含有10个整数的数组
using arrT = int[10];		//和上面的等价

using SI = Sales_item; //C++11,别名声明
wages hourly, weekly; 
SI item; //等价于Sales_item item
```
> 这里的 `using` 要和 `using namespace std;` 中的 `using` 区分开。后者是表示引入命名空间，类似于java和python的导包操作

### 指针、常量和类型别名
```cpp
typedef char *pstring;
const pstring cstr = 0; //指向char的常量指针
const pstring *ps; //ps是指针变量，它的对象是指向char的常量指针

const char *cstr = 0; //是对const pstring cstr =0 的错误理解
```
> `const pstring` 中 `const` 是对 `pstring` 的修饰，而 `pstring` 是一个 `char*` 类型，因此 `const petring` 是指向 char的 [常量指针](#const point) ，而并不是指向常量字符的指针

## 2.5.2 auto类型说明符
C++11  `auto` 类型说明符可以让编译器分析表达式所属的类型。
```cpp
int val1 = 1, val2 = 3;
auto val = val1 + val2;		//编译器可以自动推出val为int类型
auto i = 0, *p = &i;		//正确，编译器通过字面值推出i为int,p为int*
auto sz = 0; pi = 3.14;		//错误，编译器无法推出类型，sz，pi类型不一致无法统一
```
#### 复合类型、常量和auto

-  当使用引用类型推导类型是，`auto`推导的类型是引用指向变量的实际类型 
- `auto`会忽略掉顶层const, 同时底层const则会保留下来 

如果希望推断出的auto类型是一个顶层const，需要明确指出： 
指定引用类型  
```cpp
int i = 0, &r = i;
auto a = r; //a是int型

const int ci = i, &cr = ci;
auto b = ci; //b是int型，ci的顶层const被忽略
auto c = cr; //c是int型，ci的顶层const被忽略
auto d = &i; //d是整形指针，整数的地址就是指向整形的指针
auto e = &ci; //e是指向整数常量的指针（底层const没有被忽略）

const auto f = ci; //auto的推演类型为 int，f是const int

auto &g = ci; //g是一个整形常量引用，绑定到ci，（底层const没有被忽略）

auto &h = 42; //错误：不能为非常量引用绑定字面值
const auto &j =42; //正确：可以为常量引用绑定字面值

auto k = ci, &l = i; 
auto &m = ci, *p = &ci;
auto &n = i, *p2 = &ci; //错误：类型不一致
```
> auto 使用建议：
> 使用auto声明变量一定要做到心里有数，你知道编译器会推断出的什么样的类型 
> 通常使用auto是对于一些类型名比较复杂的变量，使用auto写起来更方便

## 2.5.3 decltype类型指示符
C++11  `decltype` 可以不执行表达式，编译器自动推断出表达式的返回值类型
```cpp
decltype(f()) sum = x;		//sum的类型和f()的返回类型一样
```
通过 `f()` 推断出返回类型，但是并不会执行 `f()`
#### decltype 和const

- `decltype`处理顶层 consth和引用的方式和auto有点不同，如果 decltype使用的表达式是一个变量，则decltype返回该变量的类型（包括顶层const和引用在内）
```cpp
const int ci = 0, &cj = ci;
decltype(ci) x = 0; // x的类型是const int
decltype(cj) y = x; // y的类型是const int &
decltype(cj) z; //错误：z是一个引用，必须初始化
```
#### decltype 和引用
```cpp
int i = 42, *p = &i, &r = i;
decltype(r+0) b; //正确：b为int型

//注意：下面的*不是出现在声明中，而是表达式中的解引用运算符
decltype(*p) c; //错误：解引用表达式，c的类型为引用，需要初始化
```
> `r` 是引用  `decltype(r)` 是引用，但是 `r + 0` 是一个int型数据
> 解引用指针得到的是指针所指的对象，，因此 `decltype(*p)` 是 `int&`

- 变量如果是加上括号， decltype的结果将是引用 `decltype((variable))`
```cpp
decltype((i)) d; //错误：d是int&类型,必须初始化
decltype(((i))) d1 = i; //正确：d1是int&类型，绑定为了i
decltype(i) e; //正确：e是一个（未初始化的）int
```
## 2.5.4 小节练习
#### 练习2.33：利用本节定义的变量，判断下列语句的运行结果
> 同2.34结果

#### 练习2.34：编写代码证明2.33练习的结果
```cpp
#include <iostream>
int main(int argc, char const *argv[])
{
    int i = 0, &r = i;
    auto a = r;
    const int ci = i, &cr = ci;
    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;
    auto &g = ci;
    std::cout << a << " " << b << " " << c << " " << d << " " << e << " " << g << std::endl;
    a = 42;
    b = 42;
    c = 42;
    // d = 42; //非法，d是整型指针
    // e = 42; //非法，e指向整型常量的指针
    // g = 42; //非法，g绑定整型常量
    std::cout << a << " " << b << " " << c << " " << d << " " << e << " " << g << std::endl;

    return 0;
}
/*输出
0 0 0x16f91f38c 0x16f91f378 0
42 42 42 0x16f91f38c 0x16f91f378 0
*/
```
#### 练习2.35：判断下列定义推断出的类型是什么，编写程序验证：
```cpp
#include <iostream>
#include <typeinfo>

int main()
{
    const int i = 42;
    auto j = i;
    const auto &k = i;
    auto *p = &i;
    const auto j2 = i, &k2 = i;
    std::cout << typeid(i).name() << std::endl;  // i
    std::cout << typeid(j).name() << std::endl;  // i
    std::cout << typeid(k).name() << std::endl;  // i
    std::cout << typeid(p).name() << std::endl;  // PKi
    std::cout << typeid(j2).name() << std::endl; // i
    std::cout << typeid(k2).name() << std::endl; // i

    std::cout << std::endl;
    std::cout << std::boolalpha; // 接下来的输出把 bool 值显示成 true/false

    std::cout << "i and j have same type? "
              << std::is_same<decltype(i), decltype(j)>::value << std::endl;
    std::cout << "i and k have same type? "
              << std::is_same<decltype(i), decltype(k)>::value << std::endl;
    std::cout << "i and j2 have same type? "
              << std::is_same<decltype(i), decltype(j2)>::value << std::endl;
    std::cout << "j and j2 have same type? "
              << std::is_same<decltype(j), decltype(j2)>::value << std::endl;
    std::cout << "k and k2 have same type? "
              << std::is_same<decltype(k), decltype(k2)>::value << std::endl;

    return 0;
}
```
输出结果：

- i is const int
- j is int
- k is const int &
- p is const int *
- j2 is const int
- k2 is const int &
#### 练习2.36：关于下面的代码，指出每个变量的类型以及程序结束时它们各自的值；
```cpp
#include <iostream>
#include <typeinfo>

int main() {
    int a = 3, b = 4;
    decltype(a) c = a;
    decltype((b)) d = a;
    ++c;
    ++d;
    std::cout << typeid(c).name() << std::endl; // int
    std::cout << typeid(d).name() << std::endl; // int &
    std::cout << c << std::endl; // 4
    std::cout << d << std::endl; // 4

    return 0;
}
```
#### 练习2.37：赋值是会产生引用的一类典型表达式，引用的类型就是左值的类型。也就是说如果 i 是 int，则表达式 i=x的类型是int&，根据这个指出下面代码每个变量的类型和值；
decltype 的参数既可以是普通变量，也可以是一个表达式。当参数是普通变量时，推断出的类型就是该变量的类型；当参数是表达式时，推断出的类型是引用
_c 的类型是 int，值为 3；表达式 a = b 作为decltype 的参数，编译器分析表达式并得到它的类型作为 d 的推断类型，但是不实际计算该表达式，所以 a 的值不发生改变，仍然是 3；d 的类型是 int &，d 是 a 的别名，值是 3；b 的值一直没有发生改变，为 4。_
#### 练习2.38：说明由 decltype和 auto指定类型有何区别，请举出一个例子，分别表示指定类型一样和不一样；
auto 和 decltype 的区别主要有三方面：

1. auto 类型说明符用编译器计算变量的初始值来推断其类型，而 decltype 虽然也让编译器分析表达式并得到它的类型，但是不实际计算表达式的值。
1. 编译器推断出来的 auto 类型有时候和初始值的类型并不完全一样，编译器会适当地改变结果类型使其更符合初始化规则。例如，auto 一般会忽略掉顶层 const，而把底层 const 保留下来。与之相反，decltype 会保留变量的顶层 const。
1. 与 auto 不同，decltype 的结果类型与表达式密切相关，如果变量名加上了一对括号，则得到的类型与不加括号时会有不同。如果 decltype 使用的是一个不加括号的变量，则得到的结果就是该变量的类型；如果给变量加上了一层或多层括号，则编译器将推断得到引用类型。
```cpp
#include <iostream>
#include <typeinfo>

int main() {
    int a = 3;
    auto c1 = a;
    decltype(a) c2 = a;
    decltype((a)) c3 = a;

    const int d = 5;
    auto f1 = d;
    decltype(d) f2 = d;

    std::cout << typeid(c1).name() << std::endl;	// int
    std::cout << typeid(c2).name() << std::endl;	// int
    std::cout << typeid(c3).name() << std::endl;	// int &
    std::cout << typeid(f1).name() << std::endl;	// int
    std::cout << typeid(f2).name() << std::endl;	// const int

    c1++;
    c2++;
    c3++;
    f1++;
    // f2++;    // 错误：f2 是整型常量，不能执行自增操作
    std::cout << a << " " << c1 << " " << c2 << " " << c3 << " " << f1
              << " " << f2 << std::endl;

    return 0;
}
```
# 2.6 自定义数据结构

- 这里的自定义数据结构就是指类类型的数据，在C++中定义类的关键字有`class` 和 `struct`
- `class` 和 `struct` 在功能上是完全一样的，两者唯一的不同是默认的权限不同
- `class`默认的权限是私有的(private), 而 `struct` 是公有的(public)
```cpp
class ClassName{
	//属性
	//方法
};

struct ClassName{
	//属性
	//方法
};
```
_注意：c语言中的结构体是不能有方法（函数）_
## 2.6.1 定义Sales_data类型
```cpp
struct Sales_data{
        std::string bookNo;
        unsigned units_sold = 0; //C++ 11
        double revenue = 0.0;
};//类定义的最后需要加上分号
```
> 数据成员定义了类的对象的具体内容，每个对象有自己的一份拷贝。

## 2.6.2 使用Sales_data类
```cpp
#include <iostream>
#include <string>
#include "Sales_data.h"
int main(){
    Sales_data data1, data2;
    double price = 0;  // 书的单价, 用于计算总收入
    
    // 读取第1条交易记录: ISBN, number of books sold, price per book
    std::cin >> data1.bookNo >> data1.units_sold >> price;
    // calculate total revenue from price and units_sold
    data1.revenue = data1.units_sold * price;
    
    // 读取第2条交易记录:
    std::cin >> data2.bookNo >> data2.units_sold >> price;
    data2.revenue = data2.units_sold * price;
    
    if (data1.bookNo == data2.bookNo) {
        unsigned totalCnt = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;
    
        // print: ISBN, total sold, total revenue, average price per book
        std::cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
        if (totalCnt != 0)	std::cout << totalRevenue/totalCnt << std::endl;
        else std::cout  << "(no sales)" << std::endl;
    
        return 0;  // indicate success
    } else {  // transactions weren't for the same ISBN
        std::cerr << "Data must refer to the same ISBN" << std::endl;
        return -1; // indicate failure
    }
}
```
## 2.6.3 编写自己的头文件
![image.png](https://cdn.nlark.com/yuque/0/2022/png/29691192/1659889091718-d9d2aad0-35dc-4d10-9800-4fd859247faa.png#clientId=u2732a248-72fe-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=224&id=ud4578410&name=image.png&originHeight=448&originWidth=984&originalType=binary&ratio=1&rotation=0&showTitle=false&size=66986&status=done&style=none&taskId=uaafeb40d-aa28-4a91-9e50-7fe2a9865d6&title=&width=492)
## 2.6.4 小节练习
#### 练习2.39：编译下面的程序观察其运行结果，注意，如果忘记写类定义体后面的分号会发生什么情况？记录下相关信息；
```cpp
#include <iostream>

struct Foo { /* 此处为空 */} // 注意：没有分号

int main(int argc, char const *argv[])
{
    return 0;
}
```
输出：
```bash
2.39.cpp:11:33: error: expected ';' after struct
```
#### 练习2.40：根据自己的理解写出Sales_data类；
```cpp
#ifndef SALESDATA_H
// we're here only if SALESDATA_H has not yet been defined
#define SALESDATA_H

// Definition of Sales_data class and related functions goes here
#include <iostream>
#include <string>

// 头文件不应包含 using 声明
// using namespace std;

class Sales_data {
    // 友元函数
    friend std::istream &operator>>(std::istream &, Sales_data &);
    
    // 友元函数
    friend std::ostream &operator<<(std::ostream &, const Sales_data &);
    
    // 友元函数
    friend bool operator<(const Sales_data &, const Sales_data &);
    
    // 友元函数
    friend bool operator==(const Sales_data &, const Sales_data &);
    
    public:     // 构造函数的 3 种形式
    Sales_data() = default;
    
    Sales_data(const std::string &book) : bookNo(book) {}
    
    Sales_data(std::istream &is) { is >> *this; }
    
    Sales_data &operator+=(const Sales_data &);
    
    std::string isbn() const { return bookNo; }
    
    private:
    std::string bookNo;         // 书籍编号，隐式初始化为空串
    unsigned units_sold = 0;    // 销售量，显式初始化为 0
    double sellingprice = 0.0;  // 原始价格，显式初始化为 0.0
    double saleprice = 0.0;     // 实售价格，显式初始化为 0.0
    double discount = 0.0;      // 折扣，显式初始化为 0.0
};

inline bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() == rhs.isbn();
}

Sales_data operator+(const Sales_data &, const Sales_data &);

inline bool operator==(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.units_sold == rhs.units_sold &&
        lhs.sellingprice == rhs.sellingprice &&
        lhs.saleprice == rhs.saleprice &&
        lhs.isbn() == rhs.isbn();
}

inline bool operator!=(const Sales_data &lhs, const Sales_data &rhs) {
    return !(lhs == rhs);   // 基于运算符 == 给出 != 的定义
}

Sales_data &Sales_data::operator+=(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    saleprice = (rhs.saleprice * rhs.units_sold + saleprice * units_sold)
        / (rhs.units_sold + units_sold);
    if (sellingprice != 0)
        discount = saleprice / sellingprice;
    return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data ret(lhs);    // 把 lhs 的内容拷贝到临时变量 ret 中，这种做法便于运算
    ret += rhs;             // 把 rhs 的内容加入其中
    return ret;             // 返回 ret
}

std::istream &operator>>(std::istream &in, Sales_data &s) {
    in >> s.bookNo >> s.units_sold >> s.sellingprice >> s.saleprice;
    if (in && s.sellingprice != 0)
        s.discount = s.saleprice / s.sellingprice;
    else
        s = Sales_data();   // 输入错误，重置输入的数据
    return in;
}

std::ostream &operator<<(std::ostream &out, const Sales_data &s) {
    out << s.isbn() << " " << s.units_sold << " "
        << s.sellingprice << " " << s.saleprice << " " << s.discount;
    return out;
}

#endif
```
