//
// Created by XZQ on 2022/11/22.
// https://blog.csdn.net/QLeelq/article/details/115747717
//

#include<iostream>
#include<memory>
#include<thread>
#include <cstring>

using namespace std;


void thread1() {
    std::cout << "���߳�1" << std::endl;
}

void thread2(int x) {
    std::cout << "���߳�2 x=" << x << std::endl;
}

// �� https://www.cnblogs.com/whlook/p/6573659.html

void createThread() {
    std::thread first(thread1);
    std::thread second(thread2, 100);
    std::cout << "���߳�\n";
    first.join(); //����˵������̵߳ķ�ʽ
    second.join();
}

struct student {
    char name[20];
    int age;
    double score;
};

void testStruct() {
    struct student s = {"XZQ", 11, 22.22};
    //��ȡ��ʽ1���ṹ�����.��Ա����
    printf("%s %d %.2f\n", s.name, s.age, s.score);

    student *stu = &s;
    //��ȡ��ʽ2���ṹ��ָ�������.��Ա������
    printf("%s %d %.2f\n", (*stu).name, (*stu).age, (*stu).score);
    //��ȡ��ʽ3���ṹ��ָ��->��Ա������
    printf("%s %d %.2f\n", stu->name, stu->age, stu->score);
}

struct Student {
    const char *name;
    int age;
} stu, *pstu = &stu;

void testStudent() {
    stu.age = 31;
    stu.name = "stu";
//    cout << stu.age << "  " << stu.name << endl;
//    cout << &(stu) << "  " << &stu << "\n" << endl;
    cout << &(pstu)->name << "  " << &pstu->name << endl;


    cout << pstu->name << "  " << pstu->age << endl;

//    strcpy(stu.name, "hello"); //ʧ�ܣ�ָ������û�з���ռ�
//    stu.name = (char *) malloc(3);
//    strcpy(stu.name, "hello");

}
// https://juejin.cn/post/6844903668026703880#heading-5
//�ṹ���С�漰һ����������⣬�������Ϊ��
//�ṹ������׵�ַΪ����Ա���ȣ������#pragma pack(n)����ȡ����Ա���Ⱥ�n�Ľ�Сֵ��Ĭ��pragma��n=8����������
//        �ṹ���СΪ����Ա���ȵ�������
//�ṹ��ÿ����Ա��Խṹ���׵�ַ��ƫ��������ÿ����Ա�����С�������pragma pack(n),����n���Ա��С�Ľ�Сֵ����������
//        ��ˣ�����ṹ��S1��S2��Ȼ����һ���������ֶ�˳��ͬ����СҲ��ͬ��sizeof(S1) = 8, ��sizeof(S2) = 12. ���������#pragma pack(2)����sizeof(S1)=8��sizeof(S2)=8

/*
https://blog.csdn.net/weixin_42133358/article/details/124765557
https://www.jb51.net/article/252953.htm
https://blog.csdn.net/qq_45139003/article/details/121444879
*/

int main() {
//    createThread();
    testStudent();
    return 0;
}