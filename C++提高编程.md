# 	C++提高编程

- 本阶段主要针对c++==泛型编程==和==STL==技术做详细讲解，探讨c++更深层的使用



### 1 模板

#### 1.1 模板的概念

模板就是建立**通用的摸具**，大大提高**复用性**

模板的特点：

- 模板不可以直接使用，它只是一个框架
- 模板的通用并不是万能的



#### 1.2 函数模板

- c++另一种编程思想称为 ==泛型编程==，主要利用的技术就是模板
- c++提供两种模板机制：==函数模板==和==类模板==

##### 1.2.1 函数模板语法

作用：

建立一个通用函数，其函数返回值类型和形参类型可以不具体制定，用一个==虚拟的类型==来代表

语法：

`````c++
template<typename/class T>
函数声明或定义
`````

解释：

template — 声明创建模板

typename — 表面其后面的符号是一种数据类型，可以用class代替

T — 通用的数据类型，名称可以替换，通常为大写字母

`````c++
#include<iostream>
using namespace std;

template<typename T>
void CommonSwap(T &a, T &b){    //同一个T 所以a,b类型要一样
    T temp = a;
    a = b;
    b = temp;
}

int main(){
    //两种使用函数模板方式
    int a = 1;
    int b = 2;
    //1 自动类型推导
    CommonSwap(a,b);
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;
    //2 显示指定类型
    CommonSwap<int>(a,b);
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;
}
`````

> 类型参数化



##### 1.2.2 函数模板注意事项

- 自动类型推导，必须推导出一致的数据类型T
- 模板必须要确定出T 的数据类型

`````c++
template<class T>
void func(){
    cout<<"call.."<<endl;
}
int main(){
    //func(); //错误 必须给出T的类型
    func<int>();    //利用显示指定类型的方式 给T一个类型 才可以使用模板
}
`````



##### 1.2.3 函数模板案例

案例描述：利用函数模板封装一个排序的函数，可以对不同数据类型的数组进行排序

`````c++
#include<iostream>
using namespace std;

template<class T>
int partition(T arr[], int first, int last){
    T pivot = arr[first];
    int lastS1 = first;
    for(int i = first +1; i <= last; i++){
        if(arr[i] > pivot){     //desceding order
            lastS1++;
            swap(arr[lastS1],arr[i]);
        }
    }
    swap(arr[first],arr[lastS1]);
    return lastS1;
}

template<class T>
void quickSort(T arr, int first, int last){
    if(first < last){
        int pivotIndex = partition(arr,first,last);
        quickSort(arr, first,pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, last);
    }
}

template<class T>
void print(T arr[], int n){
    //n = sizeof(arr) / sizeof(T);//错误 因为数组在函数中退化为指针
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int a[] = {3,2,5,6,23,66};
    double b[] = {24.5,52.5,32.1};
    char charA[] = "svhaweriovhb";

    int len_a = sizeof(a) / sizeof(a[0]);
    int len_b = sizeof(b) / sizeof(b[0]);
    int len_c = sizeof(charA) / sizeof(charA[0]);
    
    quickSort(a,0,5);
    quickSort(b,0,2);
    quickSort(charA,0,len_c-1);
    
    print(a,len_a);
    print(b,len_b);
    print(charA,len_c);
}
`````



##### 1.2.4 普通函数与函数模板的区别

- 普通函数调用时可以发生自动类型转换（==隐式类型转换==）
- 函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
- 如果利用显示指定类型的方式，可以发生隐式类型转换

`````c++
#include<iostream>
using namespace std;

int myAdd(int a, int b){
    return a + b;
}

template<class T>
T myAdd02(T a, T b){
    return a + b;
}

int main(){
    int a = 10;
    double b = 10.999;
    char c = 'c';   //a-97 c-99
    int d = 1;
    cout<<myAdd(a,c)<<endl;
    cout<<myAdd(a,b)<<endl;
    
    cout<<myAdd02(a,d)<<endl;
    //cout<<myAdd02(a,c)<<endl;       //不给自动转换（或者说不知道转换为什么类型 
    cout<<myAdd02<int>(a,b)<<endl;
}
`````

> 总结：建议使用显示指定类型的方式，调用函数模板，因为可以自己确定通用类型T



##### 1.2.5 普通函数与函数模板的调用规则

