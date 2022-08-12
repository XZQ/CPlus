//
// Created by Xia on 2022/8/3.
// https://blog.csdn.net/Skies_/article/details/109275161
// https://blog.csdn.net/tr_ainiyangyang/article/details/125977134
// https://blog.csdn.net/weixin_40878579/article/details/81462427
//

#include "CastTest.h"
#include <iostream>

using namespace std;

// static_cast  用来进行比较自然和低风险的转换，比如整型和实数型、字符型之间相互转换
void testStatic() {
    CastTest a;
    int n;
    char *p = (char *) "New GOOD";
    // 将3.14强制转换为3
    n = static_cast<int>(3.14);
    // 将a对象转化成int，调用int()，n的值变为1
    n = static_cast<int>(a);
    // p的值变成NULL
    p = static_cast<char *>(a);

    // 编译错误，static_cast不能将指针转换成整型
    // p = static_cast<int>(p);
    // 编译错误，static_cast不能将整型转换成指针
    // p = static_cast<char>(n);

    cout << "" << endl;
}


// 用来进行各种不同类型的指针之间的转换，不同类型的引用之间的转换，指针和能容纳得下指针的整数类型之间的转换
void testReinterPret() {
    CastTest a(100);
    int &r = reinterpret_cast<int &>(a);
    // r引用的内容变成200，r引用a前四个字节，即i的值
    r = 200;


    int n = 300;
    CastTest *pa = reinterpret_cast<CastTest *>(&n);
    pa->i = 400;
    pa->j = 500;
    cout << pa->i << " " << pa->j;

    long long la = 0x12345678abcdLL;
    // la太长，只取低32位0x5678abcd拷贝给pa
    pa = reinterpret_cast<CastTest *>(la);
    // pa逐个比特拷贝到u
//   unsigned int u = reinterpret_cast<unsigned int>(pa);
//    // 5678abcd
//    cout << hex << u;
    typedef void(*PF1)(int);
    typedef int(*PF2)(int, char *);
    PF1 pf1;
    PF2 pf2;
    // 两个不同类型的函数指针之间的转换
    pf2 = reinterpret_cast<PF2>(pf1);

}

// 用来去除const属性，将常引用转换成同类型的非常引用，将常指针转换成同类型的非常指针
void testConstCast() {
    const string s = "ssssss";
    // 将s转换成非常引用
    string &p = const_cast<string &>(s);

    cout << p << endl;
    // 将s转换成非常指针
    string *r = const_cast<string *>(&s);
    cout << *r << endl;
}


//专门用于将多态基类（包含虚函数的基类）的指针或引用，强制转换为派生类的指针或引用，而且能够检查类型转换的安全性
void testDynamicCast() {

    BaseCast b;
    CastTest d;
    CastTest *pd;
    // 将基类指针b转化成派生类指针pd
    pd = reinterpret_cast<CastTest *>(&b);
    // reinterpret_cast不检查安全性，不执行下列语句
    if (pd == NULL) {
        cout << "unsafe1";
    }
    // 将基类指针b转化成派生类指针pd，不安全
    pd = dynamic_cast<CastTest *>(&b);
    // unsafe2
    if (pd == NULL) {
        cout << "unsafe2";
    }
    // 将基类指针pb(指向派生类对象)转化成派生类指针pd，安全
//    BaseCast *pb = &d;
//    pd = dynamic_cast<CastTest *>(pb);
//    if (pd == NULL) {
//        cout << "unsafe2";
//    }

}


void testTryCatch() {
    try {
        char *p = new char[999999999999999];
    } catch (bad_alloc e) {
        cerr << e.what() << endl;
    }
}


//int main() {
//    testTryCatch();
//    return 0;
//}
