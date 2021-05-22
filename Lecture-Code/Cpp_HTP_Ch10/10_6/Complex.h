#ifndef COMPLEX_H
#define COMPLEX_H

#include <string>

class Complex{
    public:
        // constructor, copy constructor, destructor
        explicit Complex(double = 0.0, double = 0.0);
        Complex(const Complex&);

        // operator overloading
        Complex& operator+(const Complex&) const;
        Complex& operator-(const Complex&) const;
        bool operator==(const Complex&) const;
        bool operator!=(const Complex& right) const{
            return !((*this) == right);
        }
        Complex& conjugate(const Complex&);

        std::string toString() const;

    private:
        double real;
        double imag;
};


#endif