#include "DoubleScriptedArray.h"
#include <iostream>
using namespace std;

int main(){
    DoubleScriptedArray array1(4, 5);
    cout << array1 << endl;


    DoubleScriptedArray array2 (4, 5);
    cout << array2 << endl;

    cout << (array1 == array2) << endl;

    array2(2,3) = 4;

    array1 = array2;

    cout << array2 << endl;
}