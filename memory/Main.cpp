//
// Created by Xia on 2022/8/12.
//  https://blog.csdn.net/chenlong_cxy/article/details/117622502
// https://blog.csdn.net/qq_61939403/article/details/124932737
// https://blog.csdn.net/weixin_49312527/article/details/123807423
// https://blog.csdn.net/allelujah123/article/details/123747672
//

#include<iostream>
#include "Main.h"


using namespace std;


//堆与栈的区别
//        管理方式不同 ：栈是由编译器自动申请和释放空间，堆是需要程序员手动申请和释放；
//空间大小不同：栈的空间是有限的，在32位平台下，VC6下默认为1M，堆最大可以到4G；
//能否产生碎片：栈和数据结构中的栈原理相同，在弹出一个元素之前，上一个已经弹出了，不会产生碎片，如果不停地调用malloc、free对造成内存碎片很多；
//生长方向不同：堆生长方向是向上的，也就是向着内存地址增加的方向，栈刚好相反，向着内存减小的方向生长。
//分配方式不同：堆都是动态分配的，没有静态分配的堆。栈有静态分配和动态分配。静态分配是编译器完成的，比如局部变量的分配。动态分配由 malloc 函数进行分配，但是栈的动态分配和堆是不同的，它的动态分配是由编译器进行释放，无需我们手工实现。
//分配效率不同：栈的效率比堆高很多。栈是机器系统提供的数据结构，计算机在底层提供栈的支持，分配专门的寄存器来存放栈的地址，压栈出栈都有相应的指令，因此比较快。堆是由库函数提供的，机制很复杂，库函数会按照一定的算法进行搜索内存，因此比较慢
//        静态变量与非静态变量
//静态全局变量、全局变量区别
//1）静态全局变量和全局变量都属于常量区
//2）静态全局区只在本文件中有效，别的文件想调用该变量，是调不了的，而全局变量在别的文件中可以调用
//3）如果别的文件中定义了一个该全局变量相同的变量名，是会出错的。
//
//静态局部变量、局部变量的区别
//1）静态局部变量是属于常量区的，而函数内部的局部变量属于栈区；
//2）静态局部变量在该函数调用结束时，不会销毁，而是随整个程序结束而结束，但是别的函数调用不了该变量，局部变量随该函数的结束而结束；
//3）如果定义这两个变量的时候没有初始值时，静态局部变量会自动定义为0，而局部变量就是一个随机值；
//4）静态局部变量在编译期间只赋值一次，以后每次函数调用时，不在赋值，调用上次的函数调用结束时的值。局部变量在调用期间，每调用一次，赋一次值。



int globalVar = 1;// 数据段(全局数据，静态数据)
static int staticGlobalVar = 1;// 数据段(全局数据，静态数据)
// 堆栈分布
void testStackHeapDistribution() {
    static int staticVar = 1;// 数据段(全局数据，静态数据)
    char char2[] = "abcd"; // 代码段
    int *prt1 = (int *) malloc(sizeof(int));// 堆(右侧)
    int *prt2 = (int *) calloc(4, sizeof(int));// 堆(右侧)
    int *prt3 = (int *) realloc(prt2, sizeof(int) * 4); // 堆(右侧)
    // 方法内部，属于栈
}

//        malloc/calloc/realloc区别
//共同点:
//都是C语言中用来进行动态内存申请的库函数，申请的空间都在堆上，用完之后必须使用free来进行释放
//        返回值类型都是void*在接受返回的地址时必须要进行强转
//        如果申请空间成功:返回的是空间的首地址，如果失败返回的是NULL
//        不同点:
//malloc：返回值类型void*
//        在接受返回的空间地址时必须要进行强转
//成功:空间首地址 失败:NULL
//参数:申请的空间所占总的字节数
//        申请的空间在堆上，使用完成后必须要使用free来进行释放
//calloc：返回值一致
//        参数列表:参数一表示元素的个数；参数二表示单个类型的字节数
//        功能:与malloc基本相同，但是calloc会对其申请的空间进行初始化
//realloc(void* p, size_t size):将p所指向空间的大小调整到size字节
//        p指向的是NULL:该函数的类似malloc
//        假设:p所指向的空间总共占old个字节
//        size <= old:将p所指向的空间缩小到size个字节---->直接返回值p所指向空间的首地址
//        size > old:将p所指向的空间扩增到size个字节
//        大一点:返回原空间的首地址
//        大的多的多:申请新空间；将旧空间中元素拷贝到新空间；释放旧空间；返回新空间的首地址


//new的原理
//1、调用operator new申请空间，
//2、调用构造自定义类型的构造函数进行初始化
//delete的原理
//1、调用operator delete释放空间
//2、调用自定义类型的析构函数进行初始化

//malloc/free和new/delete异同
//        共同点：都是从堆上申请空间，并且需要用户手动释放。
//不同的地方是：
//        malloc和free是函数，new和delete是操作符
//        malloc申请的空间不会初始化，new可以初始化
//        malloc申请空间时，需要手动计算空间大小并传递，new只需在其后跟上空间的类型即可
//        malloc的返回值为void*, 在使用时必须强转，new不需要，因为new后跟的是空间的类型
//        malloc 申请空间失败时，返回的是NULL，因此使用时必须判空，new不需要，但是new需要 捕获异常
//        申请自定义类型对象时，malloc/free只会开辟空间，不会调用构造函数与析构函数，而new在申请空间后会调用构造函数完成对象的初始化，delete在释放空间前会调用析构函数完成空间中资源的清理
void testMemory() {
    int *p = new int(2);
    int *p1 = new int[10];
    Main *p2 = new Main;
    delete p;       //销毁p
    delete[] p1;    //销毁p1
    delete p2;     //销毁p2
}

//内存泄漏
//什么是内存泄漏：内存泄漏指因为疏忽或错误造成程序未能释放已经不再使用的内存的情况。内存泄漏并不是指内存在物理上的消失，而是应用程序分配某段内存后，因为设计错误，失去了对该段内存的控制，因而造成了内存的浪费。
//内存泄漏的危害：长期运行的程序出现内存泄漏，影响很大，如操作系统、后台服务等等，出现内存泄漏会导致响应越来越慢，最终卡死