1. 如果函数模板和普通函数都可以实现，**优先调用普通函数**
2. 可以通过**空模板参数列表**来强制调用函数模板
3. 函数**模板也可以发生重载**
4. 如果函数模板可以产生==更好的匹配==优先调用函数模板

```c++
#include<iostream>
using namespace std;

void myPrint(int a, int b){
    cout<<"This is a normal function."<<endl;
}

template<class T>
void myPrint(T a, T b){
    cout<<"This is template function."<<endl;
}

template<class T>
void myPrint(T a, T b, T c){
    cout<<"override template function."<<endl;
}

int main(){
    int a = 10;
    int b = 20;

    myPrint(a, b);
    myPrint<>(a, b);
    myPrint(a, b, 1);

    char a1 = 'a';
    char b1 = 'b';
    myPrint(a1, b1);
}
```

> 总结： 既然提供了函数模板，最好不要提供普通函数，否则容易出现二义性



##### 1.2.6 模板的局限性

`````c++
template<class T>
void func(T a, T b){
	a = b;
}
`````

如果a,b 传入的是数组，就无法实现

或如果T 的数据类型传入的是自定义的数据类型，也无法实现

因此为了解决这种问题，提供模板的重载，可以为这些**特定的类型**提供**具体化的模板**

`````c++
#include<iostream>
using namespace std;

class Person{
public:
    Person(int n){
        this->name = n;
    }
    string name;
};

template<class T>
bool myCompare(T &a, T &b){
    if(a == b)
        return true;
    return false;
}

//利用具体化Person的版本实现代码 具体化优先调用
//template<>告诉编译器这是一个特化的模板版本 不可以省略
template<> bool myCompare(Person &p1, Person &p2){		
    if(p1.name == p2.name)
        return true;
    return false;
}

int main(){
    int a = 10;
    int b = 20;
    bool rel = myCompare(a, b);
    if(rel)
        cout<<"a = b"<<endl;
    else    cout<<"a != b"<<endl;
    Person p1(1);
    Person p2(1);
    bool rel2 = myCompare(p1, p2);
    if(rel2)
        cout<<"a = b"<<endl;
    else    cout<<"a != b"<<endl;
}
`````

> 学习模板并不是为了写模板，而是在STL能够运用系统提供的模板



#### 1.3 类模板

##### 1.3.1 类模板语法

作用：

- 建立一个通用类，类中的成员 数据类型可以不具体制定，用一个虚拟的类型来代表

语法

```c++
template<typename T>
类
```

解释：

template — 声明创建模板

typename — 表面其后面的符号是一种数据类型，可以用class代替

T — 通用的数据类型，名称可以替换，通常为大写字母

`````c++
#include<iostream>
using namespace std;

template<class NameType, class AgeType>
class Person{
public:
    Person(NameType name, AgeType age){
        this->m_Name = name;
        this->m_Age = age;
    }
    void showPersonInfo(){
        cout<<"Name: "<<this->m_Name<<endl;
    }

    NameType m_Name;
    AgeType m_Age;
};

void test01(){
    Person<string,int> p1("kong", 1000);
    p1.showPersonInfo();
}

int main(){
    test01();
}
`````



##### 1.3.2 类模板与函数模板区别

1. 类模板**没有自动类型推导**的使用方式
2. 类模板在模板参数列表中可以有**默认参数**

`````c++
#include<iostream>
using namespace std;

template<class NameType, class AgeType = int>
class Person{
public:
    Person(NameType name, AgeType age){
        this->m_Age = age;
        this->m_Name = name;
    }

    void showInfo(){
        cout<<"Name: "<<this->m_Name<<" Age: "<<this->m_Age<<endl;
    }

    NameType m_Name;
    AgeType m_Age;
};

void test01(){
    //Person p("Xiao", 17);   //missing template arguments before'p'
    Person<string,int> p("Xiao", 17);
    p.showInfo();
}

void test02(){
    Person<string>p("Zhu",11);
    p.showInfo();
}

int main(){
    test01();
    test02();
}
`````



##### 1.3.3 类模板中成员函数创建时机

类模板中成员函数和普通类中成员函数创建时机是有区别的：

- 普通类中的成员函数一开始就可以创建
- 类模板中的成员函数在调用时才创建

