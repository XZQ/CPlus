//
// Created by Xia on 2022/8/3.
//

#ifndef CPLUS_CASTTEST_H
#define CPLUS_CASTTEST_H


#include "BaseCast.h"

class CastTest : BaseCast {
public:
    int i;
    int j;

    CastTest() {}

    CastTest(int n) : i(n), j(n) {}

    operator int() {
        return 1;
    }

    operator char *() {
        return nullptr;

    }
};


#endif //CPLUS_CASTTEST_H
