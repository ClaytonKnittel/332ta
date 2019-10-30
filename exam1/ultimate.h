#pragma once
#include <memory>
#include <set>
#include "puzzle2.h"


class holder {
    size_t size;
    // array of ref_counters
    ref_counter *s;

public:
    holder(size_t size);
    holder(const holder &);
    ~holder();

    void set(size_t idx, ref_counter val);

    class iterator {
        friend holder;

        // keep a reference to the holder object to which this
        // iterator belongs
        holder *parent;

        // indicates where in the array we currently are
        size_t idx;

        iterator(holder *);
        iterator(holder *, size_t idx);

    public:
        // dereference overload (should return reference to
        // value at location "idx")
        ref_counter operator*();
        ref_counter* operator->();

        iterator& operator++();
        bool operator==(const iterator &);
        bool operator!=(const iterator &);
    };


    iterator begin();
    iterator end();
};


void ultimate();
