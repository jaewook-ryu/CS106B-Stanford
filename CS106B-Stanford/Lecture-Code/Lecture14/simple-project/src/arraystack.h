#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H


#include <iostream>
using namespace std;

class ArrayStack{
public:
    ArrayStack();
    ~ArrayStack(); // destructor

    void push(int n);

    int peek() const;

    bool isEmpty() const;

    string toString() const;

private:
    int* elements;
    int size;
    int capacity;

};

// making objects printable
ostream& operator <<(ostream& out, ArrayStack& stack);



#endif // ARRAYSTACK_H
