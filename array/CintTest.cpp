//
// Created by XZQ on 2022/10/1.
//

#include <iostream>
#include <fstream>

using namespace std;

class People {
public:
    void show() {
        cout << "������\t" << name << endl;
        cout << "���䣺\t" << age << endl;
        cout << "�Ա�\t" << sex << endl;
    }

private:
    string name = "XZQ";
    int age = 17;
    string sex = "��";
};

class Student : public People {
public:
    void show_1() {
        cout << "��ߣ�\t" << height << endl;
        cout << "�ɼ���\t" << score << endl;
    }

private:
    float height = 175;
    float score = 99.8;
};

void openFile() {
    ofstream outFile;
    outFile.open("D:\\aa.txt", ios::out);
    if (outFile.is_open()) {
        cout << "�ļ��򿪳ɹ�" << endl;
    }
    outFile.close();
}

//int main() {
//    openFile();
//    return 0;
//}