`````c++
#include<iostream>
using namespace std;

class Person1{
public:
    void showPerson1(){
        cout<<"Person1 show"<<endl;
    }
};

class Person2{
public:
    void showPerson2(){
        cout<<"Person2 show"<<endl;
    }
};

template<class T>
class Myclass{
public:
    T obj;
    void func1(){
        obj.showPerson1();
    }
    void func2(){
        obj.showPerson2();
    }
};
//前面的代码build成功是因为类模板中的成员函数根本没有创建

int main(){
    Myclass<Person1> p1;
    p1.func1();
    //p1.func2();
}
`````

> [!NOTE]
>
> obj无法确认数据类型——成员函数未创建——直到调用（实例化）创建



##### 1.3.4 类模板对象做函数参数

- 类模板实例化出的对象，向函数传参的方式

1. 指定传入的类型       - - - 直接显示对象的数据类型
2. 参数模板化              - - - 将对象中的参数变为模板进行传递
3. 整个类模板化         - - - 将这个对象类型 模板化进行传递

`````c++
#include<iostream>
using namespace std;

template<class T1, class T2>
class Person{
public:
    Person(T1 name, T2 age){
        this->m_Age = age;
        this->m_Name = name;
    }
    void showInfo(){
            cout<<"Name: "<<m_Name<<" Age: "<<m_Age<<endl;
    }

    T1 m_Name;
    T2 m_Age;
};

//1 指定传入类型
void printPerson1(Person<string,int> &p){
    p.showInfo();
}

void test01(){
    Person<string,int> p("FEN", 20);
    printPerson1(p);
}

//2 参数模板化
template<class T1, class T2>
void printPerson2(Person<T1, T2> &p){
    p.showInfo();
    cout<<"T1 type: "<<typeid(T1).name()<<endl;
    cout<<"T2 type: "<<typeid(T2).name()<<endl;
}

void test02(){
    Person<string,int> p("NU", 20);
    printPerson2(p);
}

//3 整个类模板化
template<class T>
void printPerson3(T &p){
    p.showInfo();
}

void test03(){
    Person<string,int> p("Shang", 20);
    printPerson3(p);
}

int main(){
    test01();
    test02();
    test03();
}
`````

> 使用比较广泛的是第一种：指定传入类型



##### 1.3.5 类模板与继承

- 当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
- 如果不指定，编译器无法给子类分配内存
- 如果向灵活指定出父类中T的类型，子类也需要变为类模板

`````c++
#include<iostream>
using namespace std;

template<class T>
class Base{
public:
    T base_m;
};

class Son: public Base<int>{};

template<class T1, class T2>
class Son2: public Base<T2>{
    T1 obj;
};

int main(){
    Son2<int,char> s2;
}
`````



##### 1.3.6 类模板成员函数类外实现

`````c++
#include<iostream>
using namespace std;

template<class T1, class T2>
class  Person{
public:
    Person(T1 n, T2 a);
    void ShowInfo();
    T1 name;
    T2 age;
};

//构造函数类外实现
template<class T1, class T2>
Person<T1,T2>::Person(T1 n, T2 a){
    this->name = n;
    this->age = a;
} 

//成员函数类外实现
template<class T1, class T2>
void Person<T1,T2>::ShowInfo(){
    cout<<"....."<<endl;
}

int main(){
    Person<string,int> p("Tom", 11);
    p.ShowInfo();
}
`````



##### 1.3.7 类模板分文件编写

目标：

- 掌握类模板成员函数分文件编写产生的问题以及解决方式

问题：

- **类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到**

解决：

- 1： 直接包含.cpp源文件
- 2：==将声明和实现写到同一个文件中==，并更改后缀名为.hpp



##### 1.3.8 类模板与友元

全局函数类内实现 —— 直接在类内声明友元

全局函数类外实现 —— 需要提前让编译器知道全局函数的存在

`````c++
#include<iostream>
using namespace std;

template<class T1, class T2>
class Person;
//编译器需要提前知道函数的存在
template<class t1, class t2>
void printPerson2(Person<t1,t2> p){
    cout<<"Name: "<<p.m_Name<<" Age: "<<p.m_Age<<endl;
}

template<class T1, class T2>
class Person{
    //全局 友元函数类内实现？
    friend void printPerson(Person<T1,T2> p){
        cout<<"Name: "<<p.m_Name<<" Age: "<<p.m_Age<<endl;
    }
    //添加空模板参数列表
    friend void printPerson2<>(Person<T1,T2> p);
public:
    Person(T1 name, T2 age){
        this->m_Age = age;
        this->m_Name = name;
    }
    void showInfo(){
            cout<<"Name: "<<m_Name<<" Age: "<<m_Age<<endl;
    }
private:
    T1 m_Name;
    T2 m_Age;
};

int main(){
    Person<string,int> p("RIu",20);
    printPerson(p);
    printPerson2(p);
}
`````

