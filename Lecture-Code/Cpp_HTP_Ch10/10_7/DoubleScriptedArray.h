#ifndef DOUBLESCRIPTEDARRAY_H
#define DOUBLESCRIPTEDARRAY_H

#include <iostream>

class DoubleScriptedArray{
        // stream extraction/insertion operators
        friend std::ostream& operator<<(std::ostream&, DoubleScriptedArray&);
        friend std::istream& operator>>(std::istream&, DoubleScriptedArray&);

    public:
        explicit DoubleScriptedArray(int = 10, int = 10); // explicit constructor
        DoubleScriptedArray(const DoubleScriptedArray&); // copy constructor
        ~DoubleScriptedArray();
        size_t getRowSize() const;
        size_t getColSize() const;

    private:    
        // overload operators
        const DoubleScriptedArray& operator=(const DoubleScriptedArray&); // = operator 
        bool operator==(const DoubleScriptedArray&) const; // == operator

        bool operator!=(const DoubleScriptedArray& right) const {
            return !(*this == right);
        } // != operator
        
        // subscripting operators
        int operator()(int, int) const;
        int& operator()(int, int);


        // member variables
        int row, col;
        int* ptr;
};


#endif