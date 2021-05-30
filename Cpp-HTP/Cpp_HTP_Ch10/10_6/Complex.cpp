#include "Complex.h"

Complex::Complex(double real, double imag)
    : real{real}, imag{imag}{
        /* empty body */
}

Complex::Complex(const Complex& c){
    real = c.real;
    imag = c.imag;
}

Complex Complex::operator+(const Complex& right) const{
    return Complex{real + right.real, imag + right.imag};
}


