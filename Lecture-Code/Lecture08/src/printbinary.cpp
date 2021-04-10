#include <iostream>
#include "console.h"
#include "gwindow.h" // for GWindow
#include "simpio.h"  // for getLine
#include "vector.h"  // for Vector
using namespace std;

void printAllBinaryVer01(int digit);
void printAllBinaryVer02(int digit);
void binaryDigitHelper(int digit, string output);

void printDecimal(int digit);
void printDecimalHelper(int digit, string output);

int main() {
    int digit;
    cout << "Enter number of digits: ";
    cin >> digit;

    //printAllBinaryVer02(digit);


    return 0;
}

void printDecimal(int digit){
    printDecimalHelper(digit, "");
}

void printDecimalHelper(int digit, string output){
    if(digit == 0){
        cout << output << endl;
    } else{
        for(int i=0;i<9;i++){
            printDecimalHelper(digit-1, output + integerToString(i));
        }
    }
}



void printAllBinaryVer01(int digit){
    // base case
    if(digit == 1){
        cout << 0 << endl;
        cout << 1 << endl;
    }

    // non-base cases
    else{
        cout << 0;
        printAllBinaryVer01(digit-1);

        cout << 1;
        printAllBinaryVer02(digit-1);
    }
}

void printAllBinaryVer02(int digit){
    binaryDigitHelper(digit, "");
}

// helper function
void binaryDigitHelper(int digit, string output){
    if(digit == 0){
        cout << output << endl;
    } else{
        binaryDigitHelper(digit-1, output + "0");

        binaryDigitHelper(digit-1, output + "1");
    }
}

