#include <iostream>
#include "puzzle2.h"

using std::cout;
using std::endl;

ref_counter::ref_counter() {
    count = new int(1);
}

ref_counter::ref_counter(const ref_counter &ref) {
    count = ref.count;
    (*count)++;
}

ref_counter::~ref_counter() {
    (*count)--;
    if (*count == 0) {
        delete count;
    }
}

ref_counter& ref_counter::operator=(const ref_counter &ref) {
    (*count)--;
    if (*count == 0) {
        delete count;
    }
    count = ref.count;
    (*count)++;
    return *this;
}

int ref_counter::get_count() const {
    return *count;
}


void method1(const ref_counter r) {
    cout << "method1 count: " << r.get_count() << endl;
}

void method2(const ref_counter &r) {
    cout << "method2 count: " << r.get_count() << endl;
}

void puzzle2() {
    ref_counter r;

    cout << "initial count: " << r.get_count() << endl;
    method1(r);
    method2(r);

    ref_counter r2 = r;
    cout << "copy r2 count: " << r2.get_count() << endl;

    ref_counter r3;
    r3 = r;
    cout << "copy r3 count: " << r3.get_count() << endl;

    ref_counter &r4 = r;
    cout << "reference r4 count: " << r4.get_count() << endl;
}
