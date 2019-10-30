#include "puzzle1.h"
#include <iostream>

using std::cout;
using std::endl;

list::list(): _size(0) {}

list::list(size_t size): _size(size) {}

list::~list() {}

bool list::isEmpty() const {
    return _size == 0;
}

size_t list::size() const {
    return _size;
}

void list::print() const {
    cout << "[";
    for (size_t i = 0; i < _size; ++i) {
        cout << (*this)[i];
        if (i != _size - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}


arraylist::arraylist(): list(), capacity(1) {
    array = new int[capacity];
}

arraylist::arraylist(const arraylist &a): list(a.size()), capacity(a.capacity) {
    array = a.array;
}

arraylist::~arraylist() {
    delete array;
}

arraylist & arraylist::operator=(const list &l) {
    _size = l.size();
    if (capacity < _size) {
        capacity = _size;
        delete array;
        array = new int[capacity];
    }
    for (size_t i = 0; i < _size; ++i) {
        array[i] = l[i];
    }
    return *this;
}

int arraylist::operator[](size_t idx) const {
    return array[idx];
}

list & arraylist::insert(int element) {
    if (capacity == _size) {
        capacity *= 2;
        int* newlist = new int[capacity];
        for (size_t i = 0; i < _size; ++i) {
            newlist[i] = array[i];
        }
        array = newlist;
    }
    array[_size++] = element;
    return *this;
}

list & arraylist::set(size_t idx, int val) {
    array[idx] = val;
    return *this;
}

void puzzle1() {
    arraylist l1;

    l1.insert(1).insert(2).insert(5);

    arraylist l2 = l1;

    cout << "List 1: ";
    l1.print();
    cout << "List 2: ";
    l2.print();
    cout << endl;

    l2.set(1, 20);
    l2.insert(7).insert(10);
    cout << "List 1: ";
    l1.print();
    cout << "List 2: ";
    l2.print();

}