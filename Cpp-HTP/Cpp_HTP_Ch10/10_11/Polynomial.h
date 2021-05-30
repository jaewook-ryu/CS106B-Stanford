#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Polynomial{

    public:
        Polynomial(); // default constructor
        Polynomial(int deg);
        ~Polynomial(); // destructor
        Polynomial(const Polynomial& p); // copy constructor

        Polynomial operator+(const Polynomial& p);
        Polynomial operator-(const Polynomial& p);
        const Polynomial& operator=(const Polynomial& p);
        Polynomial operator*(const Polynomial& p);
        Polynomial operator+=(const Polynomial& p);
        Polynomial operator-=(const Polynomial& p);
        Polynomial operator*=(const Polynomial& p);

    private:
        int degree;
        double *ptr; // pointer to coefficient array
}
