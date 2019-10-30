#pragma once

class ref_counter {
    int *count;

public:
    ref_counter();
    ref_counter(const ref_counter &);
    ~ref_counter();

    ref_counter& operator=(const ref_counter &);

    int get_count() const;
};

void puzzle2();