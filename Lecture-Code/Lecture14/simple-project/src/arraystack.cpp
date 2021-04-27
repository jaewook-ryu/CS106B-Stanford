#include "arraystack.h"
#include "strlib.h"


ArrayStack::ArrayStack(){

}

ArrayStack::~ArrayStack(){
    //destructor: clean up the memory
    delete[] elements;
}

void ArrayStack::push(int n){

}

int ArrayStack::peek() const{
    return 0;

}

bool ArrayStack::isEmpty() const{
    return true;
}

std::string ArrayStack::toString() const{
    std::string s = "{";
    for(int i=0;i<size;i++){
        s += " "  + integerToString(elements[i]);
    }
    return s + "}";
}

ostream& operator <<(ostream& out, ArrayStack& stack){
    out << stack.toString();
    return out;
}