> 建议全局友元函数做类内实现。。



##### 1.3.9 类模板案例

案例描述：实现一个通用的数组类，需求如下：

-  可以对内置以及自定义的数据类型进行存储
-  将数组中的数据存储到堆区
-  构造函数中可以传入数组的容量
-  提供对应的构造拷贝函数以及operator=防止浅拷贝问题
-  提供尾插法和尾删法对数组中的数据进行增加和删除
-  可以通过下标的方式访问数组中的元素
-  可以获取数组中当前元素个数和数组的容量



### 2 STL初识

#### 2.1 STL的诞生

- 长久以来，软件界一直希望建立一种可重复利用的东西
- C++的**面向对象和泛型编程**思想，目的就是提升复用性
- 大多情况下，数据结构和算法都未能有一套标准，导致了大量重复工作
- 为了建立数据结构和算法的一套标准诞生了**STL**



#### 2.2 STL基本概念

- standard template library，**标准模板库**
- STL从广义上分为：**容器（container）算法（algorithm）迭代器（iterator）**
- **容器**和**算法**之间通过迭代器进行无缝衔接。
- STL几乎所有的代码都采用了模板类或者模板函数



#### 2.3 STL六大组件

STL大体分为六大组件，分别是**容器、算法、迭代器、仿函数、适配器（配接器）、空间配置器**

1. 容器：各种数据结构，如vector、list、deque、set、map等，用来存放数据。
2. 算法：各种常见的算法，如sort、find、copy、for_each等
3. 迭代器：扮演了容器与算法之间的胶合剂。
4. 仿函数：行为类似函数，可作为算法的某种策略。
5. 适配器：一种用来修饰容器或者仿函数或迭代器接口的东西。
6. 空间配置器：负责空间的配置与管理。



#### 2.4 STL中容器、算法、迭代器

**容器**：置物之所也

STL容器就是将运用**最广泛的一些数据结构**实现出来

常用的数据结构：数组、链表、树、栈、队列，集合，映射表等

这些容器分为**序列式容器**和**关联式容器**：

​	**序列式容器**：强调值的排序，序列式容器中的每个元素均有固定的位置

​	**关联式容器**：二叉树结构，各元素之间没有严格的物理上的顺序关系



**算法**：问题之解法也

有限的步骤，解决逻辑或数学上的问题，这一门学科我们叫做算法（algorithm）

算法分为：**质变算法**和**非质变算法**

**质变算法**：运算过程中会更改区间内的元素的内容。例如拷贝，替换，删除等

**非质变算法**：运算过程中不会更改区间内的元素内容，例如查找，计数，遍历，寻找极值等



**迭代器**：容器和算法之粘合剂

提供一种方法，使之能够依序寻访某个容器所含的各个元素，而又无需暴露该容器的内部的表达方式。

每个容器都有自己专属的迭代器

迭代器使用非常类似于指针，初学阶段我们可以先理解迭代器为指针。



迭代器种类：

| 种类           | 功能                                                     | 支持运算                   |
| -------------- | -------------------------------------------------------- | -------------------------- |
| 输入迭代器     | 对数据的只读访问                                         | 只读，支持++、==、!=       |
| 输出迭代器     | 对数据的只写访问                                         | ++                         |
| 前向迭代器     | 读写操作，并能向前推进迭代器                             | ++、==、!=                 |
| 双向迭代器     | 读写操作，并能向前和向后操作                             | ++、- -                    |
| 随机访问迭代器 | 读写操作，可以以跳跃的方式访问任意数据，功能最强的迭代器 | ++、- -、[n]、-n、<、>、>= |

常见的容器中迭代器种类为双向迭代器和随机访问迭代器



#### 2.5 容器算法迭代器初始

STL中最常用的容器为Vector，可以理解为数组。



2.5.1 vector存放内置数据类型

容器：`vector`

算法：`for_each`

迭代器：`vector<int>::interator`

