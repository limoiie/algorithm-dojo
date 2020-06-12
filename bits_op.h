#ifndef ALGORITHM_DOJO_BITS_OP_H
#define ALGORITHM_DOJO_BITS_OP_H

#include <iostream>

using namespace std;

// (x & y) | x ^ !y = x ^ !y

void f1() {
    uint x = 0, y = 0;
    auto r = (x & y) | (x ^ y);
    auto s = (x | y);
    cout << "x & y | x ^ y = " << r << endl;
    cout << "x | y = " << s << endl;
}

void f2() {
    uint x = 0, y = 0;
    auto r = (x & y) | (x ^ !y);
    auto s = (x ^ !y);
    cout << "x & y | x ^ !y = " << r << endl;
    cout << "x ^ !y = " << s << endl;
}

#endif //ALGORITHM_DOJO_BITS_OP_H
