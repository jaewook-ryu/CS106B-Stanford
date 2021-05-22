#include "DoubleScriptedArray.h"
#include <iostream>
using namespace std;

int main(){
    DoubleScriptedArray array1(4, 5);
    cout << array1 << endl;
    
    array1(2,3) = 10;

    cout << array1;    

}