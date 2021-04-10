#include <iostream>
#include "console.h"
#include "gwindow.h" // for GWindow
#include "simpio.h"  // for getLine
#include "vector.h"  // for Vector
using namespace std;


void diceSum(int num, int target);
void diceSumHelper(int num, int target, Vector<int> &values);

int main() {
    int num;
    num = getInteger("Enter number of dies: ");

    int target;
    target = getInteger("Enter deisred sum of dies: ");

    diceSum(num, target);

    return 0;
}

void diceSum(int num, int target){
    Vector<int> values;
    diceSumHelper(num, target, values);

}

void diceSumHelper(int num, int target, Vector<int> &values){
    if(num == 0){
        if(target == 0){
            cout << values << endl;
        }
    } else{
        for(int i=1;i<6+1;i++){
            // Vector<int> tempValues = values;
            // choose i
            values.add(i);

            // recursion
            diceSumHelper(num-1, target-i, tempValues);

            // what about the "unchoose" part?
            // what does this mean?
            values.removeBack();
        }
    }
}

// Helper1 goes through "ALL" possible cases.

void diceSumHelper2(int num, int target, Vector<int> &values){
    if(num == 0){
        if(target == 0){
            cout << values << endl;
        }
    } else if (target >= num * 1 && target <= num*6){
        for(int i=1;i<6+1;i++){
            // Vector<int> tempValues = values;
            // choose i
            values.add(i);

            // recursion
            diceSumHelper(num-1, target-i, tempValues);

            // what about the "unchoose" part?
            values.removeBack();
        }
    }
}


