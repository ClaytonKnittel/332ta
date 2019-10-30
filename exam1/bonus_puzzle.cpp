#include <iostream>
#include "bonus_puzzle.h"

using std::cout;
using std::endl;

test::test(int &i): var(i) {
}


test* method1() {
    int i = 1;
    test *t = new test(i);
    return t;
}

void method2() {
    int j = 2;
}

void method3() {
    char x = 0;
    int k = 1;
}

// must be compiled without optimizations for the output
// to make sense
void bonus_puzzle() {
    test* t = method1();
    cout << "method1: " << t->var << endl;

    method2();
    cout << "method2: " << t->var << endl;

    // this one is extra tricky :)
    method3();
    cout << "method3: " << t->var << endl;
}
