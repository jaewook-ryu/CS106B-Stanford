#include "ArrayStack.h"
#include "error.h"


ArrayStack::ArrayStack(){
    elements = new int[10]();
    size = 0;
    capacity = 10;
}

void ArrayStack::push(int n){
    if(size < capacity){
        elements[size] = n;
        size++;

    } else{
        //TODO: out of space?
    }

}

int ArrayStack::peek(){
    if(size == 0){

    } else{
        return (elements[size-1]);
    }
}

int ArrayStack::pop(){
    if(size == 0){
        //error?
    } else{
        int result = elements[size-1];
        size--;
        return result;
    }
}

bool ArrayStack::isEmpty(){
    return (size == 0);
}

std::string toString(){
    std::string s "";

    for(int i=0;i<size;i++){
        s += " " + integerToString(elements[i]);
    }

    return s;
}
