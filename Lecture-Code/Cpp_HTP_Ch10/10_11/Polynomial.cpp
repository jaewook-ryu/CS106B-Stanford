#include "Polynomial.h"

Polynomial::Polynomial(){

}

Polynomial::Polynomial(int deg){
    this->degree = deg;
}

Polynomial::~Polynomial(){
    delete degree;
    delete[] ptr;
}

Polynomial::Polynomial(const Polynomial& p){
    this->degree = p.degree;
    
    // declare new ptr array then copy values.
    this->ptr = new double[p.degree];

    for(int i=0;i<this->degree;i++){
        ptr[i] = p.ptr[i];
    }
}

Polynomial Polynomial::operator+(const Polynomial& p){
    Polynomial result;

    if(p.degree <= this->degree){
        // if degree of polynomial parameter is smaller/equal
        result.degree = this->degree;

        for(int i=0;i<this->degree;i++){
            if(i <= p.degree){
                result.ptr[i] = this->ptr[i] + p.ptr[i];
            } else{
                result.ptr[i] = this->ptr[i];
            }
        }
    } else{
        // if degree of polynomial parameter is larger
        result.degree = p.degree;

        for(int i=0;i<p.degree;i++){
            if(i <= this->degree){
                result.ptr[i] = this->ptr[i] + p.ptr[i];
            } else{
                result.ptr[i] = p.ptr[i];
            }
        }
    }

    return result;
}

const Polynomial& Polynomial::operator=(const Polynomial){
    
}