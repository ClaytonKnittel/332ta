#include <iostream>
#include "ultimate.h"

using std::cout;
using std::endl;

holder::holder(size_t size): size(size) {
    s = new ref_counter[size];
}

holder::holder(const holder &h): size(h.size) {
    s = new ref_counter[size];
    for (size_t i = 0; i < size; ++i) {
        s[i] = h.s[i];
    }
}

holder::~holder() {
    delete [] s;
}


void holder::set(size_t idx, ref_counter val) {
    s[idx] = val;
}


// start of at the beginning of the list by default
holder::iterator::iterator(holder *p): parent(p), idx(0) {
}

holder::iterator::iterator(holder *p, size_t idx): parent(p), idx(idx) {
}

ref_counter holder::iterator::operator*() {
    return parent->s[idx];
}

ref_counter* holder::iterator::operator->() {
    return &parent->s[idx];
}

holder::iterator& holder::iterator::operator++() {
    idx++;
    if (idx > parent->size) {
        idx = parent->size;
    }
    return *this;
}

bool holder::iterator::operator==(const holder::iterator &i) {
    return parent == i.parent && idx == i.idx;
}

bool holder::iterator::operator!=(const holder::iterator &i) {
    return parent != i.parent || idx != i.idx;
}

holder::iterator holder::begin() {
    return holder::iterator(this);
}

holder::iterator holder::end() {
    return holder::iterator(this, size);
}

void ultimate() {
    holder h1(5);

    for (auto it = h1.begin(); it != h1.end(); ++it) {
        cout << it->get_count() << " ";
    }
    cout << endl;

    h1.set(0, ref_counter());
    h1.set(1, ref_counter());
    h1.set(2, ref_counter());
    h1.set(3, ref_counter());
    h1.set(4, ref_counter());

    for (auto it = h1.begin(); it != h1.end(); ++it) {
        cout << it->get_count() << " ";
    }
    cout << endl;
}
