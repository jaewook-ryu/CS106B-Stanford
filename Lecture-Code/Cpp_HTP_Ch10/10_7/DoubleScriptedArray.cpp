#include "DoubleScriptedArray.h"

#include <stdexcept>
#include <iostream>
#include <iomanip>
using namespace std;

DoubleScriptedArray::DoubleScriptedArray(int m, int n)
    : row{m}, col{n}, ptr{new int[m*n]}{
        /* empty body */
}

DoubleScriptedArray::DoubleScriptedArray(const DoubleScriptedArray& toCopy)
    : row{toCopy.getRowSize()}, col{toCopy.getColSize()}, ptr{new int[row*col]}{
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            (*this)(i, j) = toCopy(i, j);
        }
    }
}

DoubleScriptedArray::~DoubleScriptedArray(){
    delete[] ptr;
}

size_t DoubleScriptedArray::getRowSize() const{
    return row;
}

size_t DoubleScriptedArray::getColSize() const{
    return col;
}

const DoubleScriptedArray& DoubleScriptedArray::operator=(const DoubleScriptedArray& right){
    
}

bool DoubleScriptedArray::operator==(const DoubleScriptedArray& right) const{
    if(col != right.col || row != right.row){
        return false;
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if((*this)(i, j) != right(i, j)){
                return false;
            }
        }
    }

    return true;
}

int DoubleScriptedArray::operator()(int i, int j) const{
    if(i<row && j<col){
        return ptr[row * i + j];
    } else{
        throw out_of_range{"Array out of bounds!"};
    }
}

int& DoubleScriptedArray::operator()(int i, int j){
    if(i<row && j<col){
        return ptr[row * i + j];
    } else{
        throw out_of_range{"Array out of bounds!"};
    }
}