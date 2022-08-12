//
// Created by Xia on 2022/8/1
// https://blog.csdn.net/qq_61386381/article/details/125595705
//

#ifndef CPLUS_STACK_H
#define CPLUS_STACK_H

using namespace std;


template<class T>
class Stack {
private:
    T *_arr;
    int _top;
    int _capacity;
public:
    Stack(T capacity = 4) : _top(0), _capacity(capacity) {
        _arr = new T[capacity];
    }

    void Push(const T &x);

    ~Stack();

};

// ① Stack 是类名，Stack<int> 才是类型。这里要拿 Stack<T> 去指定类域才对。
// ②每一次声明都要有template <class T>
template<class T>
Stack<T>::~Stack() {
    delete[] _arr;
    _arr = nullptr;
    _top = _capacity = 0;
}


#endif //CPLUS_STACK_H
