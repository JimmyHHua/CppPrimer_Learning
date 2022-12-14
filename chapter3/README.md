# 3.1 命名空间的using声明
- 之前输入和输出都是写成 `std::cin` , `std::cout` , 我们可以在使用前使用 `using` 声明
```cpp
#include <iostream>

using std::cin;

int main()
{
    int i;
    cin >> i;		
    cout << i;		//错误，只声明了 cin	
    std::cout << i;
    
    return 0;
}
```

- 每个名字都需要独立的using 声明
```cpp
#include <iostream>

// using declarations for names from the standard library
using std::cin
using std::cout; 
using std::endl;

int main()
{
cout << "Enter two numbers:" << endl;

int v1, v2;
cin >> v1 >> v2;

cout << "The sum of " << v1 << " and " << v2
     << " is " << v1 + v2 << endl;

return 0;
}
```

- 实际更常见的做法是使用 `using namespace std;` 把整个命名空间都引入，这样std命名空间下的成员都可以使用了。
- **注意：**头文件中尽量不要引入整个命名空间，因为当在其他文件包含头文件实际是将这个头文件中的内容赋值到该文件中，这样可能会和自己写的一些类名冲突。
# 3.2 标准库类型string

- 长度可变的字符序列，需要包含`string`头文件；
## 3.2.1 定义和初始化string对象
```cpp
#include <iostream>
#include <string>
using std::string;
int main()
{
string s1; //空字符串
string s2 = s1; //副本，等价于 s2(s1)
string s3 = "hiya"; //副本，等价于 s3("hiya")
string s4(10,'c'); //cccccccccc

return 0;
}
```
## 3.2.2 string对象上的操作
![image.png](https://cdn.nlark.com/yuque/0/2022/png/29691192/1662796572407-08f80956-5f97-4bbe-8cc1-5eb47b20b111.png#clientId=u5f1c59d0-a2af-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=465&id=yG6pu&margin=%5Bobject%20Object%5D&name=image.png&originHeight=930&originWidth=1016&originalType=binary&ratio=1&rotation=0&showTitle=false&size=131218&status=done&taskId=u9926a870-0c59-4061-9485-43dad830cb0&title=&width=508)
```cpp
string s1, s2;

cin >> s1 >> s2; // read first input into s1, second into s2
cout << s1 << s2 << endl; // write both strings

//输出：
//hello world
//helloworld
```
### 读取未知数量的string对象
```cpp
int main(){
string word;
while(cin >> word) //反复读取，知道文件末尾
	cout<<word<<endl; //逐个输出单词，每个单词后面紧跟一个换行
return 0;
}
```
### 使用`getline`读取一整行

- getline只要遇到换行符就结束读取操作并返回结果；
- getline得到的string对象中并不包含换行符；
```cpp
int main()
{
string line;
//每次读入一整行，包括空白，直到文件末尾
while(getline(cin,line))
	cout<<line<<endl;

return 0;
}
```
### string的操作

- **empty**：判断string对象是否为空；
- **size**：返回string对象的长度；
   - size返回的是`string::size_type`类型的值
   - 允许编译器通过`auto`或者`decltype`来推断变量的类型；
   - size返回的是一个无符号整型，因此如果一条表达式中有了`size()`函数就不要用`int`了，这样可以避免混用`int`和`unsigned`可能带来的问题
- **string比较**：比较运算符比较string对象中的字符时，对大小写敏感，如果两个对象在某些位置上不一致，则string对象比较的结果其实是string对象中第一对相异字符比较的结果；
- **string相加：**字符串的字面值并不是`string`对象；
   - 把`string`对象和字符字面值及字符串字面值混在一条语句中使用时，必须确保每个加法运算符的两侧的运算对象至少有一个是`string`
```cpp
string s1 = "hello", s2 = "world";
string s3 = s1 + "," + s2+ "\n";

string s4 = s1 + ",";      //正确：把一个string对象和一个字面值相加
string s5 = "hello" + ","; //错误：两个运算对象都不是string

string s6 = s1 + "," + "world";
string s7 = "hello" + "," + s2; //错误:不能把字面值直接相加
string s8 = "hello" + ("," + s2); 
```
> - 为了与C兼容，C++语言中的字符串字面值并不是标准库string的对象
> - 字符串字面值与string是不同的类型

## 3.2.3 处理string对象中的字符
在头文件 `cctype` 中定义了一组相关的函数
![image.png](https://cdn.nlark.com/yuque/0/2022/png/29691192/1662796572407-08f80956-5f97-4bbe-8cc1-5eb47b20b111.png#clientId=u5f1c59d0-a2af-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=465&id=W4l3M&margin=%5Bobject%20Object%5D&name=image.png&originHeight=930&originWidth=1016&originalType=binary&ratio=1&rotation=0&showTitle=false&size=131218&status=done&style=stroke&taskId=u9926a870-0c59-4061-9485-43dad830cb0&title=&width=508)
`cctype` 是c语言的头文件，在c++中包含c的头文件有两种形式

   - `#include <ctype.h>`  和c语言一样		
   - `#include <cctype>` 不加 `.h` 而是在前面加一个 `c`
### 基于范围的for语句

- 基本语法
   - declaration 定义一个变量，将被用于访问序列中的基础元素
   - expression：每次迭代，declaration部分的变量会被初始化为expression部分的下一个元素值；
   - statement是一个对象，用于表示一个序列
```cpp
//语法
for (declaration : expression) 
    statement  
```

- 示例：使用`ispunct`统计标点符号
```cpp
int main() {
string s("Hello World!!!");
decltype(s.size()) punct_cnt = 0;
// 算一算有多算个标点符号
for (auto c : s)         // 对s中的每个字符
	if (ispunct(c))      // 如果该字符是标点符号
		++punct_cnt;     // 将标点符号的计数值加1

cout << punct_cnt << " punctuation characters in " << s << endl;
//输出
// 3 punctuation characters in Hello World!!!
```

- 使用for语句该表字符串中的字符
```cpp
int main() {
    string s("Hello World!!!");
    //如果需要改变str中字符，用引用
    for (auto &c : str)
    {
        c = toupper(c);		//c是引用
    }
    cout << str << endl;
}
```

- 使用下标运算符：只把第一个词修改为大写字符
```cpp
int main() {
    string s("Hello World!!!");
    s = orig; 
    decltype(s.size()) index = 0;
    
    while (index != s.size() && !isspace(s[index])) {
        s[index] = toupper(s[index]);
        ++index;
    }
    cout << s << endl;
    return 0
}
```

- 把0-15之间的十进制转为十六进制
```cpp
int main(){
    const string hexdigits = "0123456789ABCDEF";  // 可能的十六进制
    
    cout << "Enter a series of numbers between 0 and 15\n"
    << " separated by spaces.  Hit ENTER when finished: "<< endl;
    string result;        // 保存十六进制字符串
    
    string::size_type n;  // 保存从输入流读取的数
    while (cin >> n)
        if (n < hexdigits.size())    // 忽略无效输入
            result += hexdigits[n];  // 得到对应的十六进制
    
    cout << "Your hex number is: " << result << endl;
    return 0;
}
```
## 3.2.4 小节练习
#### 练习3.2：编写一段程序从标准输入中一次读入一整行，然后修改该程序使其一次读入一个词；
```cpp
#include <iostream>
#include <string>
using std::string;

//输入一行输出一行
void input_line()
{
    string line;
    while (getline(std::cin, line))
        std::cout << line << std::endl;
}

//一次读入一个词，遇到空白停止
void input_word()
{
    string s;
    while (std::cin >> s)
        std::cout << s << std::endl;
}

int main(int argc, char const *argv[])
{
    // input_line();
    input_word();

    return 0;
}
```
#### 练习3.3：请说明`string`类的输入运算符和`getline`函数分别是如何处理空白字符？

- 标准库 string 的输入运算符自动忽略字符串开头的空白（包括空格符、换行符、制表符等），从第一个真正的字符开始读起，直到遇见下一处空白为止。
- 如果希望在最终的字符串中保留输入时的空白符，应该使用 getline 函数代替原来的 >> 运算符，getline 从给定的输入流中读取数据，直到遇到换行符为止，此时换行符也被读取进来，但是并不存储在最后的字符串中。
- 典型示例代码：
```cpp
#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
    string word, line;
    cout << "请选择读取字符串的方式：1 表示逐词读取， 2 表示整行读取" << endl;
    char ch;
    cin >> ch;
    if (ch == '1') {
        cout << "请输入字符串：    Welcome to C++ family!  " << endl;
        cin >> word;
        cout << "系统读取的有效字符串是：" << endl;
        cout << word << endl;
        return 0;
    }

    // 清空输入缓冲区
    cin.clear();
    cin.ignore();

    if (ch == '2') {
        cout << "请输入字符串：    Welcome to C++ family!  " << endl;
        getline(cin, line);
        cout << "系统读取的有效字符串是：" << endl;
        cout << line << endl;
        return 0;
    }
    cout << "您的输入有误！";

    return -1;
}
```
#### 练习3.4：编写一段程序读入两个字符串，比较其是否相等并输出结果；如果不相等，输出较大的那个字符串；该写上述程序，比较两个字符串是否等长，如果不等长，输出较大的那个？
```cpp
#include <iostream>
#include <string>

// 比较是否相等
void compare_equals()
{
    std::string s1, s2;
    std::cout << "请输入两个字符串：" << std::endl;
    std::cin >> s1 >> s2;
    if (s1 == s2)
        std::cout << "两个字符串相等" << std::endl;
    else if (s1 > s2)
        std::cout << s1 << "大于" << s2 << std::endl;
    else
        std::cout << s2 << " 大于 " << s1 << std::endl;
}

//比较长度
void compare_lenght()
{
    std::string s1, s2;
    std::cout << "请输入两个字符串：" << std::endl;
    std::cin >> s1 >> s2;

    auto len1 = s1.size();
    auto len2 = s2.size();

    if (len1 == len2)
        std::cout << s1 << " 和 " << s2 << " 的长度都是 " << len1 << std::endl;
    else if (len1 > len2)
        std::cout << s1 << " 比 " << s2 << " 的长度多 " << len1 - len2 << std::endl;
    else
        std::cout << s1 << " 比 " << s2 << " 的长度小 " << len2 - len1 << std::endl;
}

int main()
{   
    //compare_equals();
    compare_lenght();
}
```
#### 练习3.5：编写一段程序重标准输入中读入多个字符串并将它们连在一起，输出连接成的大字符串。然后修改程序，用空格把输入的多个字符串分隔开来？
```cpp
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
```
#### 练习3.6：编写一段程序，使用范围for语句将字符串内的所有字符用x代替
```cpp
#include <iostream>
#include <string>


using namespace std;

int main(int argc, char const *argv[])
{
    string str;
    cout << "请输入一个字符串，可以包含空格：" << endl;
    getline(cin, str);
    for (auto &c : str)
        c = 'X';
    cout << str << endl;
    return 0;
}
```
#### 练习3.7：就上一题，如果将循环变量的类型设为char将发生什么？
```cpp
#include <iostream>
#include <string>


using namespace std;

int main(int argc, char const *argv[])
{
    string str;
    cout << "请输入一个字符串，可以包含空格：" << endl;
    getline(cin, str);
    for (char &c : str)
        c = 'X';
    cout << str << endl;
    return 0;
}
```
> 就本题而言，将循环控制变量的类型设为 char 不会对程序运行结果造成影响，因为我们使用 auto 自动推断字符串 s 的元素类型，结果同样是 char。

#### 练习3.8：分别用while循环和传统的for循环重写第一题的程序，你觉得哪种形式更好？
```cpp
#include <iostream>
#include <string>

using namespace std;

// 使用while
void CodeByWhile()
{
    string str;
    cout << "请输入一个字符串，可以包含空格：" << endl;
    getline(cin, str);
    int i = 0;
    while (str[i] != '\0')
    {
        str[i] = 'X';
        i++;
    }
    cout << str << endl;
}

//使用for
void CodeByFor()
{
    string str;
    cout << "请输入一个字符串，可以包含空格：" << endl;
    getline(cin, str);
    for (unsigned int i = 0; i < str.size(); i++)
    {
        str[i] = 'X';
    }
    cout << str << endl;
}

int main(int argc, char const *argv[])
{
    // CodeByWhile();
    CodeByFor();
    return 0;
}
```
#### 练习3.9：下面的程序有何作用？它合法吗？如果不合法，为什么？
```cpp
string s;
cout << s[0] << endl;
```
> 该程序的原意是输出字符串 s 的首字符，但程序是错误的。因为初始状态下没有给 s 赋任何初值，所以字符串 s 的内容为空，当然也就不存在首字符，下标 0 是非法的。

#### 练习3.10：编写程序，读入一个包含标点符号的字符串，将标点符号去除后输出字符串剩余的部分
```cpp
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string str;
    cout << "请输入一个字符串，最好含有某些标点符号：" << endl;
    getline(cin, str);
    for (auto c : str)
        if (!ispunct(c))
            cout << c;
    return 0;
}
```
#### 练习3.11：下面的范围for语句合法吗？如果合法，c的类型是什么？
```cpp
const string s = "Keep out!";
for (auto &c: s){ /* ... */}
```
> 该段程序不能正确编译，因为 c 是绑定到常量的引用，其值不能改变!

# 3.3 标准库类型vector

- `vector`类似于数组，但是比数组用于更多的操作;
-  `vector`是模板，由vector生成的模板必须包含vector中元素的类型例如`vector<int>`、`vector<vector<int> >`引用不是对象，所以不存在包含引用的`vector`
```cpp
vector<int> ivec;		//ivec时int类型的对象集合
vector<Sales_item> Sales_vec;	//Sales_vec是Sales_item类型的对象集合
vector<vector<string>> file;	//该向量的元素是vector对象
```
> - C11  在 C11之前 `vector<vector<string>> file;` 要写成 `vector<vector<string> > file;`
> - 后面的两个 `>` 之间是有一个空格的

## 3.3.1 定义和初始化vector对象

- 定义vector对象的常用方法

![image.png](https://cdn.nlark.com/yuque/0/2022/png/29691192/1662796531660-0367f296-3922-4f18-972d-d29df7925962.png#clientId=u5f1c59d0-a2af-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=315&id=S62tY&margin=%5Bobject%20Object%5D&name=image.png&originHeight=630&originWidth=1072&originalType=binary&ratio=1&rotation=0&showTitle=false&size=111721&status=done&taskId=ube7b51ba-3eee-4e75-a157-4eaa30e83fa&title=&width=536)
> 注意 `()` 和 `{}` 初始化vector对象的区别

- _初始化示例_

![image.png](https://cdn.nlark.com/yuque/0/2022/png/29691192/1660473332602-a9937782-58c0-41bb-b7f9-9e8283f8d208.png#clientId=u9edb2937-0b0f-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=72&id=u406503ce&margin=%5Bobject%20Object%5D&name=image.png&originHeight=143&originWidth=700&originalType=binary&ratio=1&rotation=0&showTitle=false&size=76908&status=done&taskId=ucd4e7fac-f410-4574-b041-82e2860919e&title=&width=350)
![image.png](https://cdn.nlark.com/yuque/0/2022/png/29691192/1660473342123-c419088d-535b-4d1e-a9f2-afb9af1d7455.png#clientId=u9edb2937-0b0f-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=59&id=k3OM0&margin=%5Bobject%20Object%5D&name=image.png&originHeight=117&originWidth=827&originalType=binary&ratio=1&rotation=0&showTitle=false&size=85945&status=done&taskId=ue55e8350-2d7a-45a4-8d23-a0b54a76922&title=&width=413.5)
## 3.3.2 向vecotr对象中添加元素

- vector常用操作

![image.png](https://cdn.nlark.com/yuque/0/2022/png/29691192/1662796510528-1293e078-6a45-49e2-91a4-62bb863c9735.png#clientId=u5f1c59d0-a2af-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=392&id=gUm9Y&margin=%5Bobject%20Object%5D&name=image.png&originHeight=784&originWidth=1122&originalType=binary&ratio=1&rotation=0&showTitle=false&size=98572&status=done&taskId=u7e72e9af-0ccf-48e9-b575-32ff337aaa3&title=&width=561)
需要使用for语句时，尽量使用范围for，以免溢出：
```cpp
vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
for (auto &i : v)		//使用引用可以改变v中的值， 
{
    i *= i;				//计算平方
}
for (auto i : v)		//对于v中的每个元素
{
    cout << i << " ";	
}
```
![image.png](https://cdn.nlark.com/yuque/0/2022/png/29691192/1660473650566-3464af5b-b22a-4a8b-8a9e-012f079af69a.png#clientId=u9edb2937-0b0f-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=82&id=ud9fe73be&margin=%5Bobject%20Object%5D&name=image.png&originHeight=164&originWidth=947&originalType=binary&ratio=1&rotation=0&showTitle=false&size=178303&status=done&taskId=u0932369e-c1da-4c09-abb0-d4d1dfdd38a&title=&width=473.5)

- 成绩分数段示例：
```cpp
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <iostream>
using std::cin; using std::cout; using std::endl;

int main(){
    vector<unsigned> grades;// hold the grades we read from the standard input
    
    // count the number of grades by clusters of ten: 
    // 0--9, 10--19, . ..  90--99, 100
    vector<unsigned> scores(11, 0); // 11个分数段，全部初始化0
    unsigned grade;
    while (cin >> grade) {      // 读取成绩
    if (grade <= 100)       // 只处理有效成绩
        grades.push_back(grade);
    ++scores[grade/10]; // 将对应分数段的计数值加1
    }
    cout << "grades.size = " << grades.size() << endl;
    for (auto it : grades)
        cout << it << " " ;
    cout << endl;
    
    cout << "scores.size = " << scores.size() << endl;
    for (auto it : scores)
        cout << it << " " ;
    cout << endl;
}
```

- 不能用下标形式添加元素
```cpp
vector<int> ivec; 
for (decltype(ivec.size()) ix = 0; ix != 10; ++ix)
    ivec[ix] = ix; //严重错误：ivec不包含任何元素
    ivec.push_back(ix); //正确：添加一个新元素
```
## 3.3.3 小节练习
#### 练习3.12：下列vector对象的定义有不正确的吗？请指出
![image.png](https://cdn.nlark.com/yuque/0/2022/png/29691192/1660474538039-76186169-695a-4486-b268-614187ab63dc.png#clientId=u9edb2937-0b0f-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=67&id=u3b9a7513&margin=%5Bobject%20Object%5D&name=image.png&originHeight=95&originWidth=460&originalType=binary&ratio=1&rotation=0&showTitle=false&size=34184&status=done&style=stroke&taskId=u54634ee1-2f94-493a-8a44-d5f95806b4e&title=&width=323)

1. 正确；定义了一个名为ivec的vector对象，每个元素都是`vector<int>`对象；
1. 错误；svec的元素类型是string，而ivec的元素类型是int，因此不能使用ivec初始化svec;
1. 正确；svec含有10个元素，每个元素都是字符串null
#### 练习3.13：下列的vector对象各包含多少个元素？这些元素的值分别是多少？
![image.png](https://cdn.nlark.com/yuque/0/2022/png/29691192/1660475333140-f2940d2b-846e-4d4f-b63c-356b2b3372a9.png#clientId=u9edb2937-0b0f-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=60&id=u65d8cc44&margin=%5Bobject%20Object%5D&name=image.png&originHeight=120&originWidth=772&originalType=binary&ratio=1&rotation=0&showTitle=false&size=62644&status=done&taskId=u923feaf5-ccb0-436a-b568-72664ad3e72&title=&width=386)

1. 元素数量为0；
1. 元素数量为10，每个元素都是0；
1. 元素数量为10，每个元素都是42；
1. 元素数量为1，元素值为10；
1. 元素数量为2，元素值分别为10，42；
1. 元素数量为10，每个元素都是空字符串；
1. 元素数量为10，每个元素都是"hi"；
#### 练习3.14：编写程序，用cin读入一组整数并把他们存入一个vector对象中；
```cpp
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vInt;
    int i = 0;
    char cont = 'y';
    while (cin >> i)
    {
        vInt.push_back(i);
        cout << "您要继续吗（y or n）？" << endl;
        cin >> cont;
        if (cont != 'y' && cont != 'Y')
            break;
    }
    for (auto m : vInt)
        cout << m << endl;

    return 0;
}
```
#### 练习3.15：改写3.14程序，不过这次读入字符串；
```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<string> vInt;
    string str;
    char cont = 'y';
    while (cin >> str)
    {
        vInt.push_back(str);
        cout << "您要继续吗（y or n）？" << endl;
        cin >> cont;
        if (cont != 'y' && cont != 'Y')
            break;
    }
    for (auto m : vInt)
        cout << m << endl;

    return 0;
}
```
#### 练习3.16：编程把3.13中vector对象的容量和具体内容输出出来；
```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};

    cout << "v1 的元素个数是：" << v1.size() << endl;
    if (v1.size() > 0) {        // 当 vector 含有元素时逐个输出
        cout << "v1 的元素分别是：" << endl;
        for (auto e : v1)       // 使用范围 for 语句遍历每一个元素
            cout << e << " ";
        cout << endl;
    }

    cout << "v2 的元素个数是：" << v2.size() << endl;
    if (v2.size() > 0) {
        cout << "v2 的元素分别是：" << endl;
        for (auto e : v2)
            cout << e << " ";
        cout << endl;
    }

    cout << "v3 的元素个数是：" << v3.size() << endl;
    if (v3.size() > 0) {
        cout << "v3 的元素分别是：" << endl;
        for (auto e : v3)
            cout << e << " ";
        cout << endl;
    }

    cout << "v4 的元素个数是：" << v4.size() << endl;
    if (v4.size() > 0) {
        cout << "v4 的元素分别是：" << endl;
        for (auto e : v4)
            cout << e << " ";
        cout << endl;
    }

    cout << "v5 的元素个数是：" << v5.size() << endl;
    if (v5.size() > 0) {
        cout << "v5 的元素分别是：" << endl;
        for (auto e : v5)
            cout << e << " ";
        cout << endl;
    }

    cout << "v6 的元素个数是：" << v6.size() << endl;
    if (v6.size() > 0) {
        cout << "v6 的元素分别是：" << endl;
        for (auto e : v6)
            cout << e << " ";
        cout << endl;
    }

    cout << "v7 的元素个数是：" << v7.size() << endl;
    if (v7.size() > 0) {
        cout << "v7 的元素分别是：" << endl;
        for (auto e : v7)
            cout << e << " ";
        cout << endl;
    }

    return 0;
}
```
#### 练习3.17：从cin读入一组词并存入vector，然后所有改成大写，输出结果，每个词占一行；
```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<string> str;
    string s;
    char cont = 'y'; // 与用户交互，决定是否继续输入
    cout << "请输入第一个词：" << endl;
    while (cin >> s)
    {
        str.push_back(s); // 向 vector 对象中添加元素
        cout << "您要继续吗（y or n）？" << endl;
        cin >> cont;
        if (cont != 'y' && cont != 'Y')
            break;
        cout << "请输入下一个词：" << endl;
    }
    cout << "转换后的结果是：" << endl;
    for (auto &m : str)
    {
        for (auto &c : m)
            c =toupper(c);
        cout << m << endl;
    }

    return 0;
}
```
#### 练习3.18：下面程序合法吗？如果不合法，如何修改？
![image.png](https://cdn.nlark.com/yuque/0/2022/png/29691192/1660476692014-78202c5e-652b-4041-84ee-d7c288ff51f1.png#clientId=u9edb2937-0b0f-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=78&id=u7b50f735&margin=%5Bobject%20Object%5D&name=image.png&originHeight=78&originWidth=293&originalType=binary&ratio=1&rotation=0&showTitle=false&size=11241&status=done&taskId=u50f41ff3-bd87-4827-92f4-45859e65f91&title=&width=293)

- 该程序是非法的，因为 ivec 目前没有任何元素，因此 ivec[0] 的形式是错误的，程序试图访问的元素根本不存在。要想向 vector 对象中添加新元素，需要使用 push_back 函数。
- 修改为：
```cpp
vector<int> ivec;
ivec.push_back(42);
```
#### 练习3.19：写出三种不同方法定义一个10个元素，每个值为42的vector对象，并说明哪种好？
```cpp
//方法1：
vecotr<int> vInt = {42,42,42,42,42,42,42,42,42,42};

//方法2：
vector<int> vInt(10, 42);

//方法3：
vector<int> vInt(10);
for (auto &i : vInt)
    i = 42;
```
> 方法2采用的初始化方式形式上最简洁直观，当 vector 对象的元素数量较多且取值重复时是最好的选择；

#### 练习3.20：读入一组整数并把他们存入一个vector对象，将没对相邻整数的和输出出来。改写程序，先输出第一个和最后一个元素的和，然后输出第2个核倒数第2个的和，以此类推。
```cpp
#include <iostream>
#include <vector>

using namespace std;

void SumNeighbor()
{
    vector<int> vInt;
    int iVal;
    cout << "请输入一组数字：" << endl;
    while (cin >> iVal)
        vInt.push_back(iVal);
    if (vInt.size() == 0)
    {
        cout << "没有任何元素" << endl;
        return;
    }
    cout << "相邻两项的和依次是：" << endl;

    for (decltype(vInt.size()) i = 0; i < vInt.size() - 1; i += 2)
    {
        cout << vInt[i] + vInt[i + 1] << " ";
        if ((i + 2) % 10 == 0) //每行输出5个数字
            cout << endl;
    }
    //如果元素是奇数
    if (vInt.size() % 2 != 0)
        cout << vInt[vInt.size() - 1];
}

void SumHeadTail()
{
    vector<int> vInt;
    int iVal;
    cout << "请输入一组数字：" << endl;
    while (cin >> iVal)
        vInt.push_back(iVal);
    if (vInt.size() == 0)
    {
        cout << "没有任何元素" << endl;
        return;
    }
    cout << "首尾两项的和依次是：" << endl;

    for (decltype(vInt.size()) i = 0; i < vInt.size() - 1; i += 2)
    {
        cout << vInt[i] + vInt[vInt.size() - i - 1] << " ";
        if ((i + 2) % 10 == 0) //每行输出5个数字
            cout << endl;
    }
    //如果元素是奇数
    if (vInt.size() % 2 != 0)
        cout << vInt[vInt.size() / 2];
}

int main(int argc, char const *argv[])
{
    SumHeadTail();
    return 0;
}
```
# 3.4 迭代器介绍

- 迭代器可以理解成一种特殊的指针，他有指针类似的操作，除此之外还有自己独特的一些操作。
## 3.4.1 使用迭代器

- 使用迭代器可以访问某个元素，迭代器也能从一个元素移动到另一个元素。
- 有迭代器的类型都拥有begin和end成员：
   - begin：返回指向第一个元素（或字符）的迭代器
   - end：尾后迭代器，即尾元素的下一个位置（一个本不存在的元素）
```cpp
auto b = v.begin(), e = v.end();	//b和e类型一样
```
> 如果容器为空，则begin和end返回的是同一个迭代器，都是尾后迭代器

- 迭代器和指针类似，所以指针有的运算符，迭代器基本也有

![image.png](https://cdn.nlark.com/yuque/0/2022/png/29691192/1662796475142-18e68af9-543f-463b-8d9f-aaa8ec1770d3.png#clientId=u5f1c59d0-a2af-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=275&id=nORs5&margin=%5Bobject%20Object%5D&name=image.png&originHeight=550&originWidth=964&originalType=binary&ratio=1&rotation=0&showTitle=false&size=79091&status=done&taskId=u1669f272-f8f0-497c-b552-9f72f47bae6&title=&width=482)
尾后迭代器 并不实际指示某一个元素，所以不能对其进行递增或解引用
```cpp
string s("some string");
//将s首字母大写，变为Some string
if(s.begin()!=s.end()){
auto it = s.begin();
*it = toupper(*it);
}
//将s首单词大写，变为SOME string
for(auto it = s.begin();it != s.end()&&!isspace(*it); ++it)
	*it=toupper(*it);
```
### 迭代器类型

- 拥有迭代器的标准类型使用`iterator`和`const_iterator`（和常量指针差不多）
```cpp
vector<int>::iterator it; //it能读写vector<int>元素
string::iterator it2; //it2能读写string对象中的字符

vector<int>::const_iterator it3; //it3只能读元素，不能写元素
string::const_iterator it4; //it4只能读元素，不能写元素
```
### begin和end

- 如果对象是常量，begin和end返回`const_iterator`,否则返回iterator
```cpp
vector<int> v;
const vector<int> cv;
auto it1 = v.begin(); //it1的类型是vector<int>::iterator
auto it2 = cv.begin(); //it2的类型是vector<int>::const_iterator
```

- 有时候我们希望即使对象不是常量，我们也要使用const_iterator：
   - C++11新标准引入了cbegin和cend：
```cpp
auto it3 = v.cbegin(); //it3的类型是vector<int>::const_iterator
```
### 解引用和成员访问
```cpp
vector<string> v;
auto it = v.begin();

(*it).empty();
*it.empty();  //错误：试图访问it的名为empty的成员，但it是迭代器
it->empty(); //箭头运算符：把解引用和成员访问两个操作合在一起
```
```cpp
int main() {
vector<string> text(3, "hello the world!!");

for (auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it)
	cout << *it << endl;
} //将输出三行hello the world!!
```
**PS：任何一种可能改变vector对象容量的操作，都会使得相应的迭代器失效**
## 3.4.2 迭代器运算

- `vector` 和 `string` 迭代器支持的运算

![image.png](https://cdn.nlark.com/yuque/0/2022/png/29691192/1660489391247-3c3fdb33-1a2c-4325-850e-5b06ad4f6396.png#clientId=u9edb2937-0b0f-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=229&id=ud8f34ad0&margin=%5Bobject%20Object%5D&name=image.png&originHeight=410&originWidth=731&originalType=binary&ratio=1&rotation=0&showTitle=false&size=250408&status=done&taskId=u3044b7c1-1a8a-4841-baa0-022bbdbbaba&title=&width=408.5)

- 可以令迭代器和一个整数相加（或相减），其返回值是向前（或向后）移动了若干位置的迭代器。
```cpp
int main() {
    vector<int> text = { 1,2,3,4,5 };
    auto sought = 2;
    auto beg = text.begin(), end = text.end();
    auto mid = beg + (end-beg) / 2; //初始状态的中间点
    
    while (mid != end && *mid != sought) {
        if (sought < *mid)//在前半部分吗？
            end = mid;
        else
            beg = mid + 1;
        mid = beg + (end - beg) / 2;//新的中间点
    }
    if (mid != text.end())
        cout << "找到了！" << *mid <<endl;
    else
        cout << "没有找到！" << endl;
    
    return 0;
}
```
## 3.4.3 小节练习
#### 练习3.21：使用迭代器重做3.3.3节的第一个练习；
```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};

    cout << "v1 的元素个数是：" << v1.size() << endl;
    if (v1.cbegin() != v1.cend()) {        // 当 vector 含有元素时逐个输出
        cout << "v1 的元素分别是：" << endl;
        for (auto it = v1.cbegin(); it != v1.cend(); it++)
            cout << *it << " ";
        cout << endl;
    }

    cout << "v2 的元素个数是：" << v2.size() << endl;
    if (v2.cbegin() != v2.cend()) {
        cout << "v2 的元素分别是：" << endl;
        for (auto it = v2.cbegin(); it != v2.cend(); it++)
            cout << *it << " ";
        cout << endl;
    }

    cout << "v3 的元素个数是：" << v3.size() << endl;
    if (v3.cbegin() != v3.cend()) {
        cout << "v3 的元素分别是：" << endl;
        for (auto it = v3.cbegin(); it != v3.cend(); it++)
            cout << *it << " ";
        cout << endl;
    }

    cout << "v4 的元素个数是：" << v4.size() << endl;
    if (v4.cbegin() != v4.cend()) {
        cout << "v4 的元素分别是：" << endl;
        for (auto it = v4.cbegin(); it != v4.cend(); it++)
            cout << *it << " ";
        cout << endl;
    }

    cout << "v5 的元素个数是：" << v5.size() << endl;
    if (v5.cbegin() != v5.cend()) {
        cout << "v5 的元素分别是：" << endl;
        for (auto it = v5.cbegin(); it != v5.cend(); it++)
            cout << *it << " ";
        cout << endl;
    }

    cout << "v6 的元素个数是：" << v6.size() << endl;
    if (v6.cbegin() != v6.cend()) {
        cout << "v6 的元素分别是：" << endl;
        for (auto it = v6.cbegin(); it != v6.cend(); it++)
            cout << *it << " ";
        cout << endl;
    }

    cout << "v7 的元素个数是：" << v7.size() << endl;
    if (v7.cbegin() != v7.cend()) {
        cout << "v7 的元素分别是：" << endl;
        for (auto it = v7.cbegin(); it != v7.cend(); it++)
            cout << *it << " ";
        cout << endl;
    }

    return 0;
}
```
#### 练习3.22：修改之前输出text第一段的程序，首先把text的第一段全部改成大写，然后再输出；
```cpp
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
```
#### 练习3.23：编程，创建一个含有10个整数的vector对象，然后使用迭代器将所有元素的值都变成原来两倍，输出内容；
```cpp
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vInt;
    srand((unsigned)time(NULL));
    for (int i = 0; i < 10; i++)
    {
        vInt.push_back(rand() % 1000);
    }
    cout << "随机生成的10个数字是：" << endl;

    for (auto it = vInt.begin(); it != vInt.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << "翻倍后10个数字是：" << endl;
    for (auto it = vInt.begin(); it != vInt.end(); it++)
    {
        *it *= 2;
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
```
#### 练习3.24：使用迭代器重做3.3.3节的最后一个练习；
```cpp
#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char const *argv[])
{
    vector<int> vInt;
    int iVal;
    cout << "请输入一组数字：" << endl;
    while (cin >> iVal)
        vInt.push_back(iVal);
    if (vInt.cbegin() == vInt.cend())
    {
        cout << "没有任何元素" << endl;
        return -1;
    }
    cout << "相邻两项的和依次是：" << endl;

    for (auto it = vInt.cbegin(); it != vInt.cend() -1; it++)
    {
        cout << *it + *(++it) << " ";
        if ((it - vInt.begin() + 1) % 10 == 0) //每行输出5个数字
            cout << endl;
    }
    //如果元素是奇数
    if (vInt.size() % 2 != 0)
        cout << *(vInt.cend() - 1);
    return 0;
}

int main2() {
    vector<int> vInt;
    int iVal;
    cout << "请输入一组数字：" << endl;
    while (cin >> iVal)
        vInt.push_back(iVal);
    if (vInt.cbegin() == vInt.cend()) {
        cout << "没有任何元素" << endl;
        return -1;
    }
    cout << "首尾两项的和依次是：" << endl;
    auto beg = vInt.begin();
    auto end = vInt.end();
    // 利用 auto 推断 it 的类型
    for (auto it = beg; it != beg + (end - beg) / 2; it++) {
        // 求首尾两项的和
        cout << (*it + *(beg + (end - it) - 1)) << " ";
        // 每行输出 5 个数字
        if ((it - beg + 1) % 5 == 0)
            cout << endl;
    }
    // 如果元素个数是奇数，单独处理最后一个元素
    if (vInt.size() % 2 != 0)
        cout << *(beg + (end - beg) / 2);

    return 0;
}
```
#### 练习3.25：利用迭代器修改3.3.3节中划分分数段的程序；
```cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 该 vector 对象记录各分数段的人数，初始值为 0
    vector<unsigned> vScore(11);
    auto it = vScore.begin();
    int iVal;
    cout << "请输入一组成绩（0 ～ 100）：" << endl;
    while (cin >> iVal)
        if (iVal < 101)
            ++*(it + iVal / 10);
    cout << "您总计输入了 " << vScore.size() << " 个成绩" << endl;
    cout << "各分数段的人数分布是（成绩从低到高）：" << endl;
    // 利用迭代器遍历 vUS 的元素并逐个输出
    for (; it != vScore.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
```
#### 练习3.26：二分搜索程序中，为什么用mind = beg+(end-beg)/2而不用mid = (beg + end) /2 ;
> C++并没有定义两个迭代器的加法运算，实际上直接把两个迭代器加起来是没有意义的。
> 与之相反，C++定义了迭代器的减法运算，两个迭代器相减的结果是它们之间的距离，也就是说，将运算符右侧的迭代器向前移动多少个元素后得到左侧的迭代器，参与运算的两个迭代器必须指向同一个容器中的元素或尾后元素。
> 另外，C++还定义了迭代器与整数的加减法运算，用以控制迭代器在容器中左右移动。

- 在本题中，因为迭代器的加法不存在，所以 `mid = (beg + end) / 2`; 不合法。
- `mid = beg + (end - beg) / 2`; 的含义是，先计算 end - beg 的值得到容器中的元素个数，然后控制迭代器与**整数**`((end - beg) / 2)`进行运算，从开始处向右移动二分之一容器的长度，从而定位到容器中间的元素。
# 3.5 数组
## 3.5.1 定义和初始化内置数组

- 数组：复合类型（声明形如：`T a[d]`）
   - T：元素类型
   - a：数组名称
   - d：元素个数（必须是常量表达式）
```cpp
unsigned cnt = 42; 
constexpr unsigned sz = 42; //常量表达式
int arr[10];
int *parr[sz];
string bad[cnt]; //错误：cnt不是常量表达式
string strs[get_size()]; //当get_size是constexpr时正确；否则错误
```

- 不存在引用数组
- 可以使用列表初始化，但必须指定数组类型，不允许使用auto
```cpp
const unsigned sz = 3;
int ial[sz] = {0,1,2};
int a2[] = {0,1,2}; //自动推断元素个数为3
int a3[5] = {0,1,2}; //等价于a3[] = {0,1,2,0,0}
string a4[3] = {"hi","bye"}; //等价于a4[]={"hi","bye",""}
int a5[2] = {0,1,2}; //错误：初始值过多
```

- 字符数组的特殊性：字符串字面值的结尾处还有一个空字符
```cpp
char a1[] = {'C','+','+'}; //列表初始化，没有空字符
char a2[] = {'C','+','+','\0'}; //列表初始化，含有显示的空字符
char a3[] = "C++"; //含有空字符
const char a4[6] = "Danial"; //错误，没有空间存放空字符！
```

- 不允许拷贝和赋值
```cpp
int a[] = {0,1,2};
int a2[] = a; //初始化时拷贝错误
a2 = a; //赋值错误
```

- 理解复杂的数组声明
```cpp
int *[10]; //ptrs是含有10个元素（整型指针）的数组
int &refs[10]; //错误：不存在引用的数组
int (*Parray)[10] = &arr; //Parray指向一个含有10个整数的数组
int (&arrRef)[10] = arr; //Parray引用一个含有10个整数的数组
int *(&arry)[10] = ptrs; //arry是数组的引用，该数组包含10个指针
```
对于上面这些声明，使用从内至外的方法读比较合适。
> 对于数组的访问，需要注意的是下标越界问题，数组越界编译器不会报错的，只有在运行是才会出现错误。

## 3.5.2 访问数组元素

- 使用数组初始化 vector对象
```cpp
int int_arr[] = {0, 1, 2, 3, 4, 5};
vector<int> ivec(begin(int_arr), end(int_arr));
```

- 修改之前的例子
```cpp
int main()
{
    vector<unsigned> grades;
    // count the number of grades by clusters of ten:
    // 0--9, 10--19, . . . 90--99, 100
    unsigned scores[11] = {};  // 11 buckets, all value initialized to 0
    unsigned grade;
    while (cin >> grade) {
        if (grade <= 100)
        	++scores[grade / 10]; 
        
        grades.push_back(grade);
    }
    cout << "grades.size = " << grades.size() << endl;
    
    for (auto g : grades)  // for every element in grades
    	cout << g << " ";
    cout << endl;
    
    for (auto i : scores)       // for each counter in scores
    	cout << i << " ";       // print the value of that counter
    cout << endl;
}
```
## 3.5.3 指针和数组
在c++中，数组名就是指针，保存的是数组变量的首地址
```cpp
int arr[10];
//p1和p2是等价的
int *p1 = arr;
int *p2 = &arr[0];

string nums[] = {"one","two","three"}; //数组的元素是string对象
string *p = &nums[0]; //p指向nums的第一个元素
string *p2 = nums; //等价于p2 = &nums[0]

int ia[] = {0,1,2,3,4,5,6,7,8,9}; //ia是一个含有10个整数的数组
auto ia2(ia); //ia2是一个整型指针，指向ia的第一个元素,等价于ia2(&ia[0]);
ia2 = 42; //错误：ia2是一个指针

//当使用decltype时，上述转换不会发生
decltype(ia) ia3 = {0,1,2,3,4,5,6,7,8,9}; //ia3是数组
ia3 = p; //错误：不能用整型指针给数组赋值
ia3[4] = 42; //正确
```
> 数组就是指针，在把数组作为参数传入函数中，必须手动维护一个数组大小的变量
> 因为传入的数组是指针，无法获取到数组的长度

- 指针也是迭代器
```cpp
int arr[] = {0,1,2,3,4,5,6,7,8,9};
int *p = arr; //p指向arr的第一个元素
++p; //p指向arr[1]
int *e = &arr[10]; //指向arr尾元素的下一个位置的指针
for(int *b = arr; b!=e; ++b)
        cout<<*b<<endl; //输出arr的元素

```

- C++11中，`begin` 和  `end` 可以获取数组的头元素和尾后元素（最后一个元素的地址）
```cpp
int main()
{
//begin和end函数定义在iteator头文件中
int ia[] = { 0,1,2,3,4,5,6,7,8,9 };
int *beg = std::begin(ia); //指向ia首元素的指针
int *end = std::end(ia); //指向ia尾元素的下一个位置的指针

//寻找第一个负数
while (beg != end && *beg >= 0)
	++beg;

if (beg != end)
	cout << *beg << endl;
else
	cout << "没找到！" << endl;
}

```
### 指针运算
```cpp
constexpr std::size_t sz = 5;//#include <cstddef>
int arr[sz] = { 1,2,3,4,5 };
int *ip = arr; //等价于int *ip=&arr[0]
int *ip2 = ip + 4; //ip2指向arr的尾元素arr[4]

int *p3 = arr + sz; //正确，但不要解引用
int* ip4 = arr + 10; //错误：arr只有5个元素

auto n = std::end(arr) - std::begin(arr); //n=5

int *b = std::begin(arr), *e = std::end(arr);
while (b<e)//只要两个指针指向同一个数组，或该数组的尾后元素就可以比较
{
    //使用*b
    ++b;
}
```

- 解引用和指针运算交互
```cpp
int ia[] = { 0,2,4,6,8 }; //含有5个整数的数组
int last = *(ia + 4); //正确：last = 8
last = *ia + 4; //正确：last = 0 + 4 = 4
```

- 下标和指针
```cpp
int ia[] = { 0,2,4,6,8 };
int i = ia[2];//与下面两条等价

int *p = ia;
i = *(p + 2);

int *p = &ia[2];
int j = p[1]; //6
int k = p[-2]; //0，string，vector的下标不可以为负
```
> 标准库类型限定使用下标必须是无符号型，而内置的下标运算无此要求；

## 3.5.4 C风格字符串

- C风格字符串不是一种类型，而是为了表达和使用字符串而形成的一种约定俗成的写法。
- C风格字符串的处理函数定义在cstring头文件（string.h的C++版本）中。
   - strlen(p)
   - strcmp(p1,p2)
   - strcat(p1,p2)
   - strcpy(p1,p2)
- 在c语言中通常是 `const char*` 表示字符串，并且以空字符 `\0` 为结尾。
```cpp
const char* str = "heo\0ll";	//定义一个c风格的字符串，并且在中间加入一个结束符
//因为结束符的原因，c的函数库一些操作会出现意想不到的结果
strlen(str);	//计算str的长度，结果是3，计算方式是遇到空字符结束
```
> c中的字符串是以空字符 `\0` 判断字符串结束，如果我们自己的定义的字符数组或是字符常量中没有 `\0` 或是字符中间有 `\0` 都不能得到正确的结果

**C和C++字符串的转换**
在C中是定义了一个 `string` 类作为字符串类型,  `string` 类中重载了系列的运算符，所以从c 风格 （`const char*`） 到  c风格（`string`）的转换都是自动完成的。以下是一些注意点
```cpp
//从 c到 c++   const char* ---> string
//1. 使用字符串字面字初始化string类型，本章第二节
string s3("value");		//s3是字面值 "value" 的副本，不包含最后的空字符
string s3 = "value";	//同上
//2. string 重载了 + 运算符，可以直接拼接， s1，s2是string类型
string s4 = s1 + ", ";				//正确
string s5 = "hello" + ", ";			//错误
string s6 = s1 + ", " + "world";	//正确
string s7 = "hello" + ", " + s2;	//错误

//从 c++到 c,  string ---> const char* 
//在string类中定义了一个c_str的成员函数，可以返回 const char*
char *str = s;		//错误：不能直接使用stringdvx初始化char*
const char *str = s.c_str();	//正确，s是一个string对象，调用c_str()方法
```
> 说明：在c++的string类种是重载了`+`, 改运算符返回的也是string类型，分析
> 1. s4, `s1`是string类型，会调用重载的 `+`
> 1. s5, `hello` 和 `,` 都是 `const char*` 类型，该类型并没有定义 `+` 运算
> 1. s6,  `(s1 + ", ")`   和s4 一样，得到的是一个临时的 string， 再   `+ "world"`
> 1. s7,  `"hello" + ", "` 的错误和s5一样

## 3.5.5 与旧代码的接口
```cpp
string s("Hello World"); //s的内容是Hello World
char *str = s; //错误：不能用string对象直接初始化字符的指针。
const char *str=s.c_str(); //正确，c风格的string
```
> 如果后续的操作改变了s的值，c_str所返回的数组将失效。

- s使用数组初始化vector对象
```cpp
//使用数组初始化vector对象
int int_arr[] = {0,1,2,3,4,5};
//ivec有6个元素，分别是int_arr中对应元素的副本
vector<int> ivec(std::begin(int_arr),std::end(int_arr));
//拷贝三个元素：int_arr[1]、int_arr[2]、int_arr[3]
vector<int> subVec(int_arr+1,int_arr+4);
```
## 3.5.6 小节练习
#### 练习3.27：假设txt_size是一个无参数的函数，返回值是int，请问下列哪些定义是非法的？
```cpp
unsigned buf_size = 1024;

//a: 不合法，buf_size不是常量
int ia[buf_size];
//b: 合法，常量表达式
int ia[4 * 7 -14];
//c：不合法， 没有被定义为 constexpr，不能作为数组长度
ubt ua[txt_size()];
//d：不合法，长度不够加入'\0'
char st[11] = "fundamental";
```
#### 练习3.28：下列数组中元素的值是什么？
与练习 2.10 类似，对于 string 类型的数组来说，因为 string 类本身接受无参数的初始化方式，所以不论数组定义在函数内还是函数外都被默认初始化为空串。
对于内置类型 int 来说，数组 ia 定义在所有函数体之外，根据 C++ 的规定，ia 的所有元素默认初始化为 0；而数组 ia2 定义在 main 函数的内部，将不被初始化，如果程序试图拷贝或输出未初始化的变量，将遇到未定义的奇异值。
```cpp
#include <iostream>
using namespace std;

string sa[10];
int ia[10];

int main()
{
    string sa2[10];
    int ia2[10];

    for (auto c : sa)
        cout << c << " ";
    cout << endl;
    for (auto c : sa2)
        cout << c << " ";
    cout << endl;
    for (auto c : ia)
        cout << c << " ";
    cout << endl;
    for (auto c : ia2)
        cout << c << " ";
    cout << endl;
    return 0;
}
```
#### 练习3.29：相比于vector，数组有哪些缺点？

- 数组与 vector 的相似之处是都能存放类型相同的对象，且这些对象本身没有名字，需要通过其所在位置访问。
- 数组与 vector 的最大不同是，数组的大小固定不变，不能随意向数组中增加额外的元素，虽然在某些情境下运行时性能较好，但是与 vector 相比损失了灵活性。
- 具体来说，数组的维度在定义时已经确定，如果我们想更改数组的长度，只能创建一个更大的新数组，然后把原数组的所有元素复制到新数组中去。数组也无法像 vector 那样使用 size 函数直接获取数组的维度。如果是字符数组，可以调用 strlen 函数得到字符串的长度；如果是其他数组，只能使用 sizeof(array) / sizeof(array[0]) 的方式计算数组的维度。
#### 练习3.30：指出下列代码中的索引错误
```cpp
constexpr size_t array_size = 10;
int ia[array_size];
for (size_t ix = 0; ix < array_size; ++ix) //小于号而不是小于等于
    ia[ix] = ix;
```
#### 练习3.31：写代码，定义一个含有10个int的数组，使其每个值是元素下标；
```cpp
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    const int sz = 10;
    int a[sz];

    for(int i = 0; i < sz; i++)
        a[i] = i;
    for (auto val: a)
        cout << val << " ";
    cout << endl;
    return 0;
}
```
#### 练习3.32：将上题数组拷贝给另一个，利用vector重写程序，实现类似功能；
```cpp
#include <iostream>
#include <vector>
using namespace std;

void copyArray()
{
    const int sz = 10; // 常量 sz 作为数组的维度
    int a[sz], b[sz];

    for (int i = 0; i < sz; i++)
        a[i] = i;
    for (int j = 0; j < sz; j++)
        b[j] = a[j];
    // 通过范围 for 循环输出数组的全部元素
    for (auto val : b)
        cout << val << " ";
    cout << endl;
}

void copy_vector(){
    const int sz = 10;          // 常量 sz 作为 vector 的容量
    vector<int> vInt, vInt2;
    // 通过 for 循环为 vector 对象的元素赋值
    for (int i = 0; i < sz; i++)
        vInt.push_back(i);
    for (int j = 0; j < sz; j++)
        vInt2.push_back(vInt[j]);
    // 通过范围 for 循环输出 vector 对象的全部元素
    for (auto val : vInt2)
        cout << val << " ";
    cout << endl;
}

int main(int argc, char const *argv[])
{
    // copyArray();
    copy_vector();
    return 0;
}
```
#### 练习3.33：对于104页的程序，如果不初始化scores将发生什么？

- 如果不初始化 scores，则该数组会含有未定义的数值，这是因为 scores 是定义在函数内部的整型数组，不会执行默认初始化。
#### 练习3.34：假设p1和p2指向同一个数组中的元素，则下面程序功能是什么？什么时候是非法的？
程序：p1 += p2 - p1

- 如果 p1 和 p2 指向同一个数组中的元素，则该条语句令 p1 指向 p2 原来所指向的元素。从语法上来说，即使 p1 和 p2 指向的元素不属于同一个数组，但只要 p1 和 p2 的类型相同，该语句也是合法的。
- 如果 p1 和 p2 的类型不同，则编译时报错。
#### 练习3.35：写程序，利用指针将数组中的元素设为0；
```cpp
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a[10], i = 0;
    for (int i = 0; i < 10; i++)
    {
        a[i] = i;
    }
    cout << "初始状态下数组的内容是：" << endl;
    for (auto val : a)
        cout << val << " ";
    cout << endl;

    int *p = begin(a);
    while(p != end(a)){
        *p = 0;
        p++;
    }
    cout << "修改后的数组内容是：" << endl;
    // 通过范围 for 循环输出数组的全部元素
    for (auto val : a)
        cout << val << " ";
    cout << endl;
    return 0;
}

```
#### 练习3.36：写程序，比较两个数组是否相等；再写一个程序，比较两个vector对象是否相等；
无论对比两个数组是否相等还是两个 vector 对象是否相等，都必须逐一比较其元素。
#### 练习3.37：下面程序有何含义，输出的结果是什么？
![image.png](https://cdn.nlark.com/yuque/0/2022/png/29691192/1662305312938-7ccb3cb4-aad0-4ffe-b875-1af6a5c10922.png#clientId=u345179c7-31b2-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=126&id=u6103709f&margin=%5Bobject%20Object%5D&name=image.png&originHeight=252&originWidth=1048&originalType=binary&ratio=1&rotation=0&showTitle=false&size=74800&status=done&taskId=u43b7904c-502a-4727-894a-87d036fba9f&title=&width=524)

- while 循环的条件是 *cp，只要指针 cp 所指的字符不是空字符 \0，循环就重复执行，循环的任务有两项：首先输出指针当前所指的字符，然后将指针向后移动一位。
- 该程序的原意是输出 ca 中存储的 5 个字符，每个字符占一行，但实际的执行效果无法符合预期。因为以列表初始化方式赋值的 C 风格字符串与以字符串字面值赋值的有所区别，后者会在字符串最后额外增加一个空字符以示字符串的结束，而前者不会这样做。
- 因此在该程序中，ca 的 5 个字符全都输出后，并没有遇到预期的空字符，也就是说，while 循环的条件仍将满足，无法跳出。程序继续在内存中 ca 的存储位置之后挨个寻找空字符，直到找到为止。在这个过程中，额外经历的内容也将被输出出来，从而产生错误。
- 输出结果为：如需修改，则改为：const char ca[]={'h','e','l','l','o','\0'};
```cpp
h
e
l
l
o
�
�
```
#### 练习3.38：将两个指针相加不但是非法的，而且没什么意义，为什么？

- 指针也是一个对象，与指针相关的属性有 3 个，分别是指针本身的值（value）、指针所指的对象（content）以及指针本身在内存中存储位置（address）。它们的含义分别是：
   - 指针本身的值是一个内存地址值，表示指针所指对象在内存中的存储地址；
   - 指针所指的对象可以通过解引用指针访问；
   - 因为指针也是一个对象，所以指针也存储在内存的某个位置，它有自己的地址，这也是为什么有"指针的指针"的原因。
- 通过上述分析我们知道，指针的值是它所指对象的内存地址，如果我们把两个指针加在一起，就是试图把内存中两个对象的存储地址加在一起，这显然是没有任何意义的。与之相反，指针的减法是有意义的。如果两个指针指向同一个数组中的不同元素，则它们相减的结果表征了它们所指的元素在数组中的距离。
#### 练习3.39：写程序，比较两个string对象，再编写一段程序，比较两个C风格字符串的内容；
```cpp
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
```
#### 练习3.40：写程序，定义两个字符数组并用字符串字面值初始化，接着再定义一个字符数组存放前两个数组连接后的结果。使用strcpy 和 stract 把前面两个数组的内容拷贝到第三个数组中；

- C 风格字符串的操作函数定义在 cstring 头文件中。其中，strcpy 函数负责把字符串的内容拷贝给另一个字符串，strcat 函数则负责把字符串的内容拼接到另一个字符串之后。此外，strlen 函数用于计算字符串的长度，不包括 \0 空字符；size 函数用于计算字符串在内存实际（真实）占用，包括 \0 空字符。
- 需要注意的是，利用字符串字面值常量初始化 C 风格字符串时，默认在数组最后添加一个空字符，因此，size 的计算结果比字面值显示的字符数量多 1。为了细致起见，计算两个字符串拼接后的长字符串长度时，应该在两个字符串各自长度求和后减 1，即减去 1 个多余空字符所占的额外空间。
```cpp
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
    char str1[] = "hello world ";
    char str2[] = "by jimmy";

    char result[size(str1) + size(str2) - 1]; 
    // char result[strlen(str1) + strlen(str2) + 1];
    strcpy(result, str1);
    strcat(result, str2);

    cout << "第一个字符串是：" << str1 << endl;
    cout << "第二个字符串是：" << str2 << endl;
    cout << "拼接后的字符串是：" << result << endl;

    return 0;
}
```
#### 练习3.41：写程序，用整数型数组初始化一个vector对象；

- C++不允许用一个数组初始化另一个数组，也不允许使用 vector 对象直接初始化数组，但是允许使用数组来初始化 vector 对象。要实现这一目的，只需要指明要拷贝区域的首元素地址和尾后地址。
```cpp
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    const int sz = 10;              // 常量 sz 作为数组的维度
    int a[sz];
    srand((unsigned) time(NULL));   // 生成随机数种子
    cout << "数组的内容是：" << endl;
    // 利用范围 for 循环遍历数组的每个元素
    for (auto &val : a) {
        val = rand() % 100;         // 生成一个 100 以内的随机数
        cout << val << " ";
    }
    cout << endl;

    vector<int> vInt(begin(a), end(a));
    cout << "vector 的内容是：" << endl;
    // 利用范围 for 循环遍历 vector 的每个元素
    for (auto val : vInt) {
        cout << val << " ";
    }
    cout << endl;

    return 0;

}
```
#### 练习3.42：写程序，将含有整数型元素的vector对象拷贝给一个整数型数组

- C++允许使用数组直接初始化 vector 对象，但是不允许使用 vector 对象初始化数组。如果想用 vector 对象初始化数组，则必须把 vector 对象的每个元素逐一赋值给数组。
```cpp
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    const int sz = 10;                  // 常量 sz 作为 vector 对象的容量
    vector<int> vInt;
    srand((unsigned) time(NULL));       // 生成随机数种子
    cout << "vector 对象的内容是：" << endl;
    // 利用 for 循环遍历 vector 对象的每个元素
    for (int i = 0; i != sz; i++) {
        vInt.push_back(rand() % 100);   // 生成一个 100 以内的随机数
        cout << vInt[i] << " ";
    }
    cout << endl;

    auto it = vInt.cbegin();
    int a[vInt.size()];
    cout << "数组的内容是：" << endl;
    // 利用范围 for 循环遍历 vector 的每个元素
    for (auto &val : a) {
        val = *it;
        cout << val << " ";
        it++;
    }
    cout << endl;

    return 0;
}
```
# 3.6 多维数组

- 严格来说C++没有多维数组
```cpp
int ia[3][4]; //大小为3的数组，每个元素是含有4个整数的数组
int arr[10][20][30] ={0}; //将所有元素初始化为0
```
## 3.6.1 多维数组的初始化
```cpp
//允许使用花括号初始化多维数组
int ia2[3][4] = {
{0,1,2,3},
{4,5,6,7},
{8,9,10,11} 
};
int ia3[3][4] ={ 0,1,2,3,4,5,6,7,8,9,10,11};
int ia4[3][4] = {{0},{4},{8}};//{ 0,0,0,0,4,0,0,0,8,0,0,0};
int ia5[3][4] = {0,3,6,9}; // {0,3,6,9,0,0,0,0,0,0,0,0};
```
## 3.6.2 多维数组的下标引用
```cpp
//用arr的首元素为ia最后一行的最后一个元素赋值
ia[2][3] = arr[0][0][0];
int(&row)[4] = ia[1];//把row绑定到ia的第二个4元素数组上

constexpr size_t rowCnt = 3, colCnt = 4;
int ia[rowCnt][colCnt]; //12个未初始化的元素
//对于每一行
for (size_t i = 0; i != rowCnt; ++i)
    //对于每一列
    for (size_t j = 0; j != colCnt; ++j)
    	ia[i][j] = i * colCnt + j;//将位置索引作为值

size_t cnt = 0;
for (auto& row : ia)
    for (auto& col : row) {
        col = cnt;
        ++cnt;
    }

for (auto row : ia) //取出来的数组，会被编译器转换为指针
	for (auto col : row) //错误：int *row没有合适的begin函数
		;

for (auto& row : ia) //row声明为引用，可以避免被自动转换为指针
	for (auto col : row)
		cout << col << endl;
```
> 要使用范围for语句处理多维数组，除了最内存的循环外， 其他所有的循环的控制变量都应该是引用类型；

## 3.6.3 指针和多维数组
```cpp
int ia[3][4];
int(*p)[4] = ia;
p = &ia[2]; //p指向ia的尾元素

//输出ia中每个元素的值，每个内层数组各占一行
//p指向含有4个整数的数组
for (auto p = ia; p != ia+3; ++p){
    //q指向4个整数数组的首元素，也就是说，q指向一个整数
    for (auto q = *p; q != *p + 4; ++q)
    	cout << *q << ' ';
    cout << endl;
}

//p指向ia的第一个数组
for (auto p = std::begin(ia); p != std::end(ia); ++p)
    //q指向内层数组的首元素
    for (auto q = std::begin(*p); q != std::end(*p); ++q)
    	cout << *q << ' '; //输出q所指向的整数值
	cout << endl;
```
## 3.6.4 类型别名简化多维数组的指针
```cpp
using int_array = int[4];//typedef int int_array[4];

for (int_array *p = ia; p !=ia+3; ++p){
    for (int* q = *p; q != *p + 4; ++q)
    	cout << *q << ' ';
    cout << endl;
}
```
# 3.6.5 小节练习
#### 练习3.43：写3个程序，均能输出ia的元素，版本1使用范围for，版本2和版本3都使用普通for，其中版本2要求用下标运算符，版本3用指针。此外，3个版本都要直接写出数据类型，而不能使用类型别名、auto关键字或decltype关键字。
```cpp
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    cout << "使用范围for语句输出多维数组内容为： " << endl;
    for (int(&row)[4] : ia)
    {
        for (int &col : row)
            cout << col << " ";
        cout << endl;
    }

    cout << "利用for循环和下标运算符输出数组内容为：" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            cout << ia[i][j] << " ";
        cout << endl;
    }

    cout << "利用for循环和指针输出数组内容为：" << endl;
    for (int(*p)[4] = ia; p != ia + 3; p++)
    {
        for (int *q = *p; q != *p + 4; q++)
            cout << *q << " ";
        cout << endl;
    }

    return 0;
}

```
#### 练习3.44：改写上个程序，使用类型别名来代替循环控制变量的类型；
```cpp
#include <iostream>
using namespace std;

// using int_array = int[4];
typedef int int_array[4];

int main(int argc, char const *argv[])
{
    int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    cout << "使用类别别名多维数组内容为： " << endl;
    for (int_array(&row) : ia)
    {
        for (int &col : row)
            cout << col << " ";
        cout << endl;
    }
    return 0;
}
```
#### 练习3.45：再次改写程序，使用auto关键字；
```cpp
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    cout << "使用类别别名多维数组内容为： " << endl;
    for (auto &row : ia)
    {
        for (int &col : row)
            cout << col << " ";
        cout << endl;
    }

    cout << "利用for循环和指针输出数组内容为：" << endl;
    for (auto p = ia; p != ia + 3; p++)
    {
        for (auto q = *p; q != *p + 4; q++)
            cout << *q << " ";
        cout << endl;
    }

    return 0;
}
```
