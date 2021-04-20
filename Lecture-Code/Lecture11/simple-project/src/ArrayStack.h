#ifndef _ARRAYSTACK_H
#define _ARRAYSTACK_H

#include <iostream>

class ArrayStack{
public:
    ArrayStack();

    void push (int n);

    int pop();

    int peek();

    bool isEmpty();

    string toString();


private:
    int* elements;
    int size;
    int capacity;
};


#endif // ARRAYSTACK_H
