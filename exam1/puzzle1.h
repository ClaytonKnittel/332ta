#include <cstddef>


class list {
protected:
    size_t _size;

    list(size_t size);

public:
    list();
    virtual ~list();

    virtual int operator[](size_t idx) const = 0;

    virtual list & insert(int) = 0;
    virtual list & set(size_t idx, int val) = 0;
    bool isEmpty() const;
    size_t size() const;
    void print() const;
};

class arraylist : public list {
private:
    size_t capacity;
    int *array;

public:
    arraylist();
    arraylist(const arraylist &);
    virtual ~arraylist();

    arraylist & operator=(const list &);
    virtual int operator[](size_t idx) const;

    virtual list & insert(int);
    virtual list & set(size_t idx, int val);
};

void puzzle1();
